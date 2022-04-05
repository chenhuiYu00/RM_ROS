cmake_minimum_required(VERSION 3.0.2)
project(rm_referee)

## Use C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## By adding -Wall and -Werror, the compiler does not ignore warnings anymore,
## enforcing cleaner code.
add_definitions(-Wall -Werror)

find_package(serial REQUIRED)

find_package(catkin REQUIRED
        COMPONENTS
        roscpp
        rm_common
        rm_msgs
        serial
        )

catkin_package(
        INCLUDE_DIRS include
        CATKIN_DEPENDS
        rm_common
        rm_msgs
        serial
        roscpp
        DEPENDS
        LIBRARIES
)

include_directories(
        include
        ${catkin_INCLUDE_DIRS}
)

## Declare cpp executables
FILE(GLOB ALL_SOURCES "src/*.cpp" "src/common/*.cpp" "src/referee/*.cpp" "src/ui/*.cpp")
add_executable(${PROJECT_NAME} ${ALL_SOURCES})

add_dependencies(${PROJECT_NAME}
        ${catkin_EXPORTED_TARGETS}
        )

target_link_libraries(rm_referee ${catkin_LIBRARIES})
target_link_libraries(${PROJECT_NAME}
        ${catkin_LIBRARIES}
        )

# Mark executables and/or libraries for installation
install(
        TARGETS ${PROJECT_NAME}
        ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# Mark cpp header files for installation
install(
        DIRECTORY include/${PROJECT_NAME}/
        DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
        FILES_MATCHING PATTERN "*.h"
)

## Mark other files for installation
install(
        DIRECTORY config launch
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
