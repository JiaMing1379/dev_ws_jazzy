import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration, Command
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node

import xacro


def generate_launch_description():
    # Check if we're told to use sim time
    use_sim_time = LaunchConfiguration('use_sim_time')
    use_ros2_control = LaunchConfiguration('use_ros2_control')
    namespace = LaunchConfiguration('namespace')

    # Process the URDF file
    pkg_path = os.path.join(get_package_share_directory('articubot_one')) # /dev_ws_jazzy/src/articubot_one
    xacro_file = os.path.join(pkg_path, 'description', 'robot.urdf.xacro') # /dev_ws_jazzy/src/articubot_one/description/robot.urdf.xacro

    # Include namespace in the xacro processing for multi-robot support
    robot_description_config = Command([
        'xacro ', xacro_file, 
        ' use_ros2_control:=', use_ros2_control, 
        ' sim_mode:=', use_sim_time,
        ' namespace:=', namespace
    ])
    
    # Create a robot_state_publisher node with namespace
    params = {'robot_description': robot_description_config, 'use_sim_time': use_sim_time}
    node_robot_state_publisher = Node( #rsp takes urdf file as a parameter called robot_description, parameter is entire content of urdf is passed in as robot description parameter
        package='robot_state_publisher',
        executable='robot_state_publisher',
        namespace=namespace,
        output='screen',
        parameters=[params],
        remappings=[
            ('/tf', 'tf'),
            ('/tf_static', 'tf_static')
        ]
    )

    # Launch!
    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='false',
            description='Use sim time if true'
        ),
        DeclareLaunchArgument(
            'use_ros2_control',
            default_value='true',
            description='Use ros2_control if true'
        ),
        DeclareLaunchArgument(
            'namespace',
            default_value='',
            description='Robot namespace'
        ),

        node_robot_state_publisher
    ])