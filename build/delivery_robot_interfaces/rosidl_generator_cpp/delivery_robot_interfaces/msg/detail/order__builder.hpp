// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from delivery_robot_interfaces:msg/Order.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "delivery_robot_interfaces/msg/order.hpp"


#ifndef DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER__BUILDER_HPP_
#define DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "delivery_robot_interfaces/msg/detail/order__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace delivery_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_Order_steps
{
public:
  explicit Init_Order_steps(::delivery_robot_interfaces::msg::Order & msg)
  : msg_(msg)
  {}
  ::delivery_robot_interfaces::msg::Order steps(::delivery_robot_interfaces::msg::Order::_steps_type arg)
  {
    msg_.steps = std::move(arg);
    return std::move(msg_);
  }

private:
  ::delivery_robot_interfaces::msg::Order msg_;
};

class Init_Order_order_time
{
public:
  explicit Init_Order_order_time(::delivery_robot_interfaces::msg::Order & msg)
  : msg_(msg)
  {}
  Init_Order_steps order_time(::delivery_robot_interfaces::msg::Order::_order_time_type arg)
  {
    msg_.order_time = std::move(arg);
    return Init_Order_steps(msg_);
  }

private:
  ::delivery_robot_interfaces::msg::Order msg_;
};

class Init_Order_order_index
{
public:
  Init_Order_order_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Order_order_time order_index(::delivery_robot_interfaces::msg::Order::_order_index_type arg)
  {
    msg_.order_index = std::move(arg);
    return Init_Order_order_time(msg_);
  }

private:
  ::delivery_robot_interfaces::msg::Order msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::delivery_robot_interfaces::msg::Order>()
{
  return delivery_robot_interfaces::msg::builder::Init_Order_order_index();
}

}  // namespace delivery_robot_interfaces

#endif  // DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER__BUILDER_HPP_
