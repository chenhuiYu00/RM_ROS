//
// Created by ljq on 2021/12/4.
//

#pragma once

#include "rm_referee/common/referee_base.h"

namespace rm_referee
{
class ChassisGimbalReferee : public RefereeBase
{
public:
  explicit ChassisGimbalReferee(ros::NodeHandle& nh);

protected:
  void drawUi(const ros::Time& time) override;

  TimeChangeUi* time_change_ui_{};
  FlashUi* flash_ui_{};
  TriggerChangeUi* trigger_change_ui_{};
  FixedUi* fixed_ui_{};
};
}  // namespace rm_referee
