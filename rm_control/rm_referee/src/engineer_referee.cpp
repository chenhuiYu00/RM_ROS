//
// Created by ljq on 2021/12/4.
//

#include "rm_referee/engineer_referee.h"

namespace rm_referee
{
void EngineerReferee::run()
{
  ChassisGimbalReferee::run();
  //  power_on_calibration_->update(ros::Time::now(), state_ != PASSIVE);
  //  mast_calibration_->update(ros::Time::now(), state_ != PASSIVE);
  arm_calibration_->update(ros::Time::now());
}

void EngineerReferee::drawUi(const ros::Time& time)
{
  ChassisGimbalReferee::drawUi(time);
  time_change_ui_->update("effort", time);
  time_change_ui_->update("temperature", time);
  trigger_change_ui_->update("card", 0, card_command_sender_->getState());
  if (data_.referee_.referee_data_.interactive_data.header_data_.data_cmd_id_ == 0x0201 &&
      data_.referee_.referee_data_.interactive_data.data_ != sentry_mode_)
    data_.referee_.sendInteractiveData(
        0x0200,
        data_.referee_.referee_data_.robot_color_ == "blue" ? rm_common::RobotId::BLUE_SENTRY : rm_common::RED_SENTRY,
        sentry_mode_);
  trigger_change_ui_->update("sentry", data_.referee_.referee_data_.interactive_data.data_, false);
  flash_ui_->update("calibration", time, power_on_calibration_->isCalibrated());
  if (!data_.joint_state_.name.empty())
    flash_ui_->update("card_warning", time, data_.joint_state_.effort[0] < 1.5);
  //    trigger_change_ui_->update("jog", jog_joint_name);
}
}  // namespace rm_referee
