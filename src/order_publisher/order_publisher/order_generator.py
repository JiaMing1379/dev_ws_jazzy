#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from delivery_robot_interfaces.msg import OrderStep, Order
from rclpy.duration import Duration
from geometry_msgs.msg import Pose, Point, Quaternion

import numpy as np
from datetime import datetime
import yaml
import random
from pathlib import Path
from rclpy.time import Time

# assumptions made: no service time, time window for arrival and departure is 5 minutes (including the service time), time to go from pickup to delivery is 2 mimuntes, earliest pickup time is the order_time
# problems with current code: 
# some order is earlier than current time - solved
# pickup and delivery could be of same place - solved
# havent label order step whether is pickup or delivery - solved
# earliest start time, and latest arrival time are not set correctly - solved
# lack of getting a more realistic travel time between pickup and delivery, now assume all takes 2 minutes
# have not considered simulation time


class OrderGenerator(Node):
    def __init__(self):
        super().__init__('first_node')
        self.set_parameters([
            rclpy.parameter.Parameter('use_sim_time', rclpy.Parameter.Type.BOOL, False)
        ])
        # define necessary variables
        number_of_dynamic_orders = 20
        degree_of_dynamisms = 0.5
        robot_working_hours = 1
        average_waiting_time = 5
        standard_deviation = robot_working_hours*degree_of_dynamisms*0.4
        float_hours = np.random.normal(loc=0.0, scale=standard_deviation, size=number_of_dynamic_orders)
        mean = degree_of_dynamisms * robot_working_hours
        float_hours = float_hours - np.mean(float_hours) + mean
        for i, value in enumerate(float_hours):
            self.get_logger().info(f"float_hours[{i}] = {value:.4f}")
        start_time = self.get_clock().now()
        order_times = []
        sorted_float_hours = sorted(float_hours)
        for fh in sorted_float_hours:
            order_time = start_time + Duration(seconds=fh * 3600)  # Convert hours to seconds
            order_times.append(order_time)
        for i, t in enumerate(order_times):
            # Convert ROS Time to Python datetime for readable output
            dt = datetime.fromtimestamp(t.seconds_nanoseconds()[0] + t.seconds_nanoseconds()[1] * 1e-9)
            self.get_logger().info(f"Order {i}: scheduled at {dt.strftime('%H:%M:%S')}")
        # create a list of tuple with pose corresponding to the name
        script_dir = Path(__file__).parent
        yaml_path = script_dir / 'goals.yaml'
        with open(yaml_path, 'r') as file:
           raw_goals = yaml.safe_load(file)
        pose_name_list =  []
        for goal in raw_goals:
            position = Point(**goal['position'])
            orientation = Quaternion(**goal['orientation'])
            pose = Pose(position=position, orientation=orientation)
            pose_name_list.append((pose, goal['name']))
        orders = []
        # generate a waiting time with standard deviation of 20% of the average waiting time
        waiting_time = np.random.normal(loc=0.0, scale=average_waiting_time*2*0.2, size=number_of_dynamic_orders)
        
        # loop from 0 till number_of_dynamic_orders, create object and assign the index, order_time, and create order steps
        for n in range(number_of_dynamic_orders):
            order = Order()
            order.order_index = str(n)
            order.order_time = order_times[n].to_msg() 
            order.steps = self.create_order_steps(n, pose_name_list, order_times[n], waiting_time[n])
            orders.append(order)

        # Set up publisher, publish to '/new_order' topic
        self.order_pub = self.create_publisher(Order, '/new_order', 10)
        # List of pending orders to be published
        self.pending_orders = list(zip(orders, order_times))
        # Create timer to check every second whether order_time has passed
        self.timer = self.create_timer(1.0, self.check_time_and_publish)

    def create_order_steps(self, order_index, pose_name_list, order_time, waiting_time):
        steps = []
        # randomly select two poses for pickup and delivery
        selected_poses = random.sample(pose_name_list, k=2)
        # assign the pose and its name to two order steps, as well as order_index, assume first is pickup, and second is delivery, and their service time. 
        # only assign earliest and latest arrival time for pickup, the second for loop will assign the earliest and latest arrival time for delivery
        for i, (pose, name) in enumerate(selected_poses):
            step = OrderStep()
            step.order_index = str(order_index)
            step.location_name = name
            step.task_type = "pickup" if i == 0 else "delivery"
            step.target_pose = pose
            if step.task_type == "pickup":
                # For pickup, set earliest arrival time to order_time
                step.earliest_arrival_time = order_time.to_msg()
                step.latest_arrival_time = (order_time + Duration(seconds=300)).to_msg() #assume latest arrival time is 5 minutes later than the earliest arrival time
            step.service_time = Duration(seconds=0).to_msg()  # Assuming no service time for simplicity
            steps.append(step)
        for step in steps: # loop through the created steps, get earliest and latest pickup time, and combine with waiting time, and travel time from pickup to delivery to calculate earliest and latest arrival time for delivery
            if step.task_type == "pickup":
                earliest_pickup_time = step.earliest_arrival_time
                latest_pickup_time = step.latest_arrival_time
            else:
                earliest = Time.from_msg(earliest_pickup_time)
                latest = Time.from_msg(latest_pickup_time)
                # Calculate midpoint
                midpoint = Time(seconds=int((earliest.nanoseconds + latest.nanoseconds) / 2 * 1e-9))
                # Add waiting time + 2 min (assume time between pickup and delivery is 2 minutes)
                buffer = Duration(seconds=(waiting_time * 60 + 2 * 60))
                final_time = midpoint + buffer
                step.earliest_arrival_time = final_time.to_msg()
                step.latest_arrival_time = (final_time + Duration(seconds=300)).to_msg()
        return steps
    
    def check_time_and_publish(self): #check current time, check through the pending orders, and publish the ones that are due, and remove them from the pending orders
        now = self.get_clock().now()
        to_publish = []
        for order, scheduled_time in self.pending_orders:
            if now >= scheduled_time:
                self.order_pub.publish(order)
                to_publish.append((order, scheduled_time))
        # Remove already-published orders
        self.pending_orders = [pair for pair in self.pending_orders if pair not in to_publish]

def main(args=None):
    rclpy.init(args=args)
    node = OrderGenerator()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
