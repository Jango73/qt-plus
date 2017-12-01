// Qt
#include <QDebug>

// Library
#include "CImageHistogram.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CImageHistogram
    \inmodule qt-plus
    \brief Stores the histogram of an image as real numbers for 4 channels.
*/

/*!
    \enum CImageHistogram::EOperateOn
    Used by constructor to specify on which components to operate (RGB or HSV).

    \value eRGB
    This indicates the red-green-blue color space.

    \value eHSV
    This indicates the hue-saturation-value color space.
*/

/*!
    \enum CImageHistogram::ERGBComponent
    Used by methods to specify a RGBA channel.

    \value eRed
    This indicates the red channel.

    \value eGreen
    This indicates the green channel.

    \value eBlue
    This indicates the blue channel.

    \value eAlpha
    This indicates the alpha channel.
*/

/*!
    \enum CImageHistogram::EHSVComponent
    Used by methods to specify a HSV channel.

    \value eHue
    This indicates the hue channel.

    \value eSaturation
    This indicates the saturation channel.

    \value eValue
    This indicates the value channel.
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CImageHistogram. \br\br
    \a imgSource is the image to process. \br
    \a eOperateOn specifies on which components to operate (RGB or HSV). \br
    \a iSamples is number of samples in the histogram. The higher, the more precise the histogram.
    \a dMinimumSaturation indicates the minimum value of pixel saturation in order to take hue into account.
*/
CImageHistogram::CImageHistogram(const QImage &imgSource, EOperateOn eOperateOn, int iSamples, double dMinimumSaturation)
{
    qreal r, g, b, a;
    qreal h, s, v;
    int where;

    if (iSamples < 16)
        iSamples = 16;

    if (iSamples > 1024)
        iSamples = 1024;

    m_iSamples = iSamples;

    // Create 4 channels

    m_vHistogram.append(QVector<int>());
    m_vHistogram.append(QVector<int>());
    m_vHistogram.append(QVector<int>());
    m_vHistogram.append(QVector<int>());

    // Create initial channel values

    for (int index = 0; index < m_iSamples; index++)
    {
        m_vHistogram[eRed].append(0);
        m_vHistogram[eGreen].append(0);
        m_vHistogram[eBlue].append(0);
        m_vHistogram[eAlpha].append(0);
    }

    // Iterate on pixels

    for (int y = 0; y < imgSource.height(); y++)
    {
        for (int x = 0; x < imgSource.width(); x++)
        {
            QRgb currentPixel = imgSource.pixel(x, y);
            QColor currentColor(currentPixel);
            a = currentColor.alphaF();

            switch (eOperateOn)
            {
                case eRGB:
                {
                    r = currentColor.redF();
                    g = currentColor.greenF();
                    b = currentColor.blueF();

                    where = (int) (r * (qreal) (m_iSamples - 1));
                    where = qBound(0, where, m_iSamples - 1);
                    m_vHistogram[eRed][where]++;

                    where = (int) (g * (qreal) (m_iSamples - 1));
                    where = qBound(0, where, m_iSamples - 1);
                    m_vHistogram[eGreen][where]++;

                    where = (int) (b * (qreal) (m_iSamples - 1));
                    where = qBound(0, where, m_iSamples - 1);
                    m_vHistogram[eBlue][where]++;

                    break;
                }

                case eHSV:
                {
                    currentColor.getHsvF(&h, &s, &v);

                    if (s >= dMinimumSaturation)
                    {
                        where = (int) (h * (qreal) (m_iSamples - 1));
                        where = qBound(0, where, m_iSamples - 1);
                        m_vHistogram[eHue][where]++;

                        where = (int) (s * (qreal) (m_iSamples - 1));
                        where = qBound(0, where, m_iSamples - 1);
                        m_vHistogram[eSaturation][where]++;
                    }

                    where = (int) (v * (qreal) (m_iSamples - 1));
                    where = qBound(0, where, m_iSamples - 1);
                    m_vHistogram[eValue][where]++;

                    break;
                }

                where = (int) (a * (qreal) (m_iSamples - 1));
                where = qBound(0, where, m_iSamples - 1);
                m_vHistogram[eAlpha][where]++;
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CImageHistogram.
*/
CImageHistogram::~CImageHistogram()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the number of samples.
*/
int CImageHistogram::sampleCount() const
{
    return m_iSamples;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a vector of integers for \a channel.
*/
QVector<int>& CImageHistogram::channel(int channel)
{
    if (validChannel(channel))
    {
        return m_vHistogram[channel];
    }

    return m_vHistogram[0];
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the normalized peak along the x axis of \a channel. \br\br
    \a pRadius, if not null, will contain the normalized radius which contains values > 0 around the peak
*/
double CImageHistogram::peak(int channel, double* pRadius) const
{
    if (pRadius != nullptr)
    {
        *pRadius = 0.0;
    }

    if (validChannel(channel))
    {
        int iPeak = 0;
        int iPeakIndex = -1;

        for (int index = 0; index < m_iSamples; index++)
        {
            int iStoredValue = m_vHistogram[channel][index];

            if (iStoredValue > iPeak)
            {
                iPeak = iStoredValue;
                iPeakIndex = index;
            }
        }

        if (iPeakIndex != -1)
        {
            if (pRadius != nullptr)
            {
                int iPeakStartIndex = iPeakIndex;
                int iPeakEndIndex = iPeakIndex;

                for (int index = iPeakIndex - 1; index > 0; index--)
                {
                    int iStoredValue = m_vHistogram[channel][index];

                    if (iStoredValue == 0)
                        break;

                    iPeakStartIndex = index;
                }

                for (int index = iPeakIndex + 1; index < m_iSamples; index++)
                {
                    int iStoredValue = m_vHistogram[channel][index];

                    if (iStoredValue == 0)
                        break;

                    iPeakEndIndex = index;
                }

                *pRadius = (double) (iPeakEndIndex - iPeakStartIndex) / (double) m_iSamples;
            }

            return (double) iPeakIndex / (double) m_iSamples;
        }
        else
        {
            // qDebug() << "iPeakIndex != -1 is false";
        }
    }

    return 0.0;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the peak along the y axis of \a channel (ie the number of pixels using the peak value). \br\br
*/
int CImageHistogram::peakValue(int channel) const
{
    if (validChannel(channel))
    {
        int iPeak = 0;

        for (int index = 0; index < m_iSamples; index++)
        {
            int iStoredValue = m_vHistogram[channel][index];

            if (iStoredValue > iPeak)
            {
                iPeak = iStoredValue;
            }
        }

        return iPeak;
    }

    return 0;
}

//-------------------------------------------------------------------------------------------------

bool CImageHistogram::validChannel(int channel) const
{
    if (channel < 0)
        return false;

    if (channel > m_vHistogram.count() - 1)
        return false;

    return true;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns true if the sample number \a iSample is the only one containing a value greater than \a dTolerance. \br\br
    \a iChannel is the channel on which to operate \br
    \a iSpan widens the range of \a iSample : if equal to 2, the logic for \a iSample will also be applied to \a iSample - 2, \a iSample - 1, \a iSample + 1, \a iSample + 2
*/
bool CImageHistogram::isSampleExclusive(int iChannel, int iSample, int iSpan, double dTolerance) const
{
    if (validChannel(iChannel))
    {
        for (int index = 0; index < m_iSamples; index++)
        {
            if (index >= iSample - iSpan && index <= iSample + iSpan)
            {
                if (m_vHistogram[iChannel][index] <= dTolerance)
                    return false;
            }
            else
            {
                if (m_vHistogram[iChannel][index] > dTolerance)
                    return false;
            }
        }
    }

    return true;
}
