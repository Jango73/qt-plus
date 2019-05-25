
#pragma once

// Qt
#include <QVector>

//-------------------------------------------------------------------------------------------------

template <class T>
class CAverager
{
public:

    //! Default constructor
    CAverager(int iMaxValues = 5)
        : m_iMaxValues(iMaxValues)
    {
    }

    //! Destructor
    virtual ~CAverager()
    {
    }

    //! Adds a value
    CAverager<T>& operator << (const T& value)
    {
        append(value);
        return *this;
    }

    //! Resets all values
    void reset()
    {
        m_mValues.clear();
    }

    //! Adds a value
    void append(const T& value)
    {
        m_mValues.append(value);

        if (m_mValues.count() > m_iMaxValues)
        {
            m_mValues.remove(0);
        }
    }

    //! Returns average of all values
    T getAverage() const
    {
        if (m_mValues.count() == 0)
        {
            return T(0);
        }

        T returnValue = T(0);

        for (T iterValue : m_mValues)
        {
            returnValue += iterValue;
        }

        return returnValue / T(m_mValues.count());
    }

protected:

    int         m_iMaxValues;           // Maximum number of values
    QVector<T>  m_mValues;              // Values to average
};

//-------------------------------------------------------------------------------------------------

template <class T>
class CRollingAverager
{
public:

    //! Default constructor
    CRollingAverager(int numSamples)
        : m_iNumSamples(numSamples)
        , m_tAverage(T(0))
    {
    }

    //! Destructor
    virtual ~CRollingAverager()
    {
    }

    //! Adds a value
    CAverager<T>& operator << (const T& value)
    {
        append(value);
        return *this;
    }

    //! Resets all values
    void reset()
    {
        m_tAverage = T(0);
    }

    //! Adds a value
    void append(const T& value)
    {
        m_tAverage -= m_tAverage / m_iNumSamples;
        m_tAverage += value / m_iNumSamples;
    }

    //! Returns average of all values
    T getAverage() const
    {
        return m_tAverage;
    }

protected:

    int     m_iNumSamples;
    T       m_tAverage;
};
