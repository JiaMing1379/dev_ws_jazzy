import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument, TimerAction, GroupAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration, TextSubstitution
from launch.actions import OpaqueFunction

import yaml
import tempfile

def create_namespaced_bridge_file(robot_name, base_config_path):
    with open(base_config_path, 'r') as f:
        bridge_config = yaml.safe_load(f)

    for mapping in bridge_config:
        mapping["ros_topic_name"] = f"{robot_name}/{mapping['ros_topic_name']}"

    tmp = tempfile.NamedTemporaryFile(delete=False, mode='w', suffix='.yaml')
    yaml.dump(bridge_config, tmp)
    tmp.close()
    return tmp.name

def generate_launch_description():
    use_sim_time = LaunchConfiguration('use_sim_time')
    package_name = 'articubot_one'
    
    # Multi-robot parameters
    robots = LaunchConfiguration('robots')
    
    # Default world
    default_world = os.path.join(
        get_package_share_directory(package_name),
        'worlds',
        'empty.world'
    )
    
    world = LaunchConfiguration('world')

    # Declare launch arguments
    declare_use_sim_time_cmd = DeclareLaunchArgument(
        'use_sim_time',
        default_value='true',
        description='Use sim time if true'
    )
    
    declare_robots_cmd = DeclareLaunchArgument(
        'robots',
        default_value='robot1;robot2',  # Semicolon-separated list
        description='List of robot names separated by semicolons'
    )
    
    world_arg = DeclareLaunchArgument(
        'world',
        default_value=default_world,
        description='World to load'
    )

    # Include Gazebo launch file
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory('ros_gz_sim'), 'launch', 'gz_sim.launch.py')]),
        launch_arguments={'gz_args': ['-r -v4 ', world], 'on_exit_shutdown': 'true'}.items()
    )

    def launch_setup(context, *args, **kwargs):
        """Function to setup multiple robots dynamically"""
        robots_str = context.perform_substitution(robots)
        robot_list = robots_str.split(';')
        
        launch_actions = []
        
        for i, robot_name in enumerate(robot_list):
            robot_namespace = f'/{robot_name}'
            
            # Robot State Publisher for each robot
            rsp = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory(package_name), 'launch', 'rsp.launch.py'
                )]),
                launch_arguments={
                    'use_sim_time': 'true',
                    'use_ros2_control': 'true',
                    'namespace': robot_name
                }.items()
            )
            
            # Twist Mux for each robot
            twist_mux = Node(
                package="twist_mux",
                executable="twist_mux",
                namespace=robot_name,
                parameters=[{
                    'use_stamped': False,
                    'topics': {
                        'navigation': {
                            'topic': 'cmd_vel',
                            'timeout': 0.5,
                            'priority': 10
                        }
                    }
                }, {'use_sim_time': True}],
                remappings=[('/cmd_vel_out', f'/{robot_name}/diff_cont/cmd_vel_unstamped')]
            )
            
            spawn_x = str(i * 1.0)  # Space robots 1 meter apart
            spawn_y = str(0.0)

            spawn_entity = TimerAction(
                period=5.0,  # Delay 5 seconds to wait for robot_description to be published
                actions=[
                    Node(
                        package='ros_gz_sim',
                        executable='create',
                        arguments=[
                            '-topic', f'/{robot_name}/robot_description',
                            '-name', robot_name,
                            '-x', spawn_x,
                            '-y', spawn_y,
                            '-z', '0.1'
                        ],
                        output='screen'
                    )
                ]
            )

            # Controller spawners for each robot
            diff_drive_spawner = Node(
                package="controller_manager",
                executable="spawner",
                arguments=[
                    "diff_cont",
                    f"--controller-manager", f"/{robot_name}/controller_manager"
                ],
                output="screen"
            )
            
            joint_broad_spawner = Node(
                package="controller_manager",
                executable="spawner",
                arguments=[
                    "joint_broad",
                    f"--controller-manager", f"/{robot_name}/controller_manager"
                ],
                output="screen"
            )
            
            # Bridge parameters for each robot
            pkg_path = os.path.join(get_package_share_directory('articubot_one'))
            bridge_config_path = create_namespaced_bridge_file(robot_name, os.path.join(pkg_path, 'config', 'gz_bridge.yaml'))
            ros_gz_bridge = Node(
                package="ros_gz_bridge",
                executable="parameter_bridge",
                namespace=robot_name,
                arguments=[
                    '--ros-args',
                    '-p',
                    f'config_file:={bridge_config_path}',
                ]
            )
            
            # Twist stamper for each robot
            twist_stamper = Node(
                package='twist_stamper',
                executable='twist_stamper',
                namespace=robot_name,
                parameters=[{'use_sim_time': use_sim_time}],
                remappings=[
                    ('/cmd_vel_in', f'/{robot_name}/diff_cont/cmd_vel_unstamped'),
                    ('/cmd_vel_out', f'/{robot_name}/diff_cont/cmd_vel')
                ]
            )
            
            # Add delay between robot spawns
            spawn_delay = TimerAction(
                period=float(i * 2.0),  # 2-second delay between each robot
                actions=[
                    GroupAction([
                        rsp,
                        twist_mux,
                        twist_stamper,
                        spawn_entity,
                        diff_drive_spawner,
                        joint_broad_spawner,
                        ros_gz_bridge
                    ])
                ]
            )
            
            launch_actions.append(spawn_delay)
        
        return launch_actions

    return LaunchDescription([
        declare_use_sim_time_cmd,
        declare_robots_cmd,
        world_arg,
        gazebo,
        OpaqueFunction(function=launch_setup)
    ])