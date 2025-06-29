// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from delivery_robot_interfaces:msg/Order.idl
// generated code does not contain a copyright notice
#include "delivery_robot_interfaces/msg/detail/order__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `order_index`
#include "rosidl_runtime_c/string_functions.h"
// Member `order_time`
#include "builtin_interfaces/msg/detail/time__functions.h"
// Member `steps`
#include "delivery_robot_interfaces/msg/detail/order_step__functions.h"

bool
delivery_robot_interfaces__msg__Order__init(delivery_robot_interfaces__msg__Order * msg)
{
  if (!msg) {
    return false;
  }
  // order_index
  if (!rosidl_runtime_c__String__init(&msg->order_index)) {
    delivery_robot_interfaces__msg__Order__fini(msg);
    return false;
  }
  // order_time
  if (!builtin_interfaces__msg__Time__init(&msg->order_time)) {
    delivery_robot_interfaces__msg__Order__fini(msg);
    return false;
  }
  // steps
  if (!delivery_robot_interfaces__msg__OrderStep__Sequence__init(&msg->steps, 0)) {
    delivery_robot_interfaces__msg__Order__fini(msg);
    return false;
  }
  return true;
}

void
delivery_robot_interfaces__msg__Order__fini(delivery_robot_interfaces__msg__Order * msg)
{
  if (!msg) {
    return;
  }
  // order_index
  rosidl_runtime_c__String__fini(&msg->order_index);
  // order_time
  builtin_interfaces__msg__Time__fini(&msg->order_time);
  // steps
  delivery_robot_interfaces__msg__OrderStep__Sequence__fini(&msg->steps);
}

bool
delivery_robot_interfaces__msg__Order__are_equal(const delivery_robot_interfaces__msg__Order * lhs, const delivery_robot_interfaces__msg__Order * rhs)
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
  // order_time
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->order_time), &(rhs->order_time)))
  {
    return false;
  }
  // steps
  if (!delivery_robot_interfaces__msg__OrderStep__Sequence__are_equal(
      &(lhs->steps), &(rhs->steps)))
  {
    return false;
  }
  return true;
}

bool
delivery_robot_interfaces__msg__Order__copy(
  const delivery_robot_interfaces__msg__Order * input,
  delivery_robot_interfaces__msg__Order * output)
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
  // order_time
  if (!builtin_interfaces__msg__Time__copy(
      &(input->order_time), &(output->order_time)))
  {
    return false;
  }
  // steps
  if (!delivery_robot_interfaces__msg__OrderStep__Sequence__copy(
      &(input->steps), &(output->steps)))
  {
    return false;
  }
  return true;
}

delivery_robot_interfaces__msg__Order *
delivery_robot_interfaces__msg__Order__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  delivery_robot_interfaces__msg__Order * msg = (delivery_robot_interfaces__msg__Order *)allocator.allocate(sizeof(delivery_robot_interfaces__msg__Order), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(delivery_robot_interfaces__msg__Order));
  bool success = delivery_robot_interfaces__msg__Order__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
delivery_robot_interfaces__msg__Order__destroy(delivery_robot_interfaces__msg__Order * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    delivery_robot_interfaces__msg__Order__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
delivery_robot_interfaces__msg__Order__Sequence__init(delivery_robot_interfaces__msg__Order__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  delivery_robot_interfaces__msg__Order * data = NULL;

  if (size) {
    data = (delivery_robot_interfaces__msg__Order *)allocator.zero_allocate(size, sizeof(delivery_robot_interfaces__msg__Order), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = delivery_robot_interfaces__msg__Order__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        delivery_robot_interfaces__msg__Order__fini(&data[i - 1]);
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
delivery_robot_interfaces__msg__Order__Sequence__fini(delivery_robot_interfaces__msg__Order__Sequence * array)
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
      delivery_robot_interfaces__msg__Order__fini(&array->data[i]);
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

delivery_robot_interfaces__msg__Order__Sequence *
delivery_robot_interfaces__msg__Order__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  delivery_robot_interfaces__msg__Order__Sequence * array = (delivery_robot_interfaces__msg__Order__Sequence *)allocator.allocate(sizeof(delivery_robot_interfaces__msg__Order__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = delivery_robot_interfaces__msg__Order__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
delivery_robot_interfaces__msg__Order__Sequence__destroy(delivery_robot_interfaces__msg__Order__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    delivery_robot_interfaces__msg__Order__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
delivery_robot_interfaces__msg__Order__Sequence__are_equal(const delivery_robot_interfaces__msg__Order__Sequence * lhs, const delivery_robot_interfaces__msg__Order__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!delivery_robot_interfaces__msg__Order__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
delivery_robot_interfaces__msg__Order__Sequence__copy(
  const delivery_robot_interfaces__msg__Order__Sequence * input,
  delivery_robot_interfaces__msg__Order__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(delivery_robot_interfaces__msg__Order);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    delivery_robot_interfaces__msg__Order * data =
      (delivery_robot_interfaces__msg__Order *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!delivery_robot_interfaces__msg__Order__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          delivery_robot_interfaces__msg__Order__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!delivery_robot_interfaces__msg__Order__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
