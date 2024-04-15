// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdClimberDefault.h"
#include "Robot.h"

CmdClimberDefault::CmdClimberDefault() {}

void CmdClimberDefault::Initialize() {}

void CmdClimberDefault::Execute() 
{
  if(robotContainer.m_topDriver.GetLeftY() > 0.1 and !robotContainer.m_climber.GetTopClimberLimit())
  {
    robotContainer.m_climber.SetClimberPower(robotContainer.m_topDriver.GetLeftY());
  }
  else if(robotContainer.m_topDriver.GetLeftY() < -0.1 and !robotContainer.m_climber.GetBotClimberLimit())
  {
    robotContainer.m_climber.SetClimberPower(robotContainer.m_topDriver.GetLeftY());
  }
  else
  {
    robotContainer.m_climber.SetClimberPower(0);
  }
}

void CmdClimberDefault::End(bool interrupted) {}

bool CmdClimberDefault::IsFinished() {
  return false;
}
