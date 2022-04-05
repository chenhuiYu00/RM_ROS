//
// Created by ljq on 2021/12/4.
//

#pragma once

#include "rm_referee/chassis_gimbal_referee.h"
#include <rm_common/decision/calibration_queue.h>

namespace rm_referee
{
class ChassisGimbalShooterReferee : public ChassisGimbalReferee
{
public:
  explicit ChassisGimbalShooterReferee(ros::NodeHandle& nh) : ChassisGimbalReferee(nh)
  {
    ros::NodeHandle detection_switch_nh(nh, "detection_switch");
    switch_detection_srv_ = new rm_common::SwitchDetectionCaller(detection_switch_nh);
  };
  void run() override;

protected:
  void drawUi(const ros::Time& time) override;

  rm_common::SwitchDetectionCaller* switch_detection_srv_{};
};
}  // namespace rm_referee
