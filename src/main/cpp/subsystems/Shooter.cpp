#include "subsystems/Shooter.h"

Shooter::Shooter() = default;

//*******************SETS********************

void Shooter::ShooterInit(void)
{
    ctre::phoenix6::configs::Slot0Configs slot0configs{};

    slot0configs.kS = 0.1;
    slot0configs.kV = 0.12;
    slot0configs.kP = 0.11;
    slot0configs.kI = 0;
    slot0configs.kD = 0;

    m_lowerShooterMotor.GetConfigurator().Apply(slot0configs);
    m_upperShooterMotor.GetConfigurator().Apply(slot0configs);
}

void Shooter::SetShooterPower(double power)
{
    m_upperShooterMotor.Set(power);
    m_lowerShooterMotor.Set(power);
}

void Shooter::SetShooterTPS(units::angular_velocity::turns_per_second_t speed)
{
    ctre::phoenix6::controls::VelocityVoltage request = ctre::phoenix6::controls::VelocityVoltage{0_rpm}.WithSlot(0);

    m_lowerShooterMotor.SetControl(request.WithVelocity(speed));
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

//*******************GETS********************

ctre::phoenix6::StatusSignal<units::angular_velocity::turns_per_second_t> Shooter::GetShooterTPS(void)
{
    return m_lowerShooterMotor.GetVelocity();
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
