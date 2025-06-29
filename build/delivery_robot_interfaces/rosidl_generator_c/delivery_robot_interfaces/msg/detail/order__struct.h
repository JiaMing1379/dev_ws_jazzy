// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from delivery_robot_interfaces:msg/Order.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "delivery_robot_interfaces/msg/order.h"


#ifndef DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER__STRUCT_H_
#define DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'order_index'
#include "rosidl_runtime_c/string.h"
// Member 'order_time'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'steps'
#include "delivery_robot_interfaces/msg/detail/order_step__struct.h"

/// Struct defined in msg/Order in the package delivery_robot_interfaces.
typedef struct delivery_robot_interfaces__msg__Order
{
  rosidl_runtime_c__String order_index;
  builtin_interfaces__msg__Time order_time;
  delivery_robot_interfaces__msg__OrderStep__Sequence steps;
} delivery_robot_interfaces__msg__Order;

// Struct for a sequence of delivery_robot_interfaces__msg__Order.
typedef struct delivery_robot_interfaces__msg__Order__Sequence
{
  delivery_robot_interfaces__msg__Order * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} delivery_robot_interfaces__msg__Order__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER__STRUCT_H_
