# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;roslint;rm_common;hardware_interface;controller_interface;urdf;tf2_ros;kdl_parser;realtime_tools;pluginlib".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lrobot_state_controller".split(';') if "-lrobot_state_controller" != "" else []
PROJECT_NAME = "robot_state_controller"
PROJECT_SPACE_DIR = "/usr/local"
PROJECT_VERSION = "0.1.2"
