// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from delivery_robot_interfaces:msg/OrderStep.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "delivery_robot_interfaces/msg/order_step.h"


#ifndef DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER_STEP__STRUCT_H_
#define DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER_STEP__STRUCT_H_

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
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'earliest_arrival_time'
// Member 'latest_arrival_time'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'service_time'
#include "builtin_interfaces/msg/detail/duration__struct.h"

/// Struct defined in msg/OrderStep in the package delivery_robot_interfaces.
typedef struct delivery_robot_interfaces__msg__OrderStep
{
  rosidl_runtime_c__String order_index;
  geometry_msgs__msg__Point position;
  builtin_interfaces__msg__Time earliest_arrival_time;
  builtin_interfaces__msg__Time latest_arrival_time;
  builtin_interfaces__msg__Duration service_time;
} delivery_robot_interfaces__msg__OrderStep;

// Struct for a sequence of delivery_robot_interfaces__msg__OrderStep.
typedef struct delivery_robot_interfaces__msg__OrderStep__Sequence
{
  delivery_robot_interfaces__msg__OrderStep * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} delivery_robot_interfaces__msg__OrderStep__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER_STEP__STRUCT_H_
