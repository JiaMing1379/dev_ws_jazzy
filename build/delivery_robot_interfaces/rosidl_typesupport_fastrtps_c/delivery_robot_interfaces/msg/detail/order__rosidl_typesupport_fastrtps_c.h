// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from delivery_robot_interfaces:msg/Order.idl
// generated code does not contain a copyright notice
#ifndef DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "delivery_robot_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "delivery_robot_interfaces/msg/detail/order__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_delivery_robot_interfaces
bool cdr_serialize_delivery_robot_interfaces__msg__Order(
  const delivery_robot_interfaces__msg__Order * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_delivery_robot_interfaces
bool cdr_deserialize_delivery_robot_interfaces__msg__Order(
  eprosima::fastcdr::Cdr &,
  delivery_robot_interfaces__msg__Order * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_delivery_robot_interfaces
size_t get_serialized_size_delivery_robot_interfaces__msg__Order(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_delivery_robot_interfaces
size_t max_serialized_size_delivery_robot_interfaces__msg__Order(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_delivery_robot_interfaces
bool cdr_serialize_key_delivery_robot_interfaces__msg__Order(
  const delivery_robot_interfaces__msg__Order * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_delivery_robot_interfaces
size_t get_serialized_size_key_delivery_robot_interfaces__msg__Order(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_delivery_robot_interfaces
size_t max_serialized_size_key_delivery_robot_interfaces__msg__Order(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_delivery_robot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, delivery_robot_interfaces, msg, Order)();

#ifdef __cplusplus
}
#endif

#endif  // DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
