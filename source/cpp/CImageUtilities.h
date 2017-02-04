
#pragma once

#include "qtplus_global.h"

// Library
#include "CSingleton.h"
#include "CLargeMatrix.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QImage>
#include <QColor>

//-------------------------------------------------------------------------------------------------

//! Classe utilitaire de traitement d'images
//! Utility class for image processing
class QTPLUSSHARED_EXPORT CImageUtilities : public CSingleton<CImageUtilities>
{
    friend class CSingleton<CImageUtilities>;

public:

    //-------------------------------------------------------------------------------------------------
    // Méthodes de contrôle
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    void removeIsolatedWhites(QImage& image);

    //! Applique une matrice de filter à une image
    //! Applies a filter matrix to an image
    void applyFilterMatrix(QImage& image, const CLargeMatrix& matrix);

    //! Sélectionne les pixels dans une image selon une teinte donnée
    void tintSelection(const QImage& imgSource, QImage& imgSelection, const QColor& cTint, double dHueTolerance, double dSatTolerance, double dValTolerance, double dSmoothRadius);

    //! Ajuste les valeurs HSV d'une image (addition)
    //! Adjusts the HSV values of an image (addition)
    void adjustHSV(QImage& imgSource, const QImage& imgSelection, double dHue, double dSat, double dVal);

    //! Ajuste les valeurs HSV d'une image (addition)
    //! Adjusts the HSV values of an image (addition)
    void colorize(QImage& imgSource, const QImage& imgSelection, const QColor& cReferenceColor, bool bKeepOriginalSaturation, bool bKeepOriginalValue);

    //! Sépare les canaux RGBA d'une image
    //! Splits an image's RGBA channels
    void splitRGBAChannels(const QImage& imgSource, QImage& imgRed, QImage& imgGreen, QImage& imgBlue, QImage& imgAlpha);

    //! Fusionne les canaux RGBA d'une image
    //! Merges an image's RGBA channels
    void mergeRGBAChannels(const QImage& imgRed, const QImage& imgGreen, const QImage& imgBlue, const QImage& imgAlpha, QImage& imgTarget);

    //! Sépare les canaux HSVA d'une image
    //! Splits an image's HSVA channels
    void splitHSVAChannels(const QImage& imgSource, QImage& imgHue, QImage& imgSat, QImage& imgVal, QImage& imgAlpha);

    //! Fusionne les canaux HSVA d'une image
    //! Merges an image's HSVA channels
    void mergeHSVAChannels(const QImage& imgHue, const QImage& imgSat, const QImage& imgVal, const QImage& imgAlpha, QImage& imgTarget);

    //! Trouve la teinte dominante d'une image
    //! Find an image's dominant hue
    double findDominantHue(const QImage& imgSource, double dPrecision, double dMinimumSaturation = 0.1);

    //! Trouve la luminance dominante d'une image
    //! Find an image's dominant value (luminosity)
    double findDominantValue(const QImage& imgSource, double dPrecision);

    //! Convertit une image en ByteArray
    //! Converts an image to bytearray
    QByteArray convertQImageToByteArray(const QImage& image, const char* szFormat, int compressionRate);

    //! Convertit un ByteArray en image
    //! Converts a bytearray to an image
    QImage convertByteArrayToQImage(const QByteArray& baData, const char* szFormat);

    //! Convertit une image en niveaux de gris, dans un QByteArray
    //! Converts an image to grayscale in a QByteArray
    QByteArray grayscale(const QImage& image);

    //! Calcul la carte de disparité (profondeur) entre deux images en niveaux de gris
    //! Computes the disparity map (depth) between two grayscale images
    QByteArray disparityMap(const QByteArray& baLeft, const QByteArray& baRight, int imageWidth, int imageHeight, int grayMax);
};
