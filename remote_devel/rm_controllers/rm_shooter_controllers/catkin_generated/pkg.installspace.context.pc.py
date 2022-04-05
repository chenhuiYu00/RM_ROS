# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;roslint;rm_msgs;rm_common;pluginlib;hardware_interface;controller_interface;forward_command_controller;realtime_tools;control_toolbox;effort_controllers;dynamic_reconfigure".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lrm_shooter_controllers".split(';') if "-lrm_shooter_controllers" != "" else []
PROJECT_NAME = "rm_shooter_controllers"
PROJECT_SPACE_DIR = "/usr/local"
PROJECT_VERSION = "0.1.2"
