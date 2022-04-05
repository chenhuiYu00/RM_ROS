//
// Created by ljq on 2021/12/5.
//

#include "rm_referee/chassis_gimbal_shooter_cover_referee.h"

namespace rm_referee
{
void ChassisGimbalShooterCoverReferee::run()
{
  ChassisGimbalReferee::run();
  switch_detection_srv_->setEnemyColor(data_.referee_.referee_data_);
}

 void ChassisGimbalShooterCoverReferee::drawUi(const ros::Time& time)
{
  ChassisGimbalShooterReferee::drawUi(time);
  flash_ui_->update("cover", time, !data_.command_sender_data_.cover_state_);
}
}  // namespace rm_referee
