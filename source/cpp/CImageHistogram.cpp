
// Library
#include "CImageHistogram.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CImageHistogram
    \inmodule qt-plus
    \brief Stores the histogram of an image as real numbers for 3 channels.
*/

/*!
    \enum CImageHistogram::EOperateOn
    Used by constructor to specify on which components to operate (RGB or HSV).

    \value eRGB
    This indicates the red-green-blue color space.

    \value eHSV
    This indicates the hue-saturation-value color space.

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
    qreal r, g, b;
    qreal h, s, v;
    int where;

    if (iSamples < 16)
        iSamples = 16;

    if (iSamples > 1024)
        iSamples = 1024;

    m_iSamples = iSamples;

    // Create 3 channels

    m_vHistogram.append(QVector<double>());
    m_vHistogram.append(QVector<double>());
    m_vHistogram.append(QVector<double>());

    // Create initial channel values

    for (int index = 0; index < m_iSamples; index++)
    {
        m_vHistogram[0].append(0);
        m_vHistogram[1].append(0);
        m_vHistogram[2].append(0);
    }

    // Iterate on pixels

    for (int y = 0; y < imgSource.height(); y++)
    {
        for (int x = 0; x < imgSource.width(); x++)
        {
            QRgb currentPixel = imgSource.pixel(x, y);
            QColor currentColor(currentPixel);

            switch (eOperateOn)
            {
                case eRGB:
                {
                    r = currentColor.redF();
                    g = currentColor.greenF();
                    b = currentColor.blueF();

                    where = (int) (r * (qreal) (m_iSamples - 1));
                    where = qBound(0, where, m_iSamples - 1);
                    m_vHistogram[0][where]++;

                    where = (int) (g * (qreal) (m_iSamples - 1));
                    where = qBound(0, where, m_iSamples - 1);
                    m_vHistogram[1][where]++;

                    where = (int) (b * (qreal) (m_iSamples - 1));
                    where = qBound(0, where, m_iSamples - 1);
                    m_vHistogram[2][where]++;

                    break;
                }

                case eHSV:
                {
                    currentColor.getHsvF(&h, &s, &v);

                    if (s >= dMinimumSaturation)
                    {
                        where = (int) (h * (qreal) (m_iSamples - 1));
                        where = qBound(0, where, m_iSamples - 1);
                        m_vHistogram[0][where]++;

                        where = (int) (s * (qreal) (m_iSamples - 1));
                        where = qBound(0, where, m_iSamples - 1);
                        m_vHistogram[1][where]++;
                    }

                    where = (int) (v * (qreal) (m_iSamples - 1));
                    where = qBound(0, where, m_iSamples - 1);
                    m_vHistogram[2][where]++;

                    break;
                }
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
    Returns a vector of doubles for \a channel.
*/
QVector<double>& CImageHistogram::channel(int channel)
{
    if (validChannel(channel))
    {
        return m_vHistogram[channel];
    }

    return m_vHistogram[0];
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the peak value of \a channel.
*/
double CImageHistogram::peak(int channel) const
{
    if (validChannel(channel))
    {
        double dPeak = 0.0;
        int dPeakIndex = 0;

        for (int index = 0; index < m_iSamples; index++)
        {
            double dStoredValue = m_vHistogram[channel][index];

            if (dStoredValue > dPeak)
            {
                dPeak = dStoredValue;
                dPeakIndex = index;
            }
        }

        return (double) dPeakIndex / (double) (m_iSamples - 1);
    }

    return 0.0;
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
