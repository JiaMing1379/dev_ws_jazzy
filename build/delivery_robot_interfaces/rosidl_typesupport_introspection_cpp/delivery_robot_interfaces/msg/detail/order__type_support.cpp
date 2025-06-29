// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from delivery_robot_interfaces:msg/Order.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "delivery_robot_interfaces/msg/detail/order__functions.h"
#include "delivery_robot_interfaces/msg/detail/order__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace delivery_robot_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Order_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) delivery_robot_interfaces::msg::Order(_init);
}

void Order_fini_function(void * message_memory)
{
  auto typed_message = static_cast<delivery_robot_interfaces::msg::Order *>(message_memory);
  typed_message->~Order();
}

size_t size_function__Order__steps(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<delivery_robot_interfaces::msg::OrderStep> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Order__steps(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<delivery_robot_interfaces::msg::OrderStep> *>(untyped_member);
  return &member[index];
}

void * get_function__Order__steps(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<delivery_robot_interfaces::msg::OrderStep> *>(untyped_member);
  return &member[index];
}

void fetch_function__Order__steps(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const delivery_robot_interfaces::msg::OrderStep *>(
    get_const_function__Order__steps(untyped_member, index));
  auto & value = *reinterpret_cast<delivery_robot_interfaces::msg::OrderStep *>(untyped_value);
  value = item;
}

void assign_function__Order__steps(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<delivery_robot_interfaces::msg::OrderStep *>(
    get_function__Order__steps(untyped_member, index));
  const auto & value = *reinterpret_cast<const delivery_robot_interfaces::msg::OrderStep *>(untyped_value);
  item = value;
}

void resize_function__Order__steps(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<delivery_robot_interfaces::msg::OrderStep> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Order_message_member_array[3] = {
  {
    "order_index",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(delivery_robot_interfaces::msg::Order, order_index),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "order_time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(delivery_robot_interfaces::msg::Order, order_time),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "steps",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<delivery_robot_interfaces::msg::OrderStep>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(delivery_robot_interfaces::msg::Order, steps),  // bytes offset in struct
    nullptr,  // default value
    size_function__Order__steps,  // size() function pointer
    get_const_function__Order__steps,  // get_const(index) function pointer
    get_function__Order__steps,  // get(index) function pointer
    fetch_function__Order__steps,  // fetch(index, &value) function pointer
    assign_function__Order__steps,  // assign(index, value) function pointer
    resize_function__Order__steps  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Order_message_members = {
  "delivery_robot_interfaces::msg",  // message namespace
  "Order",  // message name
  3,  // number of fields
  sizeof(delivery_robot_interfaces::msg::Order),
  false,  // has_any_key_member_
  Order_message_member_array,  // message members
  Order_init_function,  // function to initialize message memory (memory has to be allocated)
  Order_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Order_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Order_message_members,
  get_message_typesupport_handle_function,
  &delivery_robot_interfaces__msg__Order__get_type_hash,
  &delivery_robot_interfaces__msg__Order__get_type_description,
  &delivery_robot_interfaces__msg__Order__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace delivery_robot_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<delivery_robot_interfaces::msg::Order>()
{
  return &::delivery_robot_interfaces::msg::rosidl_typesupport_introspection_cpp::Order_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, delivery_robot_interfaces, msg, Order)() {
  return &::delivery_robot_interfaces::msg::rosidl_typesupport_introspection_cpp::Order_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
