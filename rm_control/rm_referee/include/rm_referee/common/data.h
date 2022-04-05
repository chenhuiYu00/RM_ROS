//
// Created by ljq on 2021/12/3.
//

#pragma once

#include <ros/ros.h>
#include <serial/serial.h>
#include <rm_common/decision/target_cost_function.h>
#include "rm_referee/common/referee.h"
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/JointState.h>
#include <rm_msgs/ActuatorState.h>
#include <rm_msgs/DbusData.h>
#include <rm_msgs/GimbalDesError.h>
#include <rm_msgs/GameStatus.h>
#include <rm_msgs/CapacityData.h>
#include <rm_msgs/CommandSender.h>
#include <rm_msgs/GameRobotStatus.h>

namespace rm_referee
{
class Data
{
public:
  explicit Data(ros::NodeHandle& nh) : tf_listener_(tf_buffer_)
  {
    // sub
    joint_state_sub_ = nh.subscribe<sensor_msgs::JointState>("/joint_states", 10, &Data::jointStateCallback, this);
    actuator_state_sub_ =
        nh.subscribe<rm_msgs::ActuatorState>("/actuator_states", 10, &Data::actuatorStateCallback, this);
    dbus_sub_ = nh.subscribe<rm_msgs::DbusData>("/dbus_data", 10, &Data::dbusDataCallback, this);
    command_sender_sub_ =
        nh.subscribe<rm_msgs::CommandSender>("/command_sender", 10, &Data::commandSenderDataCallback, this);
    // pub
    ros::NodeHandle root_nh;
    referee_.referee_pub_ = root_nh.advertise<rm_msgs::Referee>("/referee", 1);
    referee_.super_capacitor_pub_ = root_nh.advertise<rm_msgs::SuperCapacitor>("/super_capacitor", 1);
    referee_.game_robot_status_pub_ = root_nh.advertise<rm_msgs::GameRobotStatus>("/game_robot_status_pub", 1);
    referee_.game_status_pub_ = root_nh.advertise<rm_msgs::GameStatus>("/game_status", 1);
    referee_.capacity_data_pub_ = root_nh.advertise<rm_msgs::CapacityData>("/capacity_data", 1);
    initSerial();
  }

  void jointStateCallback(const sensor_msgs::JointState::ConstPtr& joint_state)
  {
    joint_state_ = *joint_state;
  }
  void actuatorStateCallback(const rm_msgs::ActuatorState::ConstPtr& data)
  {
    actuator_state_ = *data;
  }
  void dbusDataCallback(const rm_msgs::DbusData::ConstPtr& data)
  {
    dbus_data_ = *data;
  }
  void commandSenderDataCallback(const rm_msgs::CommandSender ::ConstPtr& data)
  {
    command_sender_data_ = *data;
  }

  void initSerial()
  {
    serial::Timeout timeout = serial::Timeout::simpleTimeout(50);
    serial_.setPort("/dev/usbReferee");
    serial_.setBaudrate(115200);
    serial_.setTimeout(timeout);
    if (serial_.isOpen())
      return;
    try
    {
      serial_.open();
    }
    catch (serial::IOException& e)
    {
      ROS_ERROR("Cannot open referee port");
    }
  }

  ros::Subscriber joint_state_sub_;
  ros::Subscriber actuator_state_sub_;
  ros::Subscriber dbus_sub_;
  ros::Subscriber command_sender_sub_;

  sensor_msgs::JointState joint_state_;
  rm_msgs::ActuatorState actuator_state_;
  rm_msgs::DbusData dbus_data_;
  rm_msgs::CommandSender command_sender_data_;

  Referee referee_;
  serial::Serial serial_;

  tf2_ros::Buffer tf_buffer_;
  tf2_ros::TransformListener tf_listener_;
};

}  // namespace rm_referee
