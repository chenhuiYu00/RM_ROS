# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;roslint;sensor_msgs;rm_msgs;rm_common;pluginlib;hardware_interface;controller_interface;forward_command_controller;tf2;tf2_geometry_msgs;angles".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lrm_orientation_controller".split(';') if "-lrm_orientation_controller" != "" else []
PROJECT_NAME = "rm_orientation_controller"
PROJECT_SPACE_DIR = "/usr/local"
PROJECT_VERSION = "0.1.2"
