# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;roslint;rm_msgs;rm_common;pluginlib;hardware_interface;controller_interface;realtime_tools;effort_controllers;control_msgs".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lrm_calibration_controllers".split(';') if "-lrm_calibration_controllers" != "" else []
PROJECT_NAME = "rm_calibration_controllers"
PROJECT_SPACE_DIR = "/usr/local"
PROJECT_VERSION = "0.1.2"
