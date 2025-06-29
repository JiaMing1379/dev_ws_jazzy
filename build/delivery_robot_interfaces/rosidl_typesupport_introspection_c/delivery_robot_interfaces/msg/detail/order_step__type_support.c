// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from delivery_robot_interfaces:msg/OrderStep.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "delivery_robot_interfaces/msg/detail/order_step__rosidl_typesupport_introspection_c.h"
#include "delivery_robot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "delivery_robot_interfaces/msg/detail/order_step__functions.h"
#include "delivery_robot_interfaces/msg/detail/order_step__struct.h"


// Include directives for member types
// Member `order_index`
#include "rosidl_runtime_c/string_functions.h"
// Member `position`
#include "geometry_msgs/msg/point.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `earliest_arrival_time`
// Member `latest_arrival_time`
#include "builtin_interfaces/msg/time.h"
// Member `earliest_arrival_time`
// Member `latest_arrival_time`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"
// Member `service_time`
#include "builtin_interfaces/msg/duration.h"
// Member `service_time`
#include "builtin_interfaces/msg/detail/duration__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void delivery_robot_interfaces__msg__OrderStep__rosidl_typesupport_introspection_c__OrderStep_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  delivery_robot_interfaces__msg__OrderStep__init(message_memory);
}

void delivery_robot_interfaces__msg__OrderStep__rosidl_typesupport_introspection_c__OrderStep_fini_function(void * message_memory)
{
  delivery_robot_interfaces__msg__OrderStep__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember delivery_robot_interfaces__msg__OrderStep__rosidl_typesupport_introspection_c__OrderStep_message_member_array[5] = {
  {
    "order_index",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(delivery_robot_interfaces__msg__OrderStep, order_index),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(delivery_robot_interfaces__msg__OrderStep, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "earliest_arrival_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(delivery_robot_interfaces__msg__OrderStep, earliest_arrival_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "latest_arrival_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(delivery_robot_interfaces__msg__OrderStep, latest_arrival_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "service_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(delivery_robot_interfaces__msg__OrderStep, service_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers delivery_robot_interfaces__msg__OrderStep__rosidl_typesupport_introspection_c__OrderStep_message_members = {
  "delivery_robot_interfaces__msg",  // message namespace
  "OrderStep",  // message name
  5,  // number of fields
  sizeof(delivery_robot_interfaces__msg__OrderStep),
  false,  // has_any_key_member_
  delivery_robot_interfaces__msg__OrderStep__rosidl_typesupport_introspection_c__OrderStep_message_member_array,  // message members
  delivery_robot_interfaces__msg__OrderStep__rosidl_typesupport_introspection_c__OrderStep_init_function,  // function to initialize message memory (memory has to be allocated)
  delivery_robot_interfaces__msg__OrderStep__rosidl_typesupport_introspection_c__OrderStep_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t delivery_robot_interfaces__msg__OrderStep__rosidl_typesupport_introspection_c__OrderStep_message_type_support_handle = {
  0,
  &delivery_robot_interfaces__msg__OrderStep__rosidl_typesupport_introspection_c__OrderStep_message_members,
  get_message_typesupport_handle_function,
  &delivery_robot_interfaces__msg__OrderStep__get_type_hash,
  &delivery_robot_interfaces__msg__OrderStep__get_type_description,
  &delivery_robot_interfaces__msg__OrderStep__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_delivery_robot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, delivery_robot_interfaces, msg, OrderStep)() {
  delivery_robot_interfaces__msg__OrderStep__rosidl_typesupport_introspection_c__OrderStep_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  delivery_robot_interfaces__msg__OrderStep__rosidl_typesupport_introspection_c__OrderStep_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  delivery_robot_interfaces__msg__OrderStep__rosidl_typesupport_introspection_c__OrderStep_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  delivery_robot_interfaces__msg__OrderStep__rosidl_typesupport_introspection_c__OrderStep_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Duration)();
  if (!delivery_robot_interfaces__msg__OrderStep__rosidl_typesupport_introspection_c__OrderStep_message_type_support_handle.typesupport_identifier) {
    delivery_robot_interfaces__msg__OrderStep__rosidl_typesupport_introspection_c__OrderStep_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &delivery_robot_interfaces__msg__OrderStep__rosidl_typesupport_introspection_c__OrderStep_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
