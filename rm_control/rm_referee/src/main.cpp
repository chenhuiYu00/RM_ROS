//
// Created by ljq on 2021/11/29.
//

#include "rm_referee/common/referee_base.h"
#include "rm_referee/chassis_gimbal_shooter_referee.h"
#include "rm_referee/chassis_gimbal_shooter_cover_referee.h"
#include "rm_referee/engineer_referee.h"

int main(int argc, char** argv)
{
  std::string robot;
  rm_referee::RefereeBase* referee;
  ros::init(argc, argv, "rm_manual");
  ros::NodeHandle nh("~");
  robot = getParam(nh, "robot_type", (std::string) "error");
  if (robot == "standard")
    referee = new rm_referee::ChassisGimbalShooterCoverReferee(nh);
  else if (robot == "hero")
    referee = new rm_referee::ChassisGimbalShooterReferee(nh);
  else if (robot == "engineer")
    referee = new rm_referee::EngineerReferee(nh);
  else if (robot == "sentry")
    referee = new rm_referee::ChassisGimbalShooterReferee(nh);
  else
  {
    ROS_ERROR("no robot type ");
    return 0;
  }
  ros::Rate loop_rate(100);
  while (ros::ok())
  {
    ros::spinOnce();
    referee->run();
    loop_rate.sleep();
  }
  return 0;
}
