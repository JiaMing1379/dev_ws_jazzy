// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from delivery_robot_interfaces:msg/OrderStep.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "delivery_robot_interfaces/msg/order_step.hpp"


#ifndef DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER_STEP__BUILDER_HPP_
#define DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER_STEP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "delivery_robot_interfaces/msg/detail/order_step__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace delivery_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_OrderStep_service_time
{
public:
  explicit Init_OrderStep_service_time(::delivery_robot_interfaces::msg::OrderStep & msg)
  : msg_(msg)
  {}
  ::delivery_robot_interfaces::msg::OrderStep service_time(::delivery_robot_interfaces::msg::OrderStep::_service_time_type arg)
  {
    msg_.service_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::delivery_robot_interfaces::msg::OrderStep msg_;
};

class Init_OrderStep_latest_arrival_time
{
public:
  explicit Init_OrderStep_latest_arrival_time(::delivery_robot_interfaces::msg::OrderStep & msg)
  : msg_(msg)
  {}
  Init_OrderStep_service_time latest_arrival_time(::delivery_robot_interfaces::msg::OrderStep::_latest_arrival_time_type arg)
  {
    msg_.latest_arrival_time = std::move(arg);
    return Init_OrderStep_service_time(msg_);
  }

private:
  ::delivery_robot_interfaces::msg::OrderStep msg_;
};

class Init_OrderStep_earliest_arrival_time
{
public:
  explicit Init_OrderStep_earliest_arrival_time(::delivery_robot_interfaces::msg::OrderStep & msg)
  : msg_(msg)
  {}
  Init_OrderStep_latest_arrival_time earliest_arrival_time(::delivery_robot_interfaces::msg::OrderStep::_earliest_arrival_time_type arg)
  {
    msg_.earliest_arrival_time = std::move(arg);
    return Init_OrderStep_latest_arrival_time(msg_);
  }

private:
  ::delivery_robot_interfaces::msg::OrderStep msg_;
};

class Init_OrderStep_position
{
public:
  explicit Init_OrderStep_position(::delivery_robot_interfaces::msg::OrderStep & msg)
  : msg_(msg)
  {}
  Init_OrderStep_earliest_arrival_time position(::delivery_robot_interfaces::msg::OrderStep::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_OrderStep_earliest_arrival_time(msg_);
  }

private:
  ::delivery_robot_interfaces::msg::OrderStep msg_;
};

class Init_OrderStep_order_index
{
public:
  Init_OrderStep_order_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OrderStep_position order_index(::delivery_robot_interfaces::msg::OrderStep::_order_index_type arg)
  {
    msg_.order_index = std::move(arg);
    return Init_OrderStep_position(msg_);
  }

private:
  ::delivery_robot_interfaces::msg::OrderStep msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::delivery_robot_interfaces::msg::OrderStep>()
{
  return delivery_robot_interfaces::msg::builder::Init_OrderStep_order_index();
}

}  // namespace delivery_robot_interfaces

#endif  // DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER_STEP__BUILDER_HPP_
