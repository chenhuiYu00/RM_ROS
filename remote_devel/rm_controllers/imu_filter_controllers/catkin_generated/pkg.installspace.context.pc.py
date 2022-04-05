# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;roslint;rm_msgs;rm_common;pluginlib;imu_complementary_filter;imu_filter_madgwick;hardware_interface;controller_interface;realtime_tools".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-limu_filter_controllers".split(';') if "-limu_filter_controllers" != "" else []
PROJECT_NAME = "imu_filter_controllers"
PROJECT_SPACE_DIR = "/usr/local"
PROJECT_VERSION = "0.1.2"
