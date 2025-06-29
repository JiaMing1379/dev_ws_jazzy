// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from delivery_robot_interfaces:msg/Order.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "delivery_robot_interfaces/msg/order.hpp"


#ifndef DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER__TRAITS_HPP_
#define DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "delivery_robot_interfaces/msg/detail/order__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'order_time'
#include "builtin_interfaces/msg/detail/time__traits.hpp"
// Member 'steps'
#include "delivery_robot_interfaces/msg/detail/order_step__traits.hpp"

namespace delivery_robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Order & msg,
  std::ostream & out)
{
  out << "{";
  // member: order_index
  {
    out << "order_index: ";
    rosidl_generator_traits::value_to_yaml(msg.order_index, out);
    out << ", ";
  }

  // member: order_time
  {
    out << "order_time: ";
    to_flow_style_yaml(msg.order_time, out);
    out << ", ";
  }

  // member: steps
  {
    if (msg.steps.size() == 0) {
      out << "steps: []";
    } else {
      out << "steps: [";
      size_t pending_items = msg.steps.size();
      for (auto item : msg.steps) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Order & msg,
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

  // member: order_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "order_time:\n";
    to_block_style_yaml(msg.order_time, out, indentation + 2);
  }

  // member: steps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.steps.size() == 0) {
      out << "steps: []\n";
    } else {
      out << "steps:\n";
      for (auto item : msg.steps) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Order & msg, bool use_flow_style = false)
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
  const delivery_robot_interfaces::msg::Order & msg,
  std::ostream & out, size_t indentation = 0)
{
  delivery_robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use delivery_robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const delivery_robot_interfaces::msg::Order & msg)
{
  return delivery_robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<delivery_robot_interfaces::msg::Order>()
{
  return "delivery_robot_interfaces::msg::Order";
}

template<>
inline const char * name<delivery_robot_interfaces::msg::Order>()
{
  return "delivery_robot_interfaces/msg/Order";
}

template<>
struct has_fixed_size<delivery_robot_interfaces::msg::Order>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<delivery_robot_interfaces::msg::Order>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<delivery_robot_interfaces::msg::Order>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER__TRAITS_HPP_
