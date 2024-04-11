#include "subsystems/Shooter.h"

Shooter::Shooter() = default;

//*******************GETS********************

void Shooter::SetShooterPower(double power)
{
    m_upperShooterMotor.Set(power);
    m_lowerShooterMotor.Set(power);
}

void Shooter::SetShooterRPM(double speed)
{
    //idk i'll figure out speed control later
}

void Shooter::SetPivotAngle(units::angle::turn_t angle)
{
    m_leftPivotMotor.SetPosition(angle, m_pivotTimeout);
    m_rightPivotMotor.SetPosition(angle, m_pivotTimeout);
}

void Shooter::SetPivotPower(double power)
{
    m_leftPivotMotor.Set(power);
    m_rightPivotMotor.Set(power);
}

void Shooter::SetAmpAngle(units::angle::turn_t angle)
{
    m_ampMotor.SetPosition(angle, m_pivotTimeout);
}

void Shooter::SetAmpPower(double power)
{
    m_ampMotor.Set(power);
}

//*******************SETS********************

double Shooter::GetShooterRPM(void)
{
    //idk i'll figure out speed control later
    return 0;
}

ctre::phoenix6::StatusSignal<units::angle::turn_t> Shooter::GetPivotAngle(void)
{
    return m_leftPivotMotor.GetPosition();
}

ctre::phoenix6::StatusSignal<units::angle::turn_t> Shooter::GetAmpAngle(void)
{
    return m_ampMotor.GetPosition();
}

void Shooter::Periodic() {}
