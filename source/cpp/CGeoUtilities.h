
#pragma once

#include "qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Std
#include "math.h"

// Qt
#include <QVariant>
#include <QDataStream>
#include <QString>
#include <QVector3D>
#include <QMatrix4x4>
#include <QQuaternion>

#ifdef QT_POSITIONING_LIB
#include <QGeoCoordinate>
#endif

// Application
#include "CSingleton.h"

//-------------------------------------------------------------------------------------------------

// Defines methods to convert between geo and cartesian coordinates
// Uses the WGS 84 model
class QTPLUSSHARED_EXPORT CGeoUtilities : public CSingleton<CGeoUtilities>
{
    friend class CSingleton<CGeoUtilities>;

public:

    // Constants

    static const double POS_INFINITY;
    static const double NEG_INFINITY;
    static const double TWO_PI;
    static const double HALF_PI;
    static const double fDeg2Rad;
    static const double fRad2Deg;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Returns a quaternion that would rotate a point from \a vFrom to \a vTo.
    QQuaternion getRotationBetween(const QVector3D& vFrom, const QVector3D& vTo);

    //! Returns a transform matrix that rotates a point from the geocentric coordinate \a vReference to the geocentric coordinate of lat/lon = 0.
    QMatrix4x4 getGeoReferenceMatrix(const QVector3D& vReference);

#ifdef QT_POSITIONING_LIB

    //! Returns a 3D point which is the xyz equivalent of \a gPosition relative to \a gReference.
    QVector3D GeoCoordinateToVector3D(const QGeoCoordinate& gPosition, const QGeoCoordinate& gReference);

    //! Returns a geo coordinate which is the geodetic equivalent of \a vPosition, relative to \a gReference.
    QGeoCoordinate Vector3DToGeoCoordinate(const QVector3D& gPosition, const QGeoCoordinate& gReference);

#endif

};
