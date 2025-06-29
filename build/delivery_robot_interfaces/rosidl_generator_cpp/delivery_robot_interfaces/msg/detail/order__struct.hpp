// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from delivery_robot_interfaces:msg/Order.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "delivery_robot_interfaces/msg/order.hpp"


#ifndef DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER__STRUCT_HPP_
#define DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'order_time'
#include "builtin_interfaces/msg/detail/time__struct.hpp"
// Member 'steps'
#include "delivery_robot_interfaces/msg/detail/order_step__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__delivery_robot_interfaces__msg__Order __attribute__((deprecated))
#else
# define DEPRECATED__delivery_robot_interfaces__msg__Order __declspec(deprecated)
#endif

namespace delivery_robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Order_
{
  using Type = Order_<ContainerAllocator>;

  explicit Order_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : order_time(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->order_index = "";
    }
  }

  explicit Order_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : order_index(_alloc),
    order_time(_alloc, _init)
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
  using _order_time_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _order_time_type order_time;
  using _steps_type =
    std::vector<delivery_robot_interfaces::msg::OrderStep_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<delivery_robot_interfaces::msg::OrderStep_<ContainerAllocator>>>;
  _steps_type steps;

  // setters for named parameter idiom
  Type & set__order_index(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->order_index = _arg;
    return *this;
  }
  Type & set__order_time(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->order_time = _arg;
    return *this;
  }
  Type & set__steps(
    const std::vector<delivery_robot_interfaces::msg::OrderStep_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<delivery_robot_interfaces::msg::OrderStep_<ContainerAllocator>>> & _arg)
  {
    this->steps = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    delivery_robot_interfaces::msg::Order_<ContainerAllocator> *;
  using ConstRawPtr =
    const delivery_robot_interfaces::msg::Order_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<delivery_robot_interfaces::msg::Order_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<delivery_robot_interfaces::msg::Order_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      delivery_robot_interfaces::msg::Order_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<delivery_robot_interfaces::msg::Order_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      delivery_robot_interfaces::msg::Order_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<delivery_robot_interfaces::msg::Order_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<delivery_robot_interfaces::msg::Order_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<delivery_robot_interfaces::msg::Order_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__delivery_robot_interfaces__msg__Order
    std::shared_ptr<delivery_robot_interfaces::msg::Order_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__delivery_robot_interfaces__msg__Order
    std::shared_ptr<delivery_robot_interfaces::msg::Order_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Order_ & other) const
  {
    if (this->order_index != other.order_index) {
      return false;
    }
    if (this->order_time != other.order_time) {
      return false;
    }
    if (this->steps != other.steps) {
      return false;
    }
    return true;
  }
  bool operator!=(const Order_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Order_

// alias to use template instance with default allocator
using Order =
  delivery_robot_interfaces::msg::Order_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace delivery_robot_interfaces

#endif  // DELIVERY_ROBOT_INTERFACES__MSG__DETAIL__ORDER__STRUCT_HPP_
