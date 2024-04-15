// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Climber.h"

Climber::Climber() = default;

void Climber::SetClimberPower(double power)
{
    m_leftClimberMotor.Set(power);
    m_rightClimberMotor.Set(power);
}

void Climber::ExtendClimbBrake(void)
{
    m_climbBrake.kForward;
}

void Climber::RetractClimbBrake(void)
{
    m_climbBrake.kReverse;
}

bool Climber::GetBotClimberLimit(void)
{
    m_botLimitSwitch.Get();
}

bool Climber::GetTopClimberLimit(void)
{
    m_topLimitSwitch.Get();
}

// This method will be called once per scheduler run
void Climber::Periodic() {}
