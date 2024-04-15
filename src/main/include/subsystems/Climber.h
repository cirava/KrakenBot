// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/DoubleSolenoid.h>
#include <frc/DigitalInput.h>
#include <frc/PneumaticsModuleType.h>
#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix6/TalonFX.hpp>

#include "Constants.h"

class Climber : public frc2::SubsystemBase {
 public:
  Climber();

  void SetClimberPower(double power);
  void ExtendClimbBrake(void);
  void RetractClimbBrake(void);

  bool GetTopClimberLimit(void);
  bool GetBotClimberLimit(void);

  void Periodic() override;

 private:
  ctre::phoenix6::hardware::TalonFX m_leftClimberMotor = ctre::phoenix6::hardware::TalonFX(CLIMBER_LEFT_CANID , "rio");

  ctre::phoenix6::hardware::TalonFX m_rightClimberMotor = ctre::phoenix6::hardware::TalonFX(CLIMBER_RIGHT_CANID , "rio");

  frc::DigitalInput m_topLimitSwitch{CLIMBER_TOP_LIMIT};
  frc::DigitalInput m_botLimitSwitch{CLIMBER_BOT_LIMIT};

  frc::DoubleSolenoid m_climbBrake{PCM_CANID, frc::PneumaticsModuleType::REVPH, CLIMBER_BRAKE_ENGAGE_PCM, CLIMBER_BRAKE_DISENGAGE_PCM};
};
