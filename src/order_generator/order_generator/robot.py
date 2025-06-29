#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from delivery_robot_interfaces.msg import Order
from datetime import datetime
from rclpy.time import Time

class Robot(Node):
    def __init__(self):
        super().__init__('robot')
        self.pose_subscriber = self.create_subscription(Order, "/new_order",  self.order_callback, 10)

    def order_callback(self, msg: Order):
        self.get_logger().info(f"Received Order: {msg.order_index}")
        for step in msg.steps:
            # Convert times
            earliest = Time.from_msg(step.earliest_arrival_time).to_msg()
            latest = Time.from_msg(step.latest_arrival_time).to_msg()

            earliest_dt = datetime.fromtimestamp(step.earliest_arrival_time.sec + step.earliest_arrival_time.nanosec * 1e-9)
            latest_dt = datetime.fromtimestamp(step.latest_arrival_time.sec + step.latest_arrival_time.nanosec * 1e-9)
            service_duration = step.service_time.sec + step.service_time.nanosec * 1e-9

            # Log
            self.get_logger().info(f"Step Position: {step.position.x}, {step.position.y}, {step.position.z}")
            self.get_logger().info(f"Earliest Arrival Time: {earliest_dt.strftime('%Y-%m-%d %H:%M:%S')}")
            self.get_logger().info(f"Latest Arrival Time: {latest_dt.strftime('%Y-%m-%d %H:%M:%S')}")
            self.get_logger().info(f"Service Time: {service_duration:.1f} seconds")

def main(args=None):
    rclpy.init(args=args)
    node = Robot()
    rclpy.spin(node)
    rclpy.shutdown()
