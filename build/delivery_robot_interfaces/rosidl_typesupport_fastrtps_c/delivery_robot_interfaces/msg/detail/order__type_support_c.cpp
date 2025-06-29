// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from delivery_robot_interfaces:msg/Order.idl
// generated code does not contain a copyright notice
#include "delivery_robot_interfaces/msg/detail/order__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "delivery_robot_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "delivery_robot_interfaces/msg/detail/order__struct.h"
#include "delivery_robot_interfaces/msg/detail/order__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "builtin_interfaces/msg/detail/time__functions.h"  // order_time
#include "delivery_robot_interfaces/msg/detail/order_step__functions.h"  // steps
#include "rosidl_runtime_c/string.h"  // order_index
#include "rosidl_runtime_c/string_functions.h"  // order_index

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_delivery_robot_interfaces
bool cdr_serialize_builtin_interfaces__msg__Time(
  const builtin_interfaces__msg__Time * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_delivery_robot_interfaces
bool cdr_deserialize_builtin_interfaces__msg__Time(
  eprosima::fastcdr::Cdr & cdr,
  builtin_interfaces__msg__Time * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_delivery_robot_interfaces
size_t get_serialized_size_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_delivery_robot_interfaces
size_t max_serialized_size_builtin_interfaces__msg__Time(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_delivery_robot_interfaces
bool cdr_serialize_key_builtin_interfaces__msg__Time(
  const builtin_interfaces__msg__Time * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_delivery_robot_interfaces
size_t get_serialized_size_key_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_delivery_robot_interfaces
size_t max_serialized_size_key_builtin_interfaces__msg__Time(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_delivery_robot_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time)();

bool cdr_serialize_delivery_robot_interfaces__msg__OrderStep(
  const delivery_robot_interfaces__msg__OrderStep * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_delivery_robot_interfaces__msg__OrderStep(
  eprosima::fastcdr::Cdr & cdr,
  delivery_robot_interfaces__msg__OrderStep * ros_message);

size_t get_serialized_size_delivery_robot_interfaces__msg__OrderStep(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_delivery_robot_interfaces__msg__OrderStep(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_delivery_robot_interfaces__msg__OrderStep(
  const delivery_robot_interfaces__msg__OrderStep * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_delivery_robot_interfaces__msg__OrderStep(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_delivery_robot_interfaces__msg__OrderStep(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, delivery_robot_interfaces, msg, OrderStep)();


using _Order__ros_msg_type = delivery_robot_interfaces__msg__Order;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_delivery_robot_interfaces
bool cdr_serialize_delivery_robot_interfaces__msg__Order(
  const delivery_robot_interfaces__msg__Order * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: order_index
  {
    const rosidl_runtime_c__String * str = &ros_message->order_index;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: order_time
  {
    cdr_serialize_builtin_interfaces__msg__Time(
      &ros_message->order_time, cdr);
  }

  // Field name: steps
  {
    size_t size = ros_message->steps.size;
    auto array_ptr = ros_message->steps.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_delivery_robot_interfaces__msg__OrderStep(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_delivery_robot_interfaces
bool cdr_deserialize_delivery_robot_interfaces__msg__Order(
  eprosima::fastcdr::Cdr & cdr,
  delivery_robot_interfaces__msg__Order * ros_message)
{
  // Field name: order_index
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->order_index.data) {
      rosidl_runtime_c__String__init(&ros_message->order_index);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->order_index,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'order_index'\n");
      return false;
    }
  }

  // Field name: order_time
  {
    cdr_deserialize_builtin_interfaces__msg__Time(cdr, &ros_message->order_time);
  }

  // Field name: steps
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->steps.data) {
      delivery_robot_interfaces__msg__OrderStep__Sequence__fini(&ros_message->steps);
    }
    if (!delivery_robot_interfaces__msg__OrderStep__Sequence__init(&ros_message->steps, size)) {
      fprintf(stderr, "failed to create array for field 'steps'");
      return false;
    }
    auto array_ptr = ros_message->steps.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_delivery_robot_interfaces__msg__OrderStep(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_delivery_robot_interfaces
size_t get_serialized_size_delivery_robot_interfaces__msg__Order(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Order__ros_msg_type * ros_message = static_cast<const _Order__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: order_index
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->order_index.size + 1);

  // Field name: order_time
  current_alignment += get_serialized_size_builtin_interfaces__msg__Time(
    &(ros_message->order_time), current_alignment);

  // Field name: steps
  {
    size_t array_size = ros_message->steps.size;
    auto array_ptr = ros_message->steps.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_delivery_robot_interfaces__msg__OrderStep(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_delivery_robot_interfaces
size_t max_serialized_size_delivery_robot_interfaces__msg__Order(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: order_index
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: order_time
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_builtin_interfaces__msg__Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: steps
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_delivery_robot_interfaces__msg__OrderStep(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = delivery_robot_interfaces__msg__Order;
    is_plain =
      (
      offsetof(DataType, steps) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_delivery_robot_interfaces
bool cdr_serialize_key_delivery_robot_interfaces__msg__Order(
  const delivery_robot_interfaces__msg__Order * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: order_index
  {
    const rosidl_runtime_c__String * str = &ros_message->order_index;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: order_time
  {
    cdr_serialize_key_builtin_interfaces__msg__Time(
      &ros_message->order_time, cdr);
  }

  // Field name: steps
  {
    size_t size = ros_message->steps.size;
    auto array_ptr = ros_message->steps.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_delivery_robot_interfaces__msg__OrderStep(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_delivery_robot_interfaces
size_t get_serialized_size_key_delivery_robot_interfaces__msg__Order(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Order__ros_msg_type * ros_message = static_cast<const _Order__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: order_index
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->order_index.size + 1);

  // Field name: order_time
  current_alignment += get_serialized_size_key_builtin_interfaces__msg__Time(
    &(ros_message->order_time), current_alignment);

  // Field name: steps
  {
    size_t array_size = ros_message->steps.size;
    auto array_ptr = ros_message->steps.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_delivery_robot_interfaces__msg__OrderStep(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_delivery_robot_interfaces
size_t max_serialized_size_key_delivery_robot_interfaces__msg__Order(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: order_index
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: order_time
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_builtin_interfaces__msg__Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: steps
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_delivery_robot_interfaces__msg__OrderStep(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = delivery_robot_interfaces__msg__Order;
    is_plain =
      (
      offsetof(DataType, steps) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _Order__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const delivery_robot_interfaces__msg__Order * ros_message = static_cast<const delivery_robot_interfaces__msg__Order *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_delivery_robot_interfaces__msg__Order(ros_message, cdr);
}

static bool _Order__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  delivery_robot_interfaces__msg__Order * ros_message = static_cast<delivery_robot_interfaces__msg__Order *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_delivery_robot_interfaces__msg__Order(cdr, ros_message);
}

static uint32_t _Order__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_delivery_robot_interfaces__msg__Order(
      untyped_ros_message, 0));
}

static size_t _Order__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_delivery_robot_interfaces__msg__Order(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Order = {
  "delivery_robot_interfaces::msg",
  "Order",
  _Order__cdr_serialize,
  _Order__cdr_deserialize,
  _Order__get_serialized_size,
  _Order__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Order__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Order,
  get_message_typesupport_handle_function,
  &delivery_robot_interfaces__msg__Order__get_type_hash,
  &delivery_robot_interfaces__msg__Order__get_type_description,
  &delivery_robot_interfaces__msg__Order__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, delivery_robot_interfaces, msg, Order)() {
  return &_Order__type_support;
}

#if defined(__cplusplus)
}
#endif
