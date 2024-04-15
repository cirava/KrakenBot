// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "Constants.h"
#include "subsystems/Climber.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"

#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/DriverStation.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Timer.h>
#include <frc2/command/button/POVButton.h>

#include <frc2/command/CommandPtr.h>

class RobotContainer {
 public:
  RobotContainer();

  //***********CONTROLLERS**********
    frc::XboxController m_botDriver{0};
    frc::XboxController m_topDriver{1};

  //**************SUBSYSTEMS*************
    Climber m_climber;
    Intake  m_intake;
    Shooter m_shooter;

  frc2::CommandPtr GetAutonomousCommand();

 private:
  void ConfigureBindings();
};
