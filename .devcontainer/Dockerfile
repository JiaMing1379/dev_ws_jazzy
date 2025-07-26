
FROM osrf/ros:jazzy-desktop
# Add ubuntu user with same UID and GID as your host system, if it doesn't already exist
# Since Ubuntu 24.04, a non-root user is created by default with the name vscode and UID=1000
ARG USERNAME=ubuntu
ARG USER_UID=1000
ARG USER_GID=$USER_UID
RUN if ! id -u $USER_UID >/dev/null 2>&1; then \
groupadd --gid $USER_GID $USERNAME && \
useradd -s /bin/bash --uid $USER_UID --gid $USER_GID -m $USERNAME; \
fi

# Add sudo support for the non-root user
RUN apt-get update && \
apt-get install -y sudo && \
echo "$USERNAME ALL=(root) NOPASSWD:ALL" > /etc/sudoers.d/$USERNAME && \
chmod 0440 /etc/sudoers.d/$USERNAME
# Switch from root to user
USER $USERNAME

# Add user to video group to allow access to webcam
RUN sudo usermod --append --groups video $USERNAME

# Update all packages
RUN sudo apt update && sudo apt upgrade -y

# Install Git
RUN sudo apt install -y git
RUN sudo apt install -y libserial-dev
RUN sudo apt install -y mesa-utils

# Set timezone to Asia/Kuala_Lumpur
ENV TZ=Asia/Kuala_Lumpur
RUN sudo apt-get update && sudo apt-get install -y tzdata && \
    sudo ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && \
    echo $TZ | sudo tee /etc/timezone && \
    sudo dpkg-reconfigure -f noninteractive tzdata
    
# Rosdep update
RUN rosdep update

# Source the ROS setup file
RUN echo "source /opt/ros/${ROS_DISTRO}/setup.bash" >> ~/.bashrc

RUN sudo apt-get update && \
sudo apt-get install -y \
ros-${ROS_DISTRO}-xacro \
ros-${ROS_DISTRO}-rqt \
ros-${ROS_DISTRO}-joint-state-publisher \
ros-${ROS_DISTRO}-ros-gz \
ros-${ROS_DISTRO}-gz-ros2-control \
ros-${ROS_DISTRO}-twist-mux \
ros-${ROS_DISTRO}-twist-stamper \
ros-${ROS_DISTRO}-ros2-control \
ros-${ROS_DISTRO}-ros2-controllers \
ros-${ROS_DISTRO}-turtlesim \
ros-${ROS_DISTRO}-rviz2 \
ros-${ROS_DISTRO}-joint-state-publisher-gui \
ros-${ROS_DISTRO}-slam-toolbox \
ros-${ROS_DISTRO}-navigation2 \
ros-${ROS_DISTRO}-nav2-bringup \
ros-${ROS_DISTRO}-turtlebot3* \
ros-${ROS_DISTRO}-ros-gz-sim \
ros-${ROS_DISTRO}-rmw-zenoh-cpp \
&& sudo rm -rf /var/lib/apt/lists/*

################################
## ADD ANY CUSTOM SETUP BELOW ##
################################
