
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
    // Classes imbriquées
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

        double	dInput;
        T		tOutput;
    };

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    //-------------------------------------------------------------------------------------------------

    //! Constructeur par défaut
    CInterpolator()
    {
    }

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Retourne le nombre de valeurs
    int count() { return m_vValues.count(); }

    //! Retourne le vecteur de valeurs
    QVector<InterpolatorValue>& getValues() { return m_vValues; }

    //-------------------------------------------------------------------------------------------------
    // Méthodes de contrôle
    //-------------------------------------------------------------------------------------------------

    //! Ajoute un pas d'interpolation
    //! Une valeur double donnée est associée une valeur T
    void addValue(double input, T output)
    {
        m_vValues.append(InterpolatorValue(input, output));
    }

    //! Retourne la valeur T correspondant à la valeur double d'entrée
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
    // Propriétés
    //-------------------------------------------------------------------------------------------------

protected:

    QVector<InterpolatorValue>	m_vValues;
};
