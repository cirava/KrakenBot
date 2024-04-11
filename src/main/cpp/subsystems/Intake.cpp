#include "subsystems/Intake.h"

Intake::Intake() = default;

void Intake::Periodic() {}

void Intake::SetIntakeAngle(units::angle::turn_t angle)
{
    m_leftIntakeMotor.SetPosition(angle, m_pivotTimeout);
    m_rightIntakeMotor.SetPosition(angle, m_pivotTimeout);
}

void Intake::SetIntakePower(double power)
{
    m_powerIntakeMotor.Set(power);
}

ctre::phoenix6::StatusSignal<units::angle::turn_t> Intake::GetIntakeAngle(void)
{
    return m_leftIntakeMotor.GetPosition();
}

bool Intake::GetIntakePhotoeye(void)
{
    return m_intakePhotoeye.Get();
}
