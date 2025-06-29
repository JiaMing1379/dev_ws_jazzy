// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from delivery_robot_interfaces:msg/OrderStep.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "delivery_robot_interfaces/msg/order_step.hpp"


#ifndef DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER_STEP__TRAITS_HPP_
#define DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER_STEP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "delivery_robot_interfaces/msg/detail/order_step__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'earliest_arrival_time'
// Member 'latest_arrival_time'
#include "builtin_interfaces/msg/detail/time__traits.hpp"
// Member 'service_time'
#include "builtin_interfaces/msg/detail/duration__traits.hpp"

namespace delivery_robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const OrderStep & msg,
  std::ostream & out)
{
  out << "{";
  // member: order_index
  {
    out << "order_index: ";
    rosidl_generator_traits::value_to_yaml(msg.order_index, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: earliest_arrival_time
  {
    out << "earliest_arrival_time: ";
    to_flow_style_yaml(msg.earliest_arrival_time, out);
    out << ", ";
  }

  // member: latest_arrival_time
  {
    out << "latest_arrival_time: ";
    to_flow_style_yaml(msg.latest_arrival_time, out);
    out << ", ";
  }

  // member: service_time
  {
    out << "service_time: ";
    to_flow_style_yaml(msg.service_time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OrderStep & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: order_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "order_index: ";
    rosidl_generator_traits::value_to_yaml(msg.order_index, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: earliest_arrival_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "earliest_arrival_time:\n";
    to_block_style_yaml(msg.earliest_arrival_time, out, indentation + 2);
  }

  // member: latest_arrival_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "latest_arrival_time:\n";
    to_block_style_yaml(msg.latest_arrival_time, out, indentation + 2);
  }

  // member: service_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "service_time:\n";
    to_block_style_yaml(msg.service_time, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OrderStep & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace delivery_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use delivery_robot_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const delivery_robot_interfaces::msg::OrderStep & msg,
  std::ostream & out, size_t indentation = 0)
{
  delivery_robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use delivery_robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const delivery_robot_interfaces::msg::OrderStep & msg)
{
  return delivery_robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<delivery_robot_interfaces::msg::OrderStep>()
{
  return "delivery_robot_interfaces::msg::OrderStep";
}

template<>
inline const char * name<delivery_robot_interfaces::msg::OrderStep>()
{
  return "delivery_robot_interfaces/msg/OrderStep";
}

template<>
struct has_fixed_size<delivery_robot_interfaces::msg::OrderStep>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<delivery_robot_interfaces::msg::OrderStep>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<delivery_robot_interfaces::msg::OrderStep>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER_STEP__TRAITS_HPP_
