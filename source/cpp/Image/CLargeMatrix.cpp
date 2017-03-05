
// Std
#include "math.h"

// Library
#include "CLargeMatrix.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CLargeMatrix
    \inmodule qt-plus
    \brief A class that stores a NxN matrix.
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs an empty CLargeMatrix.
*/
CLargeMatrix::CLargeMatrix()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CLargeMatrix.
*/
CLargeMatrix::~CLargeMatrix()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the number of columns to \a width and the number of rows to \a height.
*/
void CLargeMatrix::setSize(int width, int height)
{
    m_vData.clear();

    for (int row = 0; row < height; row++)
    {
        m_vData << QVector<double>();

        for (int column = 0; column < width; column++)
        {
            m_vData[row] << 0.0;
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the value at \a row and \a column to \a value.
*/
void CLargeMatrix::setValue(int row, int column, double value)
{
    if (row >= 0 && row < m_vData.count())
    {
        if (column >= 0 && column < m_vData[row].count())
        {
            m_vData[row][column] = value;
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the number of columns.
*/
int CLargeMatrix::width() const
{
    if (m_vData.count() > 0)
    {
        return m_vData[0].count();
    }

    return 0;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the number of rows.
*/
int CLargeMatrix::height() const
{
    return m_vData.count();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the data as a vector of vector of doubles.
*/
QVector<QVector<double > >& CLargeMatrix::data()
{
    return m_vData;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the data as a constant vector of vector of doubles.
*/
const QVector<QVector<double > >& CLargeMatrix::data() const
{
    return m_vData;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a reference to the row at \a index.
*/
QVector<double >& CLargeMatrix::row(int index)
{
    if (index >= 0 && index < m_vData.count())
    {
        return m_vData[index];
    }

    return m_vDummyRow;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a constant reference to the row at \a index.
*/
const QVector<double >& CLargeMatrix::row(int index) const
{
    if (index >= 0 && index < m_vData.count())
    {
        return m_vData[index];
    }

    return m_vDummyRow;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the value at \a row and \a column.
*/
double CLargeMatrix::valueAt(int row, int column) const
{
    if (row >= 0 && row < m_vData.count())
    {
        if (column >= 0 && column < m_vData[row].count())
        {
            return m_vData[row][column];
        }
    }

    return 0.0;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a blurring matrix using \a dRadius.
*/
CLargeMatrix CLargeMatrix::blurMatrix(double dRadius)
{
    CLargeMatrix matrix;

    if (dRadius > 0.0)
    {
        int size = (int) (dRadius * 2.0);

        if (size == 0) size++;

        if ((size & 1) == 0)
        {
            size++;
        }

        matrix.setSize(size, size);

        double dMaxDistance = (double)sqrt(dRadius * dRadius + dRadius * dRadius);
        double dTotal = 0.0;

        for (int column = 0; column < size; column++)
        {
            for (int row = 0; row < size; row++)
            {
                double dDistanceX = fabs(column - dRadius);
                double dDistanceY = fabs(row - dRadius);
                double dFactor = sqrt(dDistanceX * dDistanceX + dDistanceY * dDistanceY);
                dFactor = (1.0 - (dFactor / dMaxDistance));
                dTotal += dFactor;

                matrix.setValue(row, column, dFactor);
            }
        }

        for (int column = 0; column < size; column++)
        {
            for (int row = 0; row < size; row++)
            {
                matrix.setValue(row, column, matrix.valueAt(row, column) / dTotal);
            }
        }
    }

    return matrix;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a dilate matrix.
*/
CLargeMatrix CLargeMatrix::dilateMatrix()
{
    CLargeMatrix matrix;
    int size = 3;

    matrix.setSize(size, size);

    matrix.row(0)[0] = 0;
    matrix.row(0)[1] = 1;
    matrix.row(0)[2] = 0;

    matrix.row(1)[0] = 1;
    matrix.row(1)[1] = 1;
    matrix.row(1)[2] = 1;

    matrix.row(2)[0] = 0;
    matrix.row(2)[1] = 1;
    matrix.row(2)[2] = 0;

    return matrix;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns an erode matrix.
*/
CLargeMatrix CLargeMatrix::erosionMatrix()
{
    CLargeMatrix matrix;
    int size = 3;

    matrix.setSize(size, size);

    matrix.row(0)[0] = 1;
    matrix.row(0)[1] = 0;
    matrix.row(0)[2] = 1;

    matrix.row(1)[0] = 0;
    matrix.row(1)[1] = 0;
    matrix.row(1)[2] = 0;

    matrix.row(2)[0] = 1;
    matrix.row(2)[1] = 0;
    matrix.row(2)[2] = 1;

    return matrix;
}
