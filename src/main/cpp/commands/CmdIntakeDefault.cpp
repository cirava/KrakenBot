// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdIntakeDefault.h"
#include "Robot.h"

#include <iostream>

CmdIntakeDefault::CmdIntakeDefault() {}

void CmdIntakeDefault::Initialize() 
{
  m_isIntaking = false;
}

void CmdIntakeDefault::Execute() 
{
  if(robotContainer.m_topDriver.GetRightBumperPressed() and !robotContainer.m_intake.GetIntakePhotoeye())
  {
    robotContainer.m_intake.SetIntakeAngle(90_deg);
    m_isIntaking = true;
  }
  else if(robotContainer.m_topDriver.GetRightBumperPressed() and robotContainer.m_intake.GetIntakePhotoeye())
  {
    robotContainer.m_intake.SetIntakeAngle(0_deg);
    std::cout << "Note in Robot" << std::endl;
    m_isIntaking = false;
  }
  else if(m_isIntaking)
  {
    robotContainer.m_intake.SetIntakeAngle(0_deg);
  }
}

// Called once the command ends or is interrupted.
void CmdIntakeDefault::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdIntakeDefault::IsFinished() {
  return false;
}
