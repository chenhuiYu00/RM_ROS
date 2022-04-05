//
// Created by peter on 2021/7/19.
//

#pragma once

#include "rm_referee/common/referee.h"
#include <rm_common/ros_utilities.h>
#include <rm_common/referee/protocol.h>

namespace rm_referee
{
class Graph
{
public:
  explicit Graph(const XmlRpc::XmlRpcValue& config, Referee& referee, int id);
  void display(bool priority_flag = false);
  void displayTwice(bool priority_flag = false);
  void display(const ros::Time& time);
  void display(const ros::Time& time, bool state, bool once = false);
  void updatePosition(int index);
  void setOperation(const rm_common::GraphOperation& operation)
  {
    config_.operate_type_ = operation;
  }
  void setColor(const rm_common::GraphColor& color)
  {
    config_.color_ = color;
  }
  void setContent(const std::string& content)
  {
    content_ = content;
  }
  void setStartX(int start_x)
  {
    config_.start_x_ = start_x;
  }
  void setStartY(int start_y)
  {
    config_.start_y_ = start_y;
  }

private:
  void initPosition(XmlRpc::XmlRpcValue value, std::vector<std::pair<int, int>>& positions);
  rm_common::GraphColor getColor(const std::string& color);
  rm_common::GraphType getType(const std::string& type);
  Referee& referee_;
  ros::Time last_time_ = ros::Time::now();
  ros::Duration delay_ = ros::Duration(0.);
  rm_common::GraphConfig config_{}, last_config_{};
  std::string title_{}, content_{}, last_title_{}, last_content_{};
  std::vector<std::pair<int, int>> start_positions_{}, end_positions_{};
};

}  // namespace rm_referee
