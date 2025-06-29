# generated from rosidl_generator_py/resource/_idl.py.em
# with input from delivery_robot_interfaces:msg/Order.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Order(type):
    """Metaclass of message 'Order'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('delivery_robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'delivery_robot_interfaces.msg.Order')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__order
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__order
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__order
            cls._TYPE_SUPPORT = module.type_support_msg__msg__order
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__order

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

            from delivery_robot_interfaces.msg import OrderStep
            if OrderStep.__class__._TYPE_SUPPORT is None:
                OrderStep.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Order(metaclass=Metaclass_Order):
    """Message class 'Order'."""

    __slots__ = [
        '_order_index',
        '_order_time',
        '_steps',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'order_index': 'string',
        'order_time': 'builtin_interfaces/Time',
        'steps': 'sequence<delivery_robot_interfaces/OrderStep>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['delivery_robot_interfaces', 'msg'], 'OrderStep')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.order_index = kwargs.get('order_index', str())
        from builtin_interfaces.msg import Time
        self.order_time = kwargs.get('order_time', Time())
        self.steps = kwargs.get('steps', [])

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.order_index != other.order_index:
            return False
        if self.order_time != other.order_time:
            return False
        if self.steps != other.steps:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def order_index(self):
        """Message field 'order_index'."""
        return self._order_index

    @order_index.setter
    def order_index(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'order_index' field must be of type 'str'"
        self._order_index = value

    @builtins.property
    def order_time(self):
        """Message field 'order_time'."""
        return self._order_time

    @order_time.setter
    def order_time(self, value):
        if self._check_fields:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'order_time' field must be a sub message of type 'Time'"
        self._order_time = value

    @builtins.property
    def steps(self):
        """Message field 'steps'."""
        return self._steps

    @steps.setter
    def steps(self, value):
        if self._check_fields:
            from delivery_robot_interfaces.msg import OrderStep
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, OrderStep) for v in value) and
                 True), \
                "The 'steps' field must be a set or sequence and each value of type 'OrderStep'"
        self._steps = value
