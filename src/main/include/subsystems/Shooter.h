// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix6/TalonFX.hpp>
#include <units/time.h>
#include <units/angle.h>

#include "Constants.h"

class Shooter : public frc2::SubsystemBase {
 public:
  Shooter();

  void ShooterInit(void);

  //sets
  void SetShooterPower(double power);
  void SetShooterTPS(units::angular_velocity::turns_per_second_t speed);

  void SetPivotAngle(units::angle::turn_t angle);
  void SetPivotPower(double power);
  
  void SetAmpAngle(units::angle::turn_t angle);
  void SetAmpPower(double power);

  //gets
  ctre::phoenix6::StatusSignal<units::angular_velocity::turns_per_second_t> GetShooterTPS(void);

  ctre::phoenix6::StatusSignal<units::angle::turn_t> GetPivotAngle(void);

  ctre::phoenix6::StatusSignal<units::angle::turn_t> GetAmpAngle(void);

  void Periodic() override;

 private:

  units::second_t m_pivotTimeout = 5_s;

  ctre::phoenix6::hardware::TalonFX m_upperShooterMotor = ctre::phoenix6::hardware::TalonFX(SHOOTER_UPPER_CANID , "rio");

  ctre::phoenix6::hardware::TalonFX m_lowerShooterMotor = ctre::phoenix6::hardware::TalonFX(SHOOTER_LOWER_CANID , "rio");

  ctre::phoenix6::hardware::TalonFX m_leftPivotMotor = ctre::phoenix6::hardware::TalonFX(LEFT_PIVOT_CANID , "rio");

  ctre::phoenix6::hardware::TalonFX m_rightPivotMotor = ctre::phoenix6::hardware::TalonFX(RIGHT_PIVOT_CANID , "rio");

  ctre::phoenix6::hardware::TalonFX m_ampMotor = ctre::phoenix6::hardware::TalonFX(AMP_MOTOR_CANID , "rio");

};
