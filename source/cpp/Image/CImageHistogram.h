
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QImage>
#include <QColor>
#include <QVector>

//-------------------------------------------------------------------------------------------------

//! Classe utilitaire de traitement d'images
//! Utility class for image processing
class QTPLUSSHARED_EXPORT CImageHistogram
{
public:

    enum EOperateOn
    {
        eRGB,
        eHSV
    };

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //!
    CImageHistogram(const QImage& imgSource, EOperateOn eOperateOn = eRGB, int iSamples = 256, double dMinimumSaturation = 0.1);

    //!
    virtual ~CImageHistogram();

    //-------------------------------------------------------------------------------------------------
    // M�thodes de contr�le
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    QVector<double>& channel(int channel);

    //!
    double peak(int channel) const;

    //-------------------------------------------------------------------------------------------------
    // M�thodes priv�es
    // Private methods
    //-------------------------------------------------------------------------------------------------

private:

    //!
    bool validChannel(int channel) const;

    //-------------------------------------------------------------------------------------------------
    // Propri�t�s
    //-------------------------------------------------------------------------------------------------

protected:

    int                         m_iSamples;
    QVector<QVector<double> >   m_vHistogram;       // First dimension is channel
};
