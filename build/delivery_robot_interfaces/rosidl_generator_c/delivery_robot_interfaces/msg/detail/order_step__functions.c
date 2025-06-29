// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from delivery_robot_interfaces:msg/OrderStep.idl
// generated code does not contain a copyright notice
#include "delivery_robot_interfaces/msg/detail/order_step__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `order_index`
#include "rosidl_runtime_c/string_functions.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `earliest_arrival_time`
// Member `latest_arrival_time`
#include "builtin_interfaces/msg/detail/time__functions.h"
// Member `service_time`
#include "builtin_interfaces/msg/detail/duration__functions.h"

bool
delivery_robot_interfaces__msg__OrderStep__init(delivery_robot_interfaces__msg__OrderStep * msg)
{
  if (!msg) {
    return false;
  }
  // order_index
  if (!rosidl_runtime_c__String__init(&msg->order_index)) {
    delivery_robot_interfaces__msg__OrderStep__fini(msg);
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    delivery_robot_interfaces__msg__OrderStep__fini(msg);
    return false;
  }
  // earliest_arrival_time
  if (!builtin_interfaces__msg__Time__init(&msg->earliest_arrival_time)) {
    delivery_robot_interfaces__msg__OrderStep__fini(msg);
    return false;
  }
  // latest_arrival_time
  if (!builtin_interfaces__msg__Time__init(&msg->latest_arrival_time)) {
    delivery_robot_interfaces__msg__OrderStep__fini(msg);
    return false;
  }
  // service_time
  if (!builtin_interfaces__msg__Duration__init(&msg->service_time)) {
    delivery_robot_interfaces__msg__OrderStep__fini(msg);
    return false;
  }
  return true;
}

void
delivery_robot_interfaces__msg__OrderStep__fini(delivery_robot_interfaces__msg__OrderStep * msg)
{
  if (!msg) {
    return;
  }
  // order_index
  rosidl_runtime_c__String__fini(&msg->order_index);
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // earliest_arrival_time
  builtin_interfaces__msg__Time__fini(&msg->earliest_arrival_time);
  // latest_arrival_time
  builtin_interfaces__msg__Time__fini(&msg->latest_arrival_time);
  // service_time
  builtin_interfaces__msg__Duration__fini(&msg->service_time);
}

bool
delivery_robot_interfaces__msg__OrderStep__are_equal(const delivery_robot_interfaces__msg__OrderStep * lhs, const delivery_robot_interfaces__msg__OrderStep * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // order_index
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->order_index), &(rhs->order_index)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // earliest_arrival_time
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->earliest_arrival_time), &(rhs->earliest_arrival_time)))
  {
    return false;
  }
  // latest_arrival_time
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->latest_arrival_time), &(rhs->latest_arrival_time)))
  {
    return false;
  }
  // service_time
  if (!builtin_interfaces__msg__Duration__are_equal(
      &(lhs->service_time), &(rhs->service_time)))
  {
    return false;
  }
  return true;
}

bool
delivery_robot_interfaces__msg__OrderStep__copy(
  const delivery_robot_interfaces__msg__OrderStep * input,
  delivery_robot_interfaces__msg__OrderStep * output)
{
  if (!input || !output) {
    return false;
  }
  // order_index
  if (!rosidl_runtime_c__String__copy(
      &(input->order_index), &(output->order_index)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // earliest_arrival_time
  if (!builtin_interfaces__msg__Time__copy(
      &(input->earliest_arrival_time), &(output->earliest_arrival_time)))
  {
    return false;
  }
  // latest_arrival_time
  if (!builtin_interfaces__msg__Time__copy(
      &(input->latest_arrival_time), &(output->latest_arrival_time)))
  {
    return false;
  }
  // service_time
  if (!builtin_interfaces__msg__Duration__copy(
      &(input->service_time), &(output->service_time)))
  {
    return false;
  }
  return true;
}

delivery_robot_interfaces__msg__OrderStep *
delivery_robot_interfaces__msg__OrderStep__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  delivery_robot_interfaces__msg__OrderStep * msg = (delivery_robot_interfaces__msg__OrderStep *)allocator.allocate(sizeof(delivery_robot_interfaces__msg__OrderStep), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(delivery_robot_interfaces__msg__OrderStep));
  bool success = delivery_robot_interfaces__msg__OrderStep__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
delivery_robot_interfaces__msg__OrderStep__destroy(delivery_robot_interfaces__msg__OrderStep * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    delivery_robot_interfaces__msg__OrderStep__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
delivery_robot_interfaces__msg__OrderStep__Sequence__init(delivery_robot_interfaces__msg__OrderStep__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  delivery_robot_interfaces__msg__OrderStep * data = NULL;

  if (size) {
    data = (delivery_robot_interfaces__msg__OrderStep *)allocator.zero_allocate(size, sizeof(delivery_robot_interfaces__msg__OrderStep), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = delivery_robot_interfaces__msg__OrderStep__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        delivery_robot_interfaces__msg__OrderStep__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
delivery_robot_interfaces__msg__OrderStep__Sequence__fini(delivery_robot_interfaces__msg__OrderStep__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      delivery_robot_interfaces__msg__OrderStep__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

delivery_robot_interfaces__msg__OrderStep__Sequence *
delivery_robot_interfaces__msg__OrderStep__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  delivery_robot_interfaces__msg__OrderStep__Sequence * array = (delivery_robot_interfaces__msg__OrderStep__Sequence *)allocator.allocate(sizeof(delivery_robot_interfaces__msg__OrderStep__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = delivery_robot_interfaces__msg__OrderStep__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
delivery_robot_interfaces__msg__OrderStep__Sequence__destroy(delivery_robot_interfaces__msg__OrderStep__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    delivery_robot_interfaces__msg__OrderStep__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
delivery_robot_interfaces__msg__OrderStep__Sequence__are_equal(const delivery_robot_interfaces__msg__OrderStep__Sequence * lhs, const delivery_robot_interfaces__msg__OrderStep__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!delivery_robot_interfaces__msg__OrderStep__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
delivery_robot_interfaces__msg__OrderStep__Sequence__copy(
  const delivery_robot_interfaces__msg__OrderStep__Sequence * input,
  delivery_robot_interfaces__msg__OrderStep__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(delivery_robot_interfaces__msg__OrderStep);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    delivery_robot_interfaces__msg__OrderStep * data =
      (delivery_robot_interfaces__msg__OrderStep *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!delivery_robot_interfaces__msg__OrderStep__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          delivery_robot_interfaces__msg__OrderStep__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!delivery_robot_interfaces__msg__OrderStep__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
