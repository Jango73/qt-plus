
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QImage>
#include <QColor>
#include <QVector>

//-------------------------------------------------------------------------------------------------

//! Image processing utility class
//! Utility class for image processing
class QTPLUSSHARED_EXPORT CImageHistogram
{
public:

    enum EOperateOn
    {
        eRGB,
        eHSV
    };

    enum ERGBComponent
    {
        eRed = 0,
        eGreen = 1,
        eBlue = 2,
        eAlpha = 3
    };

    enum EHSVComponent
    {
        eHue = 0,
        eSaturation = 1,
        eValue = 2
    };

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //!
    CImageHistogram(const QImage& imgSource, EOperateOn eOperateOn = eRGB, int iSamples = 256, double dMinimumSaturation = 0.1);

    //!
    virtual ~CImageHistogram();

    //-------------------------------------------------------------------------------------------------
    // Control methods
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    int sampleCount() const;

    //!
    QVector<int> &channel(int channel);

    //!
    double peak(int channel, double* pRadius = nullptr) const;

    //!
    int peakValue(int channel) const;

    //!
    bool isSampleExclusive(int iChannel, int iSample, int iSpan = 0, double dTolerance = 0.01) const;

    //-------------------------------------------------------------------------------------------------
    // Private methods
    // Private methods
    //-------------------------------------------------------------------------------------------------

private:

    //!
    bool validChannel(int channel) const;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    int                     m_iSamples;
    QVector<QVector<int> >  m_vHistogram;       // First dimension is channel
};
