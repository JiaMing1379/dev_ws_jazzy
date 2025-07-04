# Heading
ros2 launch articubot_one launch_sim.launch.py
rviz2 -d src/articubot_one/config/main.rviz
ros2 launch articubot_one localization_launch.py map:=./map_save.yaml use_sim_time:=true
ros2 launch articubot_one navigation_launch.py use_sim_time:=true map_subscribe_transient_local:=true

ros2 launch articubot_one online_async_launch.py map:=./map_save.yaml use_sim_time:=true
