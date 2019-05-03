
#pragma once

#include "qtplus_global.h"

//-------------------------------------------------------------------------------------------------

class QTPLUSSHARED_EXPORT CPIDController
{
public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    CPIDController(double dNewProportional, double dNewIntegral, double dNewDerivative);

    //! Destructor
    virtual ~CPIDController();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //! Defines the set point (the value to reach)
    void setSetPoint(double value) { m_dSetPoint = value; }

    //! Defines the proportional factor
    void setProportionalConstant(double value) { m_dProportionalConstant = value; }

    //! Defines the integral factor
    void setIntegralConstant(double value) { m_dIntegralConstant = value; }

    //! Defines the derivative factor
    void setDerivativeConstant(double value) { m_dDerivativeConstant = value; }

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Returns the set point (the value to reach)
    double setPoint() const { return m_dSetPoint; }

    //! Returns the proportional factor
    double proportionalConstant() const { return m_dProportionalConstant; }

    //! Returns the integral factor
    double integralConstant() const { return m_dIntegralConstant; }

    //! Returns the derivative factor
    double derivativeConstant() const { return m_dDerivativeConstant; }

    //! Returns the output value
    double output() const { return m_dOutput; }

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Resets the controller
    void reset();

    //! Updates the controller
    void update(double dCurrentValue, double dDeltaTimeMillis);

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    double m_dSetPoint;
    double m_dError;
    double m_dPreviousError;
    double m_dIntegral;
    double m_dDerivative;
    double m_dProportionalConstant;
    double m_dIntegralConstant;
    double m_dDerivativeConstant;
    double m_dOutput;
};
