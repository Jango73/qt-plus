
#pragma once

#include "../qtplus_global.h"

// Library
#include "../CSingleton.h"
#include "CLargeMatrix.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QImage>
#include <QColor>

//-------------------------------------------------------------------------------------------------

//! Image processing utility class
//! Utility class for image processing
class QTPLUSSHARED_EXPORT CImageUtilities : public CSingleton<CImageUtilities>
{
    friend class CSingleton<CImageUtilities>;

public:

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    void removeIsolatedWhites(QImage& image);

    //! Applies a filter matrix to an image
    void applyFilterMatrix(QImage& image, const CLargeMatrix& matrix);

    //! Selects the pixels in an image according to a given hue
    void tintSelection(const QImage& imgSource, QImage& imgSelection, const QColor& cTint, double dHueTolerance, double dSatTolerance, double dValTolerance, double dSmoothRadius);

    //! Ajuste les valeurs HSV d'une image (addition)
    //! Adjusts the HSV values of an image (addition)
    void adjustHSV(QImage& imgSource, const QImage& imgSelection, double dHue, double dSat, double dVal);

    //! Ajuste les valeurs HSV d'une image (addition)
    //! Adjusts the HSV values of an image (addition)
    void colorize(QImage& imgSource, const QImage& imgSelection, const QColor& cReferenceColor, bool bKeepOriginalSaturation, bool bKeepOriginalValue);

    //! Splits an image's RGBA channels
    void splitRGBAChannels(const QImage& imgSource, QImage& imgRed, QImage& imgGreen, QImage& imgBlue, QImage& imgAlpha);

    //! Merges an image's RGBA channels
    void mergeRGBAChannels(const QImage& imgRed, const QImage& imgGreen, const QImage& imgBlue, const QImage& imgAlpha, QImage& imgTarget);

    //! Splits an image's HSVA channels
    void splitHSVAChannels(const QImage& imgSource, QImage& imgHue, QImage& imgSat, QImage& imgVal, QImage& imgAlpha);

    //! Merges an image's HSVA channels
    void mergeHSVAChannels(const QImage& imgHue, const QImage& imgSat, const QImage& imgVal, const QImage& imgAlpha, QImage& imgTarget);

    //! Finds the dominant hue of an image
    //! Find an image's dominant hue
    double findDominantHue(const QImage& imgSource, double dPrecision, double dMinimumSaturation = 0.1);

    //! Finds the dominant luminance of an image
    //! Find an image's dominant value (luminosity)
    double findDominantValue(const QImage& imgSource, double dPrecision);

    //! Converts an image to a ByteArray
    //! Converts an image to bytearray
    QByteArray convertQImageToByteArray(const QImage& image, const char* szFormat, int compressionRate);

    //! Converts a ByteArray to an image
    //! Converts a bytearray to an image
    QImage convertByteArrayToQImage(const QByteArray& baData, const char* szFormat);

    //! Converts an image to gray levels, in a QByteArray
    //! Converts an image to grayscale in a QByteArray
    QByteArray grayscale(const QImage& image);

    //! Computes the disparity map (depth) between two gray level images
    //! Computes the disparity map (depth) between two grayscale images
    QByteArray disparityMap(const QByteArray& baLeft, const QByteArray& baRight, int imageWidth, int imageHeight, int grayMax);
};
