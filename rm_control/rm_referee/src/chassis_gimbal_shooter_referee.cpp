//
// Created by ljq on 2021/12/4.
//

#include "rm_referee/chassis_gimbal_shooter_referee.h"

namespace rm_referee
{
void ChassisGimbalShooterReferee::run()
{
  ChassisGimbalReferee::run();
  switch_detection_srv_->setEnemyColor(data_.referee_.referee_data_);
}

    void ChassisGimbalShooterReferee::drawUi(const ros::Time &time) {
        ChassisGimbalReferee::drawUi(time);
        if (data_.referee_.referee_data_.robot_id_ != rm_common::RobotId::BLUE_HERO &&
            data_.referee_.referee_data_.robot_id_ != rm_common::RobotId::RED_HERO)
            trigger_change_ui_->update("target", switch_detection_srv_->getTarget(),
                                       data_.command_sender_data_.shooter_burst_flag_,
                                       switch_detection_srv_->getArmorTarget(),
                                       switch_detection_srv_->getColor() == rm_msgs::StatusChangeRequest::RED);
        else
            trigger_change_ui_->update("target", data_.command_sender_data_.gimbal_eject_flag_ ? 1 : 0,
                                       data_.command_sender_data_.shooter_burst_flag_,
                                       switch_detection_srv_->getArmorTarget(),
                                       switch_detection_srv_->getColor() == rm_msgs::StatusChangeRequest::RED);
        trigger_change_ui_->update("exposure", switch_detection_srv_->getExposureLevel(), false);
        fixed_ui_->update();
    }
}  // namespace rm_referee
