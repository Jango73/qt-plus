
#pragma once

// Std
#include "math.h"

// Qt
#include <QVector>

//-------------------------------------------------------------------------------------------------

template <class T>
class CInterpolator
{
public:

    //-------------------------------------------------------------------------------------------------
    // Inner classes
    //-------------------------------------------------------------------------------------------------

    class InterpolatorValue
    {
    public:

        InterpolatorValue()
        {
            dInput = 0.0;
        }

        InterpolatorValue(double NewInput, T NewOutput)
        {
            dInput = NewInput;
            tOutput = NewOutput;
        }

        double  dInput;
        T       tOutput;
    };

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    CInterpolator()
    {
    }

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Returns the number of values
    int count() { return m_vValues.count(); }

    //! Returns the vector of values
    QVector<InterpolatorValue>& getValues() { return m_vValues; }

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    void clear()
    {
        m_vValues.clear();
    }

    //! Adds an interpolation step
    //! An input value of type double yields an output value of type T
    void addValue(double input, T output)
    {
        m_vValues.append(InterpolatorValue(input, output));
    }

    //! Returns the T type value for the input value
    T getValue(double input)
    {
        T output = T();

        if (m_vValues.count() == 0) return output;

        if (input < m_vValues[0].dInput) input = m_vValues[0].dInput;
        if (input > m_vValues[m_vValues.count() - 1].dInput) input = m_vValues[m_vValues.count() - 1].dInput;

        for (int iIndex = 0; iIndex < m_vValues.count(); iIndex++)
        {
            if (input >= m_vValues[iIndex].dInput)
            {
                if (iIndex < m_vValues.count() - 1)
                {
                    if (input <= m_vValues[iIndex + 1].dInput)
                    {
                        double input1 = m_vValues[iIndex + 0].dInput;
                        double input2 = m_vValues[iIndex + 1].dInput;
                        double inputRange = input2 - input1;

                        T output1 = m_vValues[iIndex + 0].tOutput;
                        T output2 = m_vValues[iIndex + 1].tOutput;
                        T outputRange = output2 - output1;

                        double factor = (input - input1) / inputRange;
                        output = output1 + (outputRange * factor);

                        break;
                    }
                }
                else
                {
                    output = m_vValues[iIndex].tOutput;
                }
            }
        }

        return output;
    }

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QVector<InterpolatorValue>  m_vValues;
};
