# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include;/usr/include/eigen3".split(';') if "${prefix}/include;/usr/include/eigen3" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;roslint;rm_msgs;rm_common;nav_msgs;pluginlib;hardware_interface;controller_interface;forward_command_controller;realtime_tools;control_toolbox;effort_controllers;tf2;tf2_geometry_msgs;angles".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lrm_chassis_controllers".split(';') if "-lrm_chassis_controllers" != "" else []
PROJECT_NAME = "rm_chassis_controllers"
PROJECT_SPACE_DIR = "/usr/local"
PROJECT_VERSION = "0.1.2"
