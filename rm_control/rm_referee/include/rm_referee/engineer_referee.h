//
// Created by ljq on 2021/12/4.
//

#pragma once
#include "rm_referee/chassis_gimbal_referee.h"
#include <rm_common/decision/calibration_queue.h>

namespace rm_referee
{
class EngineerReferee : public ChassisGimbalReferee
{
public:
  explicit EngineerReferee(ros::NodeHandle& nh) : ChassisGimbalReferee(nh){};
  void run() override;

private:
  void drawUi(const ros::Time& time) override;

  int operating_mode_, sentry_mode_;
  rm_common::CalibrationQueue *power_on_calibration_{}, *mast_calibration_{}, *arm_calibration_{};
  rm_common::JointPositionBinaryCommandSender *mast_command_sender_, *card_command_sender_;

  //  void ctrlXPress() {
  //    target_ = "EXCHANGE_";
  //    prefix_ = "";
  //    trigger_change_ui_->update("step", prefix_ + target_);
  //  }
};
}  // namespace rm_referee
