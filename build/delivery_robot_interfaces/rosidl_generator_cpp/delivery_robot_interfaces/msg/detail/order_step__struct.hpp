// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from delivery_robot_interfaces:msg/OrderStep.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "delivery_robot_interfaces/msg/order_step.hpp"


#ifndef DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER_STEP__STRUCT_HPP_
#define DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER_STEP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'earliest_arrival_time'
// Member 'latest_arrival_time'
#include "builtin_interfaces/msg/detail/time__struct.hpp"
// Member 'service_time'
#include "builtin_interfaces/msg/detail/duration__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__delivery_robot_interfaces__msg__OrderStep __attribute__((deprecated))
#else
# define DEPRECATED__delivery_robot_interfaces__msg__OrderStep __declspec(deprecated)
#endif

namespace delivery_robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OrderStep_
{
  using Type = OrderStep_<ContainerAllocator>;

  explicit OrderStep_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init),
    earliest_arrival_time(_init),
    latest_arrival_time(_init),
    service_time(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->order_index = "";
    }
  }

  explicit OrderStep_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : order_index(_alloc),
    position(_alloc, _init),
    earliest_arrival_time(_alloc, _init),
    latest_arrival_time(_alloc, _init),
    service_time(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->order_index = "";
    }
  }

  // field types and members
  using _order_index_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _order_index_type order_index;
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
  using _earliest_arrival_time_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _earliest_arrival_time_type earliest_arrival_time;
  using _latest_arrival_time_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _latest_arrival_time_type latest_arrival_time;
  using _service_time_type =
    builtin_interfaces::msg::Duration_<ContainerAllocator>;
  _service_time_type service_time;

  // setters for named parameter idiom
  Type & set__order_index(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->order_index = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__earliest_arrival_time(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->earliest_arrival_time = _arg;
    return *this;
  }
  Type & set__latest_arrival_time(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->latest_arrival_time = _arg;
    return *this;
  }
  Type & set__service_time(
    const builtin_interfaces::msg::Duration_<ContainerAllocator> & _arg)
  {
    this->service_time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    delivery_robot_interfaces::msg::OrderStep_<ContainerAllocator> *;
  using ConstRawPtr =
    const delivery_robot_interfaces::msg::OrderStep_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<delivery_robot_interfaces::msg::OrderStep_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<delivery_robot_interfaces::msg::OrderStep_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      delivery_robot_interfaces::msg::OrderStep_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<delivery_robot_interfaces::msg::OrderStep_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      delivery_robot_interfaces::msg::OrderStep_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<delivery_robot_interfaces::msg::OrderStep_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<delivery_robot_interfaces::msg::OrderStep_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<delivery_robot_interfaces::msg::OrderStep_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__delivery_robot_interfaces__msg__OrderStep
    std::shared_ptr<delivery_robot_interfaces::msg::OrderStep_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__delivery_robot_interfaces__msg__OrderStep
    std::shared_ptr<delivery_robot_interfaces::msg::OrderStep_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OrderStep_ & other) const
  {
    if (this->order_index != other.order_index) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->earliest_arrival_time != other.earliest_arrival_time) {
      return false;
    }
    if (this->latest_arrival_time != other.latest_arrival_time) {
      return false;
    }
    if (this->service_time != other.service_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const OrderStep_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OrderStep_

// alias to use template instance with default allocator
using OrderStep =
  delivery_robot_interfaces::msg::OrderStep_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace delivery_robot_interfaces

#endif  // DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER_STEP__STRUCT_HPP_
