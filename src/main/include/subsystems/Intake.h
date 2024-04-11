// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <units/angle.h>
#include <units/time.h>
#include <ctre/phoenix6/TalonFX.hpp>
#include <frc/DigitalInput.h>

#include "Constants.h"

class Intake : public frc2::SubsystemBase {
 public:
  Intake();

  //sets
  void SetIntakeAngle(units::angle::turn_t angle);
  void SetIntakePower(double power);

  //gets
  ctre::phoenix6::StatusSignal<units::angle::turn_t> GetIntakeAngle(void);
  bool GetIntakePhotoeye(void);

  void Periodic() override;

 private:
  units::second_t m_pivotTimeout = 5_s;

  ctre::phoenix6::hardware::TalonFX m_leftIntakeMotor = ctre::phoenix6::hardware::TalonFX(INTAKE_LEFT_CANID , "rio");

  ctre::phoenix6::hardware::TalonFX m_rightIntakeMotor = ctre::phoenix6::hardware::TalonFX(INTAKE_RIGHT_CANID , "rio");

  ctre::phoenix6::hardware::TalonFX m_powerIntakeMotor = ctre::phoenix6::hardware::TalonFX(INTAKE_POWER_CANID , "rio");

  frc::DigitalInput m_intakePhotoeye{INTAKE_PHOTOEYE};
  
};
