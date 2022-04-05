//
// Created by ljq on 2021/12/4.
//

#pragma once

#include "rm_referee/chassis_gimbal_shooter_referee.h"

namespace rm_referee
{
class ChassisGimbalShooterCoverReferee : public ChassisGimbalShooterReferee
{
public:
  explicit ChassisGimbalShooterCoverReferee(ros::NodeHandle& nh) : ChassisGimbalShooterReferee(nh){};
  void run() override;

protected:
  void drawUi(const ros::Time& time) override;
};
}  // namespace rm_referee
