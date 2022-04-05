# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "sensor_msgs;roslint;rm_msgs;rm_common;tf2_geometry_msgs;std_msgs;actionlib;nav_msgs".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lrm_manual".split(';') if "-lrm_manual" != "" else []
PROJECT_NAME = "rm_manual"
PROJECT_SPACE_DIR = "/usr/local"
PROJECT_VERSION = "1.0.54"
