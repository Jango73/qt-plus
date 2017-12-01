
// Std
#include "math.h"

// Qt
#include <QBuffer>

// Library
#include "CImageUtilities.h"
#include "CImageHistogram.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CImageUtilities
    \inmodule qt-plus
    \brief A singleton that provides image manipulation functions.
*/

//-------------------------------------------------------------------------------------------------

static double angleDifferenceGrad(double dAngle1, double dAngle2)
{
    double a = dAngle1 - dAngle2;
    a += (a > 0.5) ? -1.0 : (a < -0.5) ? 1.0 : 0.0;
    return a;
}

//-------------------------------------------------------------------------------------------------

/*!
    Removes isolated white pixels from \a image (sets them to black).
*/
void CImageUtilities::removeIsolatedWhites(QImage& image)
{
    QImage source = image.copy();
    qreal h1, s1, v1;
    qreal h2, s2, v2;

    for (int y = 0; y < image.height(); y++)
    {
        for (int x = 0; x < image.width(); x++)
        {
            QRgb currentPixel = source.pixel(x, y);
            QColor currentColor(currentPixel);
            currentColor.getHsvF(&h1, &s1, &v1);

            if (v1 > 0.5)
            {
                int iCount = 0;

                for (int y2 = -1 ; y2 < 2; y2++)
                {
                    for (int x2 = -1; x2 < 2; x2++)
                    {
                        int offsetX = x + x2;
                        int offsetY = y + y2;

                        if (offsetX > 0 && offsetX < image.width() && offsetY > 0 && offsetY < image.height())
                        {
                            QRgb otherPixel = source.pixel(offsetX, offsetY);
                            QColor otherColor(otherPixel);
                            otherColor.getHsvF(&h2, &s2, &v2);

                            if (v2 > 0.5)
                            {
                                iCount++;
                            }
                        }
                        else
                        {
                            iCount++;
                        }
                    }
                }

                if (iCount < 2)
                {
                    image.setPixel(x, y, QColor(Qt::black).rgba());
                }
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Applies a filter \a matrix to \a image. \br\br
    The filter matrix holds normalized values (0.0 -> 1.0) that will act as factors for the pixels in \a image. \br
    Please refer to documentation on image filters in order to learn how to fill them.
*/
void CImageUtilities::applyFilterMatrix(QImage& image, const CLargeMatrix& matrix)
{
    if (matrix.width() > 0 && matrix.height() > 0)
    {
        QImage source = image.copy();
        int matrixWidth =  matrix.width();
        int matrixHeight =  matrix.height();
        int halfMatrixWidth =  matrixWidth / 2;
        int halfMatrixHeight =  matrixHeight / 2;

        for (int currentY = 0; currentY < image.height(); currentY++)
        {
            for (int currentX = 0; currentX < image.width(); currentX++)
            {
                QRgb currentPixel = 0;
                QColor currentColor(currentPixel);

                double dCurrentR = (double) currentColor.red() / 255.0;
                double dCurrentG = (double) currentColor.green() / 255.0;
                double dCurrentB = (double) currentColor.blue() / 255.0;

                for (int matrixY = 0; matrixY < matrixHeight; matrixY++)
                {
                    for (int matrixX = 0; matrixX < matrixWidth; matrixX++)
                    {
                        int pixelOffsetX = (currentX - halfMatrixWidth) + matrixX;
                        int pixelOffsetY = (currentY - halfMatrixHeight) + matrixY;

                        if (
                                pixelOffsetX > 0 && pixelOffsetX < image.width() &&
                                pixelOffsetY > 0 && pixelOffsetY < image.height()
                                )
                        {
                            double dFactor = matrix.valueAt(matrixY, matrixX);

                            QRgb otherPixel = source.pixel(pixelOffsetX, pixelOffsetY);
                            QColor otherColor(otherPixel);

                            double dOtherR = (double) otherColor.red() / 255.0;
                            double dOtherG = (double) otherColor.green() / 255.0;
                            double dOtherB = (double) otherColor.blue() / 255.0;

                            dCurrentR = dCurrentR + dOtherR * dFactor;
                            dCurrentG = dCurrentG + dOtherG * dFactor;
                            dCurrentB = dCurrentB + dOtherB * dFactor;
                        }
                    }
                }

                if (dCurrentR < 0.0) dCurrentR = 0.0;
                if (dCurrentG < 0.0) dCurrentG = 0.0;
                if (dCurrentB < 0.0) dCurrentB = 0.0;

                if (dCurrentR > 1.0) dCurrentR = 1.0;
                if (dCurrentG > 1.0) dCurrentG = 1.0;
                if (dCurrentB > 1.0) dCurrentB = 1.0;

                currentColor.setRed((int)(dCurrentR * 255.0));
                currentColor.setGreen((int)(dCurrentG * 255.0));
                currentColor.setBlue((int)(dCurrentB * 255.0));

                image.setPixel(currentX, currentY, currentColor.rgba());
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Selects pixels by tint in an image. \br\br
    \a imgSource is the image to process. \br
    \a imgSelection is the image that will hold the selected pixels (full black or full white). \br
    \a cTint holds the hue, saturation and lightness to look for. \br
    \a dHueTolerance, \a dSatTolerance and \a dValTolerance are the tolerance values to use when comparing pixels. They range from 0.0 to 1.0. \br
    \a dSmoothRadius is currently unused.
*/
void CImageUtilities::tintSelection(const QImage& imgSource, QImage& imgSelection, const QColor& cTint, double dHueTolerance, double dSatTolerance, double dValTolerance, double dSmoothRadius)
{
    Q_UNUSED(dSmoothRadius);

    qreal h1, s1, v1;
    qreal h2, s2, v2;

    imgSelection = QImage(imgSelection.size(), QImage::Format_RGB888);

    cTint.getHsvF(&h1, &s1, &v1);

    for (int y = 0; y < imgSource.height(); y++)
    {
        for (int x = 0; x < imgSource.width(); x++)
        {
            QRgb currentPixel = imgSource.pixel(x, y);
            QColor currentColor(currentPixel);
            currentColor.getHsvF(&h2, &s2, &v2);

            double dHueDiff = fabs(angleDifferenceGrad(h1, h2)) * 2.0;
            double dSatDiff = fabs(s1 - s2);
            double dValDiff = fabs(v1 - v2);

            if (dHueDiff <= dHueTolerance && dSatDiff <= dSatTolerance && dValDiff <= dValTolerance)
            {
                imgSelection.setPixel(x, y, QColor(Qt::white).rgba());
            }
            else
            {
                imgSelection.setPixel(x, y, QColor(Qt::black).rgba());
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Adjusts hue, saturation and lightness in an image using (optionally) a selection image. \br\br
    \a imgSource is the image to process. \br
    \a imgSelection is the image to use as a selection mask. It must be the same size as \a imgSource, or it will be ignored. \br
    \a dHue, \a dSat and \a dVal are values to add to hue, saturation and lightness. They range from -1.0 to 1.0.
*/
void CImageUtilities::adjustHSV(QImage& imgSource, const QImage& imgSelection, double dHue, double dSat, double dVal)
{
    qreal h1, s1, v1;
    qreal h2, s2, v2;

    QImage alphaImage = imgSource.alphaChannel();

    bool bUseSelection = imgSelection.isNull() == false && imgSource.size() == imgSelection.size();

    for (int y = 0; y < imgSource.height(); y++)
    {
        for (int x = 0; x < imgSource.width(); x++)
        {
            QRgb currentPixel = imgSource.pixel(x, y);
            QColor currentColor(currentPixel);
            currentColor.getHsvF(&h1, &s1, &v1);
            double dFactor = 1.0;

            if (bUseSelection)
            {
                QRgb selectionPixel = imgSelection.pixel(x, y);
                QColor currentFactorColor(selectionPixel);
                currentFactorColor.getHsvF(&h2, &s2, &v2);
                dFactor = v2;
            }

            h1 = (h1 + dHue * dFactor);
            h1 = fmod(h1, 1.0);
            if (h1 < 0.0) h1 = 0.0;
            if (h1 > 1.0) h1 = 1.0;

            s1 = (s1 + dSat * dFactor);
            if (s1 < 0.0) s1 = 0.0;
            if (s1 > 1.0) s1 = 1.0;

            v1 = (v1 + dVal * dFactor);
            if (v1 < 0.0) v1 = 0.0;
            if (v1 > 1.0) v1 = 1.0;

            currentColor.setHsvF(h1, s1, v1);

            imgSource.setPixel(x, y, currentColor.rgba());
        }
    }

    if (alphaImage.isNull() == false)
    {
        imgSource.setAlphaChannel(alphaImage);
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Colorizes an image using a selection, a reference color. \br\br
    \a imgSource is the image to process. \br
    \a imgSelection is the image to use as a selection mask. It must be the same size as \a imgSource, or it will be ignored. \br
    \a cReferenceColor is the tint to apply. \br
    If \a bKeepOriginalSaturation is true, image saturation will remain unchanged. \br
    If \a bKeepOriginalValue is true, image luminance will remain unchanged. \br
*/
void CImageUtilities::colorize(QImage& imgSource, const QImage& imgSelection, const QColor& cReferenceColor, bool bKeepOriginalSaturation, bool bKeepOriginalValue)
{
    qreal h1, s1, v1;
    qreal h2, s2, v2;
    qreal h3, s3, v3;

    QImage alphaImage = imgSource.alphaChannel();

    cReferenceColor.getHsvF(&h1, &s1, &v1);

    bool bUseSelection = imgSelection.isNull() == false && imgSource.size() == imgSelection.size();

    for (int y = 0; y < imgSource.height(); y++)
    {
        for (int x = 0; x < imgSource.width(); x++)
        {
            QRgb currentPixel = imgSource.pixel(x, y);
            QColor currentColor(currentPixel);
            currentColor.getHsvF(&h2, &s2, &v2);

            double dFactor = 1.0;

            if (bUseSelection)
            {
                QRgb selectionPixel = imgSelection.pixel(x, y);
                QColor currentFactorColor(selectionPixel);
                currentFactorColor.getHsvF(&h3, &s3, &v3);
                dFactor = v3;
            }

            double dHueFactor = pow(dFactor, 3.0);
            h2 = (h1 * dHueFactor) + (h2 * (1.0 - dHueFactor));
            if (h2 < 0.0) h2 = 0.0;
            if (h2 > 1.0) h2 = 1.0;

            if (bKeepOriginalSaturation == false)
            {
                s2 = (s1 * dFactor) + (s2 * (1.0 - dFactor));
                if (s2 < 0.0) s2 = 0.0;
                if (s2 > 1.0) s2 = 1.0;
            }

            if (bKeepOriginalValue == false)
            {
                v2 = (v1 * dFactor) + (v2 * (1.0 - dFactor));
                if (v2 < 0.0) v2 = 0.0;
                if (v2 > 1.0) v2 = 1.0;
            }

            currentColor.setHsvF(h2, s2, v2);

            imgSource.setPixel(x, y, currentColor.rgba());
        }
    }

    if (alphaImage.isNull() == false)
    {
        imgSource.setAlphaChannel(alphaImage);
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Splits the different channels of an image. \br\br
    \a imgSource is the image to process. \br
    \a imgRed is the image that will contain the red channel. \br
    \a imgGreen is the image that will contain the green channel. \br
    \a imgBlue is the image that will contain the blue channel. \br
    \a imgAlpha is the image that will contain the alpha channel. \br
    \note All images must have the same size.
*/
void CImageUtilities::splitRGBAChannels(const QImage& imgSource, QImage& imgRed, QImage& imgGreen, QImage& imgBlue, QImage& imgAlpha)
{
    QImage trueColorImage = imgSource.convertToFormat(QImage::Format_ARGB32);

    for (int y = 0; y < trueColorImage.height(); y++)
    {
        for (int x = 0; x < trueColorImage.width(); x++)
        {
            QRgb currentPixel = trueColorImage.pixel(x, y);

            QColor colorRed(qRed(currentPixel), qRed(currentPixel), qRed(currentPixel));
            QColor colorGreen(qGreen(currentPixel), qGreen(currentPixel), qGreen(currentPixel));
            QColor colorBlue(qBlue(currentPixel), qBlue(currentPixel), qBlue(currentPixel));
            QColor colorAlpha(qAlpha(currentPixel), qAlpha(currentPixel), qAlpha(currentPixel));

            imgRed.setPixel(x, y, colorRed.rgba());
            imgGreen.setPixel(x, y, colorGreen.rgba());
            imgBlue.setPixel(x, y, colorBlue.rgba());
            imgAlpha.setPixel(x, y, colorAlpha.rgba());
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Merges RGBA channels into a single image. \br\br
    \a imgRed is the image that contains the red channel. \br
    \a imgGreen is the image that contains the green channel. \br
    \a imgBlue is the image that contains the blue channel. \br
    \a imgAlpha is the image that contains the alpha channel. \br
    \a imgTarget is the resulting image. \br
    \note All images must have the same size.
*/
void CImageUtilities::mergeRGBAChannels(const QImage& imgRed, const QImage& imgGreen, const QImage& imgBlue, const QImage& imgAlpha, QImage& imgTarget)
{
    bool bUseAlpha = imgAlpha.isNull() == false;

    for (int y = 0; y < imgTarget.height(); y++)
    {
        for (int x = 0; x < imgTarget.width(); x++)
        {
            QRgb currentRed = imgRed.pixel(x, y);
            QRgb currentGreen = imgGreen.pixel(x, y);
            QRgb currentBlue = imgBlue.pixel(x, y);
            QColor finalColor;

            if (bUseAlpha)
            {
                QRgb currentAlpha = imgAlpha.pixel(x, y);
                finalColor = QColor(qRed(currentRed), qGreen(currentGreen), qBlue(currentBlue), qRed(currentAlpha));
            }
            else
            {
                finalColor = QColor(qRed(currentRed), qGreen(currentGreen), qBlue(currentBlue));
            }

            imgTarget.setPixel(x, y, finalColor.rgba());
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Splits the different channels of an image, but as HSV instead of RGB. \br\br
    \a imgSource is the image to process. \br
    \a imgHue is the image that will contain the hue channel. \br
    \a imgSat is the image that will contain the saturation channel. \br
    \a imgVal is the image that will contain the lightness channel. \br
    \a imgAlpha is the image that will contain the alpha channel. \br
    \note All images must have the same size.
*/
void CImageUtilities::splitHSVAChannels(const QImage& imgSource, QImage& imgHue, QImage& imgSat, QImage& imgVal, QImage& imgAlpha)
{
    QImage trueColorImage = imgSource.convertToFormat(QImage::Format_ARGB32);

    for (int y = 0; y < trueColorImage.height(); y++)
    {
        for (int x = 0; x < trueColorImage.width(); x++)
        {
            QRgb currentPixel = trueColorImage.pixel(x, y);
            double dHue;
            double dSat;
            double dVal;

            QColor(currentPixel).getHsvF(&dHue, &dSat, &dVal);

            int iHue = (int) (dHue * 255.0);
            int iSat = (int) (dSat * 255.0);
            int iVal = (int) (dVal * 255.0);

            QColor colorHue(iHue, iHue, iHue);
            QColor colorSat(iSat, iSat, iSat);
            QColor colorVal(iVal, iVal, iVal);
            QColor colorAlpha(qAlpha(currentPixel), qAlpha(currentPixel), qAlpha(currentPixel));

            imgHue.setPixel(x, y, colorHue.rgba());
            imgSat.setPixel(x, y, colorSat.rgba());
            imgVal.setPixel(x, y, colorVal.rgba());
            imgAlpha.setPixel(x, y, colorAlpha.rgba());
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Merges HSVA channels into a single image. \br\br
    \a imgHue is the image that contains the hue channel. \br
    \a imgSat is the image that contains the saturation channel. \br
    \a imgVal is the image that contains the value channel. \br
    \a imgAlpha is the image that contains the alpha channel. \br
    \a imgTarget is the resulting image. \br
    \note All images must have the same size.
*/
void CImageUtilities::mergeHSVAChannels(const QImage& imgHue, const QImage& imgSat, const QImage& imgVal, const QImage& imgAlpha, QImage& imgTarget)
{
    bool bUseAlpha = imgAlpha.isNull() == false;

    for (int y = 0; y < imgTarget.height(); y++)
    {
        for (int x = 0; x < imgTarget.width(); x++)
        {
            qreal currentHue = QColor(imgHue.pixel(x, y)).redF();
            qreal currentSat = QColor(imgSat.pixel(x, y)).redF();
            qreal currentVal = QColor(imgVal.pixel(x, y)).redF();
            QColor finalColor;

            if (bUseAlpha)
            {
                qreal currentAlpha = QColor(imgAlpha.pixel(x, y)).redF();
                finalColor = QColor::fromHsvF(currentHue, currentSat, currentVal, currentAlpha);
            }
            else
            {
                finalColor = QColor::fromHsvF(currentHue, currentSat, currentVal);
            }

            imgTarget.setPixel(x, y, finalColor.rgba());
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the dominant hue in \a imgSource. \br\br
    \a dPrecision is a cursor for number of samples to use in histogram, goes from 0.03 to 1.0. \br
    \a dMinimumSaturation indicates the minimum value of pixel saturation in order to take hue into account.
*/
double CImageUtilities::findDominantHue(const QImage& imgSource, double dPrecision, double dMinimumSaturation)
{
    int iSamples = (int) (dPrecision * 512);

    iSamples = qBound(16, iSamples, 512);

    return CImageHistogram(imgSource, CImageHistogram::eHSV, iSamples, dMinimumSaturation).peak(CImageHistogram::eHue);
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the dominant value (luminosity) in \a imgSource. \br\br
    \a dPrecision is a cursor for number of samples to use in histogram, goes from 0.03 to 1.0.
*/
double CImageUtilities::findDominantValue(const QImage& imgSource, double dPrecision)
{
    int iSamples = (int) (dPrecision * 512);

    iSamples = qBound(16, iSamples, 512);

    return CImageHistogram(imgSource, CImageHistogram::eHSV, iSamples).peak(CImageHistogram::eValue);
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a QByteArray to which \a image was saved, using \a szFormat and \a compressionRate.
*/
QByteArray CImageUtilities::convertQImageToByteArray(const QImage& image, const char* szFormat, int compressionRate)
{
    QByteArray baOutput;
    QBuffer buffer(&baOutput);

    if (buffer.open(QIODevice::WriteOnly))
    {
        image.save(&buffer, szFormat, compressionRate);
        buffer.close();
    }

    return baOutput;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns an image loaded from \a baData, using \a szFormat.
*/
QImage CImageUtilities::convertByteArrayToQImage(const QByteArray& baData, const char* szFormat)
{
    QImage image;

    if (image.loadFromData(baData, szFormat))
    {
        image = image.convertToFormat(QImage::Format_RGB888);
    }

    return image;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a QByteArray containing grayscale pixels of \a image.
*/
QByteArray CImageUtilities::grayscale(const QImage& image)
{
    const unsigned char* src = (const unsigned char*) image.constBits();
    int len = image.width() * image.height();
    QByteArray returnValue(len, 0);

    // Itération sur chaque pixel
    // Une valeur de niveau de gris est calculée en fonction de la luminance
    for (int i = 0; i < len; i++, src += 3)
    {
        returnValue[i] = (int) (
                    0.2125 * (double) (src[0] >> 1) +
                0.7154 * (double) (src[1] >> 1) +
                0.0721 * (double) (src[2] >> 1)
                );
    }

    return returnValue;
}

//-------------------------------------------------------------------------------------------------

// 5kk73 GPU assignment

// correlation methods
// 1: SSD, sum of squared differences
// 2: SAD, sum of absolute differences
//
// Two methods should get the same disparity,
// but performance may be different,
// depending on the spec of the machine.
#define CORRELATION 1

// window size for SSD or SAD
#define WIN_SIZE 9

// Warning: the MAX_SHIFT should be less than or equal to 255
#define MAX_SHIFT 63

// Number of bins in histogram
#define HIST_BIN 256

// Define value below to use equalization
// #define WITH_EQUALIZATION

//-------------------------------------------------------------------------------------------------

/*!
    Creates a disparity map between two grayscale images. \br\br
    \a baLeft is the left image. \br
    \a baRight is the right image. \br
    \a imageWidth and \a imageHeight are the images size. \br
    \a grayMax is used for equalization.
*/
QByteArray CImageUtilities::disparityMap(const QByteArray& baLeft, const QByteArray& baRight, int imageWidth, int imageHeight, int grayMax)
{
    int i, j;

    /****************************************************
    *
    * Pad the images with margin pixels to handle
    * the SSD window operation at the border.
    *
    ****************************************************/

    // set board width to half SAD window
    int marginWidth = WIN_SIZE / 2;
    int marginHeight = WIN_SIZE / 2;

    // set height of padded image
    int paddedHeight = imageHeight + marginWidth * 2;

    // set width of padded image
    int paddedWidth = imageWidth + marginWidth * 2;

    // memory size (Byte) of the padded image
    int mem_size_paddedRight = sizeof(unsigned char) * paddedWidth * paddedHeight;
    int mem_size_paddedLeft = mem_size_paddedRight;

    // padded left image
    QByteArray baPaddedLeft(mem_size_paddedLeft, (char) 0x00);
    // padded right image
    QByteArray baPaddedRight(mem_size_paddedRight, (char) 0x00);

    // copy the image to the padded image
    for (i = 0; i < imageHeight; i++)
    {
        for (j = 0; j < imageWidth; j++)
        {
            baPaddedLeft[(marginHeight + i) * paddedWidth + marginWidth + j] = baLeft[i * imageWidth + j];
            baPaddedRight[(marginHeight + i) * paddedWidth + marginWidth + j] = baRight[i * imageWidth + j];
        }
    }

    /****************************************************
    *
    * Generate Disparity Map
    *
    ****************************************************/

    // shifted right image
    QByteArray baShiftedRight(mem_size_paddedRight, (char) 0x00);

    // malloc for SSD image, use integer (4 Byte) to avoid over flow
    int mem_size_ssd = sizeof(unsigned int) * paddedWidth * paddedHeight;
    unsigned int* puiSSD = new unsigned int [mem_size_ssd];

    // malloc for window over SSD
    int mem_size_winssd = sizeof(unsigned int) * imageWidth * imageHeight;
    unsigned int* puiWinSSD = new unsigned int [mem_size_winssd];

    // minimun of window over SSD
    int mem_size_minssd = sizeof(unsigned int) * imageWidth * imageHeight;
    unsigned int* puiMinSSD = new unsigned int [mem_size_minssd];

    // disparity map
    int mem_size_disparity = imageWidth * imageHeight;
    QByteArray disparity(mem_size_disparity, (char) 0x00);

    // the shift value of the right image
    int shift;

    // initialize SSD to xFFFFFFFF
    memset(puiSSD, 255, mem_size_ssd);

    // initialize window over SSD to xFFFFFFFF
    memset(puiWinSSD, 255, mem_size_winssd);

    // initialize min window SSD to xFFFFFFFF
    memset(puiMinSSD, 255, mem_size_minssd);

    for (shift = 0; shift < MAX_SHIFT; shift++)
    {
        /**************************************************
        * For each shift value, perform:
        * 1. Shift the right image
        * 2. Window SSD/SAD between left and shifted right image
        * 3. Find the shift value that leads to minimun SSD
        *************************************************/

        // make a shifted right image
        for (i = 0; i < paddedHeight; i++)
        {
            for (j = 0; j < paddedWidth - shift - marginWidth; j++)
            {
                baShiftedRight[i * paddedWidth + shift + j] = baPaddedRight[i * paddedWidth + j];
            }
        }

        // SSD/SAD
        for (i = 0; i < paddedHeight; i++)
        {
            for (j = 0; j < paddedWidth; j++)
            {
                int index = i * paddedWidth+j;
                int diff = baPaddedLeft[index] - baShiftedRight[index];

                // SSD
#if CORRELATION == 1
                puiSSD[index] = (unsigned int)(diff * diff);

                // SAD
#elif CORRELATION == 2
                puiSSD[index] = (unsigned int)abs(diff);

                // Unknown
#else
                printf("Unknown correlation method.\n");
                exit(1);
#endif
            }
        }

        // accumulate SSD over a window
        for (i = 0; i < imageHeight; i++)
        {
            for (j = 0; j < imageWidth; j++)
            {
                // indexwinssd: index to the center of the window over ssd
                int indexwinssd = i * imageWidth + j;

                // accu is used to accumulate the sum over the window
                unsigned int accu = 0;

                // loop over the window
                for (int ii = -1 * marginHeight; ii < marginHeight + 1; ii++)
                {
                    for (int jj = -1 * marginWidth; jj < marginWidth + 1; jj++)
                    {
                        // indexssd: index to the ssd position for accumulating the window
                        int indexssd = (i + marginHeight + ii) * paddedWidth + j + marginWidth + jj;
                        accu = accu + puiSSD[indexssd];
                    } //loop over window width
                } //loop over window height

                puiWinSSD[indexwinssd] = accu;
            } // loop over imageWidth
        } // loop over imageHeight

        // update the minimun of window over SSD and corresponding shift value
        for (i = 0; i < imageHeight; i++)
        {
            for (j = 0; j < imageWidth; j++)
            {
                int index = i * imageWidth + j;

                if (puiWinSSD[index] < puiMinSSD[index])
                {
                    puiMinSSD[index] = puiWinSSD[index];
                    disparity[index] = (unsigned char)shift;
                }
            }
        }

    } // loop over the shift value

    /****************************************************
    *
    * Histogram Equalization
    *
    ****************************************************/

#ifdef WITH_EQUALIZATION

    // histogram
    unsigned int hist[HIST_BIN];

    // cumulative distribution function
    int cdf[HIST_BIN];

    // transfer function for histogram equalization
    unsigned int trans[HIST_BIN];

    // minimun non-zero value of cumulative distribution function
    int mincdf = 0;

    // initialize histogram to 0
    memset(hist, 0, sizeof(unsigned int) * HIST_BIN);
    // initialize cumulative distribution function to 0
    memset(cdf, 0, sizeof(int) * HIST_BIN);

    for (i = 0; i < imageWidth * imageHeight; i++)
    {
        hist[disparity[i]]++;
    }

    cdf[0] = hist[0];
    for (i = 1; i < HIST_BIN; i++)
    {
        cdf[i] = cdf[i-1] + hist[i];
    }

    i = 0;
    while (mincdf == 0)
    {
        mincdf = cdf[i];
        i++;
    }

    // denonminator of transfer function
    int d = imageWidth * imageHeight - mincdf;
    for (i = 0; i < HIST_BIN; i++)
    {
        if (cdf[i] - mincdf < 0)
        {
            trans[i] = 0;
        }
        else
        {
            trans[i] = (unsigned int)( (float)( (cdf[i] - mincdf) * grayMax ) / (float)(d) );
        }
    }

    QByteArray baReturnValue(imageWidth * imageHeight, (char) 0x00);

    for (i = 0; i < imageWidth * imageHeight; i++)
    {
        baReturnValue[i] = (unsigned char)trans[disparity[i]];
    }

#else

    // No equalization

    grayMax = grayMax;

    QByteArray baReturnValue(imageWidth * imageHeight, (char) 0x00);

    for (i = 0; i < imageWidth * imageHeight; i++)
    {
        baReturnValue[i] = (unsigned char)disparity[i];
    }

#endif

    //-----------------------------------------------

    delete [] puiSSD;
    delete [] puiWinSSD;
    delete [] puiMinSSD;

    return baReturnValue;
}
