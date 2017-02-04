
// Application
#include "CPIDController.h"

using namespace CarEmulator;

//-------------------------------------------------------------------------------------------------

CPIDController::CPIDController(double dNewProportional, double dNewIntegral, double dNewDerivative)
{
	m_dProportionalConstant = dNewProportional;
	m_dIntegralConstant = dNewIntegral;
	m_dDerivativeConstant = dNewDerivative;

	reset();
}

//-------------------------------------------------------------------------------------------------

CPIDController::~CPIDController()
{
}

//-------------------------------------------------------------------------------------------------

void CPIDController::reset()
{
	m_dSetPoint = 0.0;
	m_dError = 0.0;
	m_dPreviousError = 0.0;
	m_dIntegral = 0.0;
	m_dDerivative = 0.0;
	m_dOutput = 0.0;
}

//-------------------------------------------------------------------------------------------------

void CPIDController::update(double CurrentValue, double DeltaTimeMillis)
{
	// Calculate the difference between the desired value and the actual value
	m_dError = m_dSetPoint - CurrentValue;

	// Track error over time, scaled to the timer interval
	m_dIntegral = m_dIntegral + (m_dError * DeltaTimeMillis);

	// Determine the amount of change from the last time checked
	m_dDerivative = (m_dError - m_dPreviousError) / DeltaTimeMillis;

	// Calculate how much drive the output in order to get to the desired setpoint. 
	m_dOutput = (m_dProportionalConstant * m_dError) + (m_dIntegralConstant * m_dIntegral) + (m_dDerivativeConstant * m_dDerivative);

	// Remember the error for the next time around
	m_dPreviousError = m_dError;
}
