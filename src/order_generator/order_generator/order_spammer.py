#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from delivery_robot_interfaces.msg import OrderStep, Order
from rclpy.duration import Duration
from geometry_msgs.msg import Point

class OrderPublisher(Node):
    def __init__(self):
        super().__init__('first_node')
        self.publisher_ = self.create_publisher(Order, '/new_order', 10)
        timer_period = 2.0  # seconds
        self.timer = self.create_timer(timer_period, self.publish_order)

    def timer_callback(self):
        self.get_logger().info('Hello, world!')

    def publish_order(self):
        order = Order()
        order.order_index = "1"
        order.order_time = self.get_clock().now().to_msg()

        point = Point()
        point.x = 1.0
        point.y = 2.0
        point.z = 3.0 
        step1 = OrderStep()
        step1.order_index = "1"
        step1.position = point
        step1.earliest_arrival_time = self.get_clock().now().to_msg()
        step1.latest_arrival_time = (self.get_clock().now() + Duration(seconds=3600)).to_msg()
        step1.service_time = Duration(seconds=360).to_msg()

        step2 = OrderStep()
        step2.order_index = "1"
        step2.position = point
        step2.earliest_arrival_time = self.get_clock().now().to_msg()
        step2.latest_arrival_time = (self.get_clock().now() + Duration(seconds=3600)).to_msg()
        step2.service_time = Duration(seconds=360).to_msg()

        order.steps.append(step1)
        order.steps.append(step2)

        self.publisher_.publish(order)
        # self.get_logger().info(f'Published Order: {order}')

def main(args=None):
    rclpy.init(args=args)
    node = OrderPublisher()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
    