
// Std
#include <limits>

// Application
#include "GeoTools/geocent.h"
#include "CGeoUtilities.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CGeoUtilities
    \inmodule qt-plus
    \brief A singleton that provides coordinate system change functions.
*/

//-------------------------------------------------------------------------------------------------

const double CGeoUtilities::POS_INFINITY = std::numeric_limits<double>::infinity();
const double CGeoUtilities::NEG_INFINITY = -std::numeric_limits<double>::infinity();
const double CGeoUtilities::TWO_PI = 2.0 * M_PI;
const double CGeoUtilities::HALF_PI = 0.5 * M_PI;
const double CGeoUtilities::fDeg2Rad = M_PI / 180.0;
const double CGeoUtilities::fRad2Deg = 180.0 / M_PI;

//-------------------------------------------------------------------------------------------------

static QString Vector3DString(const QVector3D& vec)
{
    return "<" + QString::number(vec.x(), 'f', 2) + ", " + QString::number(vec.y(), 'f', 2) + ", " + QString::number(vec.z(), 'f', 2) + ">";
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a quaternion that would rotate a point from \a vFrom to \a vTo.
*/
QQuaternion CGeoUtilities::getRotationBetween(const QVector3D& vFrom, const QVector3D& vTo)
{
    QVector3D nVec1 = vFrom.normalized();
    QVector3D nVec2 = vTo.normalized();
    QVector3D nVec3 = (nVec1 + nVec2).normalized();
    double angle = QVector3D::dotProduct(nVec3, nVec2);
    QVector3D axis = QVector3D::crossProduct(nVec3, nVec2);

    return QQuaternion(angle, axis);
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a transform matrix that rotates a point from the geocentric coordinate \a vReference to the geocentric coordinate of lat/lon = 0.
*/
QMatrix4x4 CGeoUtilities::getGeoReferenceMatrix(const QVector3D& vReference)
{
    QMatrix4x4 mRotationInverseY;

    QVector3D vReferenceCopy = vReference;

    // Get a quaternion that brings reference to <1, 0, 0> without taking Y component into account
    QQuaternion mQuat1 = getRotationBetween(QVector3D(1.0, 0.0, 0.0), QVector3D(vReferenceCopy.x(), 0.0, vReferenceCopy.z()));

    mRotationInverseY.rotate(mQuat1);
    vReferenceCopy = vReferenceCopy * mRotationInverseY;

    // Get a quaternion for the X axis rotation
    QQuaternion mQuat2 = getRotationBetween(QVector3D(1.0, 0.0, 0.0), QVector3D(vReferenceCopy));

    // Create a matrix using both quats and 90 degrees about Y and X axis
    QMatrix4x4 mResult;
    mResult.rotate(mQuat1);
    mResult.rotate(mQuat2);
    mResult.rotate(-90.0, 0.0, 1.0, 0.0);
    mResult.rotate(-90.0, 1.0, 0.0, 0.0);

    // Return the result matrix
    return mResult;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a 3D point which is the xyz equivalent of \a gPosition relative to \a gReference. \br\br
    Imagining that you are standing at \a gReference on earth, looking to true north, the resulting vector is: \br
    \list
    \li X = positive to your right
    \li Y = positive above your head
    \li Z = positive in front of you
    \endlist
    \sa Vector3DToGeoCoordinate()
*/
#ifdef QT_POSITIONING_LIB

QVector3D CGeoUtilities::GeoCoordinateToVector3D(const QGeoCoordinate& gPosition, const QGeoCoordinate& gReference)
{
    double dReference3D_X;
    double dReference3D_Y;
    double dReference3D_Z;
    double dPosition3D_X;
    double dPosition3D_Y;
    double dPosition3D_Z;
    double dTemp;

    // Get geocentric coordinates of reference
    Convert_Geodetic_To_Geocentric(
                gReference.latitude() * fDeg2Rad,
                gReference.longitude() * fDeg2Rad,
                gReference.altitude(),
                &dReference3D_X, &dReference3D_Y, &dReference3D_Z
                );

    // Get geocentric coordinates of position
    Convert_Geodetic_To_Geocentric(
                gPosition.latitude() * fDeg2Rad,
                gPosition.longitude() * fDeg2Rad,
                gPosition.altitude(),
                &dPosition3D_X, &dPosition3D_Y, &dPosition3D_Z
                );

    // Reverse Y and Z components of position and reference (axis conventions)
    dTemp = dReference3D_Y; dReference3D_Y = dReference3D_Z; dReference3D_Z = dTemp;
    dTemp = dPosition3D_Y; dPosition3D_Y = dPosition3D_Z; dPosition3D_Z = dTemp;

    // Create vectors using doubles
    QVector3D vReference3D(dReference3D_X, dReference3D_Y, dReference3D_Z);
    QVector3D vPosition3D(dPosition3D_X, dPosition3D_Y, dPosition3D_Z);

    // Get the magic transform matrix
    QMatrix4x4 mRotationInverse = getGeoReferenceMatrix(vReference3D);

    // Transform both position and reference using the matrix
    vReference3D = vReference3D * mRotationInverse;
    vPosition3D = vPosition3D * mRotationInverse;

    // Return the difference between position and reference in xyz coord system
    return vPosition3D - vReference3D;
}

#endif

//-------------------------------------------------------------------------------------------------

/*!
    Returns a geo coordinate which is the geodetic equivalent of \a vPosition, relative to \a gReference. \br
    It is the exact inverse of GeoCoordinateToVector3D().
    \sa GeoCoordinateToVector3D()
*/
#ifdef QT_POSITIONING_LIB

QGeoCoordinate CGeoUtilities::Vector3DToGeoCoordinate(const QVector3D& vPosition, const QGeoCoordinate& gReference)
{
    double dReference3D_X;
    double dReference3D_Y;
    double dReference3D_Z;
    double dLatitude;
    double dLongitude;
    double dAltitude;
    double dTemp;

    //-----------------------------------------------
    // Récupération des coordonnées géocentriques

    Convert_Geodetic_To_Geocentric(
                gReference.latitude() * fDeg2Rad,
                gReference.longitude() * fDeg2Rad,
                gReference.altitude(),
                &dReference3D_X, &dReference3D_Y, &dReference3D_Z
                );

    // Reverse Y and Z components of reference (axis conventions)
    dTemp = dReference3D_Y; dReference3D_Y = dReference3D_Z; dReference3D_Z = dTemp;

    // Create a vector using doubles
    QVector3D vReference3D(dReference3D_X, dReference3D_Y, dReference3D_Z);

    // Get the magic transform matrix
    QMatrix4x4 mRotationInverse = getGeoReferenceMatrix(vReference3D);

    // Transform reference using the matrix
    vReference3D = vReference3D * mRotationInverse;

    // Add reference and position
    QVector3D vPosition3D = vReference3D + vPosition;

    // Transform position using the matrix' inverse
    vPosition3D = vPosition3D * mRotationInverse.inverted();

    // Reverse Y and Z components of position (axis conventions)
    dTemp = vPosition3D.y(); vPosition3D.setY(vPosition3D.z()); vPosition3D.setZ(dTemp);

    // Get geodetic coordinates of position
    Convert_Geocentric_To_Geodetic(
        vPosition3D.x(), vPosition3D.y(), vPosition3D.z(),
        &dLatitude,
        &dLongitude,
        &dAltitude
        );

    // Return a geo coordinate using result
    return QGeoCoordinate(dLatitude * fRad2Deg, dLongitude * fRad2Deg, dAltitude);
}

#endif
