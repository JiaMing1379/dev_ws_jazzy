// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from delivery_robot_interfaces:msg/Order.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "delivery_robot_interfaces/msg/detail/order__rosidl_typesupport_introspection_c.h"
#include "delivery_robot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "delivery_robot_interfaces/msg/detail/order__functions.h"
#include "delivery_robot_interfaces/msg/detail/order__struct.h"


// Include directives for member types
// Member `order_index`
#include "rosidl_runtime_c/string_functions.h"
// Member `order_time`
#include "builtin_interfaces/msg/time.h"
// Member `order_time`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"
// Member `steps`
#include "delivery_robot_interfaces/msg/order_step.h"
// Member `steps`
#include "delivery_robot_interfaces/msg/detail/order_step__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__Order_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  delivery_robot_interfaces__msg__Order__init(message_memory);
}

void delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__Order_fini_function(void * message_memory)
{
  delivery_robot_interfaces__msg__Order__fini(message_memory);
}

size_t delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__size_function__Order__steps(
  const void * untyped_member)
{
  const delivery_robot_interfaces__msg__OrderStep__Sequence * member =
    (const delivery_robot_interfaces__msg__OrderStep__Sequence *)(untyped_member);
  return member->size;
}

const void * delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__get_const_function__Order__steps(
  const void * untyped_member, size_t index)
{
  const delivery_robot_interfaces__msg__OrderStep__Sequence * member =
    (const delivery_robot_interfaces__msg__OrderStep__Sequence *)(untyped_member);
  return &member->data[index];
}

void * delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__get_function__Order__steps(
  void * untyped_member, size_t index)
{
  delivery_robot_interfaces__msg__OrderStep__Sequence * member =
    (delivery_robot_interfaces__msg__OrderStep__Sequence *)(untyped_member);
  return &member->data[index];
}

void delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__fetch_function__Order__steps(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const delivery_robot_interfaces__msg__OrderStep * item =
    ((const delivery_robot_interfaces__msg__OrderStep *)
    delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__get_const_function__Order__steps(untyped_member, index));
  delivery_robot_interfaces__msg__OrderStep * value =
    (delivery_robot_interfaces__msg__OrderStep *)(untyped_value);
  *value = *item;
}

void delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__assign_function__Order__steps(
  void * untyped_member, size_t index, const void * untyped_value)
{
  delivery_robot_interfaces__msg__OrderStep * item =
    ((delivery_robot_interfaces__msg__OrderStep *)
    delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__get_function__Order__steps(untyped_member, index));
  const delivery_robot_interfaces__msg__OrderStep * value =
    (const delivery_robot_interfaces__msg__OrderStep *)(untyped_value);
  *item = *value;
}

bool delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__resize_function__Order__steps(
  void * untyped_member, size_t size)
{
  delivery_robot_interfaces__msg__OrderStep__Sequence * member =
    (delivery_robot_interfaces__msg__OrderStep__Sequence *)(untyped_member);
  delivery_robot_interfaces__msg__OrderStep__Sequence__fini(member);
  return delivery_robot_interfaces__msg__OrderStep__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__Order_message_member_array[3] = {
  {
    "order_index",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(delivery_robot_interfaces__msg__Order, order_index),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "order_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(delivery_robot_interfaces__msg__Order, order_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "steps",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(delivery_robot_interfaces__msg__Order, steps),  // bytes offset in struct
    NULL,  // default value
    delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__size_function__Order__steps,  // size() function pointer
    delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__get_const_function__Order__steps,  // get_const(index) function pointer
    delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__get_function__Order__steps,  // get(index) function pointer
    delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__fetch_function__Order__steps,  // fetch(index, &value) function pointer
    delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__assign_function__Order__steps,  // assign(index, value) function pointer
    delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__resize_function__Order__steps  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__Order_message_members = {
  "delivery_robot_interfaces__msg",  // message namespace
  "Order",  // message name
  3,  // number of fields
  sizeof(delivery_robot_interfaces__msg__Order),
  false,  // has_any_key_member_
  delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__Order_message_member_array,  // message members
  delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__Order_init_function,  // function to initialize message memory (memory has to be allocated)
  delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__Order_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__Order_message_type_support_handle = {
  0,
  &delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__Order_message_members,
  get_message_typesupport_handle_function,
  &delivery_robot_interfaces__msg__Order__get_type_hash,
  &delivery_robot_interfaces__msg__Order__get_type_description,
  &delivery_robot_interfaces__msg__Order__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_delivery_robot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, delivery_robot_interfaces, msg, Order)() {
  delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__Order_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__Order_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, delivery_robot_interfaces, msg, OrderStep)();
  if (!delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__Order_message_type_support_handle.typesupport_identifier) {
    delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__Order_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &delivery_robot_interfaces__msg__Order__rosidl_typesupport_introspection_c__Order_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
