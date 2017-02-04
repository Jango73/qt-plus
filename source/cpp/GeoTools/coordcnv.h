// File Name:
//
// Package:
// Module:
//
// Description:
//
// Usage:
//
// Author:
// Created:
//
// Revision History:
//
//
#ifndef __COORDCNV
#define __COORDCNV

#include "../qtplus_global.h"

#include <math.h>

//#include "simtypes.h"


#define PIOVER2 (1.570796326794896619)
#define PITIMES2 (PIOVER2*4.0)
#define SEMI_MAJOR   6378137.0
#define SEMI_MINOR   6356752.3142
#define CENTRAL_SCALE 0.9996
#ifndef M_PI
#define M_PI 3.141592653589793239
#endif
#define DEG_TO_RAD (M_PI/180.0)
#define RAD_TO_DEG (180.0/M_PI)

#define FLOAT_64 double
#define FLOAT_32 float
#define LOGICAL int
typedef struct
{
    FLOAT_64     northing;   /* UTM northing in meters */
    FLOAT_64     easting;    /* UTM easting in meters  */
} UTM;

typedef struct
{
    FLOAT_64     phi;        /* geodetic latitude in radians  */
    FLOAT_64     lambda;     /* geodetic longitude in radians */
} GEO;

class QTPLUSSHARED_EXPORT CoordCnv
{
private:
    static void CalcFalseNorthEast ( FLOAT_64 latitude_radians );
    static FLOAT_64 CalcZone(FLOAT_64 longitude_radians);
    static void CalcLambda0(FLOAT_64 zone);
    static void CalcDatabaseOrigin(
            FLOAT_64 latitude,
            FLOAT_64 longitude,
            FLOAT_64 height);
    static void SaveGeocentricSinCos( void );
    static void InitializeEllipsoid( FLOAT_64 a, FLOAT_64 f );
    static void NIU_Initialize_WGS84( void );
    static void ComputeTopocentricConstants( FLOAT_64 x, FLOAT_64 y, FLOAT_64 z );
    static void NIU_InitializeTopocentric( FLOAT_64 x, FLOAT_64 y, FLOAT_64 z );

public:

    static void NIU_InitializeCoordinates( FLOAT_64 lat_rad,
                                           FLOAT_64 lon_rad,
                                           FLOAT_64 hgt_mtr);
    static void NIU_GeodeticToRadian( FLOAT_64  deg, FLOAT_64 min, FLOAT_64 sec,
                                      FLOAT_64 *radian);
    static void NIU_RadianToGeodetic( FLOAT_64 radian, FLOAT_64 *deg, FLOAT_64 *min,
                                      FLOAT_64 *sec);
    static void NIU_GeocentricToGeodetic( FLOAT_64 xp,   FLOAT_64 yp,   FLOAT_64 zp,
                                          FLOAT_64 *lat, FLOAT_64 *lon, FLOAT_64 *height );
    static void NIU_GeocentricToUTM( FLOAT_64 xg,  FLOAT_64 yg,  FLOAT_64 zg,
                                     FLOAT_64 *xu, FLOAT_64 *yu, FLOAT_64 *zu );
    static void NIU_GeocentricToUTMLocal( FLOAT_64 xg,  FLOAT_64 yg,  FLOAT_64 zg,
                                          FLOAT_64 *xu, FLOAT_64 *yu, FLOAT_64 *zu );
    static void NIU_GeocentricToTopocentric( FLOAT_64 xg,  FLOAT_64 yg,  FLOAT_64 zg,
                                             FLOAT_64 *xt, FLOAT_64 *yt, FLOAT_64 *zt );
    static void NIU_GeodeticToGeocentric( FLOAT_64 lat,  FLOAT_64 lon,  FLOAT_64 height,
                                          FLOAT_64 *x,   FLOAT_64 *y,   FLOAT_64 *z );
    static void NIU_GeodeticToUTM( GEO *geo, UTM *utm );
    static void NIU_UTMToGeodetic( UTM *utm, GEO *geo );
    static void NIU_UTMToGeocentric( FLOAT_64 xu,  FLOAT_64 yu,  FLOAT_64 zu,
                                     FLOAT_64 *xg, FLOAT_64 *yg, FLOAT_64 *zg );
    static void NIU_UTMLocalToGeocentric( FLOAT_64  xu, FLOAT_64  yu, FLOAT_64  zu,
                                          FLOAT_64 *xg, FLOAT_64 *yg, FLOAT_64 *zg );
    static void NIU_UTMLocalToUTM ( FLOAT_64 xl,  FLOAT_64 yl,  FLOAT_64 zl,
                                    FLOAT_64 *xu, FLOAT_64 *yu, FLOAT_64 *zu );
    static void NIU_UTMToUTMLocal ( FLOAT_64 xu,  FLOAT_64 yu,  FLOAT_64 zu,
                                    FLOAT_64 *xl, FLOAT_64 *yl, FLOAT_64 *zl );

    static void NIU_TopocentricToGeocentric( FLOAT_64 xt,  FLOAT_64 yt,  FLOAT_64 zt,
                                             FLOAT_64 *xg, FLOAT_64 *yg, FLOAT_64 *zg );
    static void NIU_TopovelocityToGeovelocity(FLOAT_32  vxt, FLOAT_32  vyt, FLOAT_32  vzt,
                                              FLOAT_32 *vxg, FLOAT_32 *vyg, FLOAT_32 *vzg);
    static void NIU_GeoVelocityToUTMVelocity(
            FLOAT_32 srcx,   FLOAT_32 srcy,   FLOAT_32 srcz,
            FLOAT_32 *destx, FLOAT_32 *desty, FLOAT_32 *destz );
    static void NIU_GeovelocityToTopovelocity(FLOAT_32  vxg, FLOAT_32  vyg, FLOAT_32  vzg,
                                              FLOAT_32 *vxt, FLOAT_32 *vyt, FLOAT_32 *vzt);
    static void NIU_UTMVelocityToGeoVelocity(
            FLOAT_32 srcx,   FLOAT_32 srcy,   FLOAT_32 srcz,
            FLOAT_32 *destx, FLOAT_32 *desty, FLOAT_32 *destz );
    static void NIU_GeoEulerToUTMEuler(
            FLOAT_32 psi,      FLOAT_32 theta,     FLOAT_32 phi,
            FLOAT_32 *utmRoll, FLOAT_32 *utmPitch, FLOAT_32 *utmYaw );
    static void NIU_GeoeulerToTopoeuler(
            FLOAT_32 psi,      FLOAT_32 theta,     FLOAT_32 phi,
            FLOAT_32 *outRoll, FLOAT_32 *outPitch, FLOAT_32 *outYaw );
    static void NIU_UTMEulerToGeoEuler(
            FLOAT_32 utmRoll, FLOAT_32 utmPitch, FLOAT_32 utmYaw,
            FLOAT_32 *psi,    FLOAT_32 *theta,   FLOAT_32 *phi );
    static void NIU_TopoeulerToGeoeuler(
            FLOAT_32 inRoll,  FLOAT_32 inPitch,  FLOAT_32 inYaw,
            FLOAT_32 *psi,    FLOAT_32 *theta,   FLOAT_32 *phi );

};
#endif
