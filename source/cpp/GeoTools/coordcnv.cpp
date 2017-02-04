
////    Includes    ////
#include <string.h>
#include "coordcnv.h"

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

////    Static Data    ////
static GEO saved_geo;
static FLOAT_64 ellipse_a,          /* equatorial radius   */
ellipse_a_sq,       /* radius squared      */
ellipse_f,          /* flattening (a-b)/a  */
ellipse_b,          /* polar semi-diameter */
ellipse_b_sq,       /* polar semi-diameter squared */
ellipse_a_sq_over_b,/* a*a/b                       */
ellipse_e,          /* ellipticity 2f-f*f          */
ellipse_c1,         /* (1-f)*(1-f)                 */

topo_radius,        /* z value at origin of topocentric systemc */

topo_sin_lat,       /* sin of angle between normal & equ plane  */
topo_cos_lat,       /* cos of angle between normal & equ plane  */
topo_sin_lon,       /* sin of angle between normal & PM plane   */
topo_cos_lon,       /* cos of angle between normal & PM plane   */

topo_sin_cos,       /* sin(lat) * cos(lon)                      */
topo_sin_sin,       /* sin(lat) * sin(lon)                      */
topo_cos_cos,       /* cos(lat) * cos(lon)                      */
topo_cos_sin,       /* cos(lat) * sin(lon)                      */

xo, yo, zo, /* origin of the database in geocentric coordinates */

ellipse_a_b,           /* (a * b)         */
ellipse_a_sq_sq,       /* (a * a * a * a) */
ellipse_b_sq_sq,       /* (b * b * b * b) */
two_over_ellipse_a,    /* (2/a)           */
two_over_ellipse_b,    /* (2/b)           */
two_over_ellipse_a_sq, /* 2/(a * a)       */
two_over_ellipse_b_sq, /* 2/(b * b)       */

saved_geod_sin_lat,       /* sin of angle latitude (phi)     */
saved_geod_cos_lat,       /* cos of angle latitude (phi)     */
saved_geod_sin_lon,       /* sin of angle longitude (lambda) */
saved_geod_cos_lon,       /* cos of angle longitude (lambda) */
saved_geod_sin_cos,       /* sin(lat) * cos(lon)             */
saved_geod_sin_sin,       /* sin(lat) * sin(lon)             */
saved_geod_cos_cos,       /* cos(lat) * cos(lon)             */
saved_geod_cos_sin,       /* cos(lat) * sin(lon)             */

False_North,
False_East,
Zone,
Database_Origin_X,
Database_Origin_Y,
Lambda0,
e_sq,     /* eccentricity squared */
ep_sq,    /* e-prime squared      */
ef,       /* e-factor             */
e_sq_to_3,/* pow(e_sq,3.0) */
ef_to_3,  /* pow(ef,3.0) */
ef_to_4,  /* pow(ef,4.0) */

poly1_a,
poly2_a,
poly3_a,
poly4_a,
poly5_a,
poly1_b,
poly2_b,
poly3_b,
poly4_b;

////    Functions    ////

/***************************************************************************
*  Routine name:  InitializeEllipsoid                                      *
*                                                                          *
*  Description :  Sets up a mathematical model of the WGS84 spheroid.      *
*     The model is used in the setup of the transformation. This is called *
*     by NIU_InitializeTopocentric().  The algorithm is obtained from the  *
*     paper titled:                                                        *
*     Use of Global Coordinates in the SIMNET Protocol by Burchfield       *
*     and Smyth,  BBN Systems and Technologies Corporation (Jan. 1990).    *
*                                                                          *
* a: equatorial radius: WGS84 = 6,378,137m                                 *
* b: flattening:        WGS84 = 1 / 298.257223563                          *
*                                                                          *
*  Parameters  :                                                           *
*         Inbound  :                                                       *
*         Outbound :                                                       *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*  Author:                                                                 *
*         John Gagnon, TSI.                                                *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::InitializeEllipsoid( FLOAT_64 a, FLOAT_64 f)
{

    ellipse_a = a;
    ellipse_a_sq = ellipse_a * ellipse_a;
    ellipse_f = f;
    ellipse_b = ellipse_a * (1.0 - ellipse_f);

    ellipse_b_sq = ellipse_b * ellipse_b;
    ellipse_a_sq_over_b = ellipse_a_sq / ellipse_b;

    /* changed by Huat Ng                         */
    /* ellipse_e = ellipse_f * (2.0 + ellipse_f); */

    ellipse_e  = ellipse_f*(2.0 - ellipse_f);
    ellipse_c1 = (1.0 - ellipse_f) * (1.0 - ellipse_f);

    ellipse_a_b     = ellipse_a * ellipse_b;           /* (a * b)         */

    ellipse_a_sq_sq = ellipse_a_sq * ellipse_a_sq;     /* (a * a * a * a) */
    ellipse_b_sq_sq = ellipse_b_sq * ellipse_b_sq;     /* (b * b * b * b) */

    two_over_ellipse_a = 2.0 / ellipse_a;              /* (2/a)           */
    two_over_ellipse_b = 2.0 / ellipse_b;              /* (2/b)           */

    two_over_ellipse_a_sq = 2.0 / ellipse_a_sq;        /* 2/(a * a)       */
    two_over_ellipse_b_sq = 2.0 / ellipse_b_sq;        /* 2/(b * b)       */

} /* end of InitializeEllipsoid */

/***************************************************************************
*  Routine name:  ComputeTopocentricConstants                              *
*                                                                          *
*  Description :  This procedure sets up transformation constants          *
*     This procedure sets up transformation constants associated with a    *
*     associated with a point with geocentric coordinates x, y, and z      *
*     for use in subsequent conversions between geocentric and topocentric *
*     coordinates.  It must be called once whenever a new origin is        *
*     selected for a topocentric coordinate system.  The algorithm is      *
*     obtained from the paper titled:                                      *
*     Use of Global Coordinates in the SIMNET Protocol by Burchfield       *
*     and Smyth,  BBN Systems and Technologies Corporation (Jan. 1990).    *
*                                                                          *
*  Parameters  :  x,y,z:  Geocentric coords for database                   *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*  Author:                                                                 *
*     John Gagnon, TSI.                                                    *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::ComputeTopocentricConstants( FLOAT_64 x, FLOAT_64 y, FLOAT_64 z )
{
    FLOAT_64        w, wsq;
    static FLOAT_64 lat, lon, dummy;

    wsq = x * x + y * y;
    topo_radius = sqrt(wsq + z * z);

    NIU_GeocentricToGeodetic(x, y, z, &lat, &lon, &dummy);

    w = sqrt(wsq);

    topo_cos_lat = cos(lat);
    topo_sin_lat = sqrt(1.0 - topo_cos_lat * topo_cos_lat);

    topo_cos_lon = x / w;
    topo_sin_lon = y / w;

    topo_sin_sin = topo_sin_lat * topo_sin_lon;
    topo_sin_cos = topo_sin_lat * topo_cos_lon;
    topo_cos_sin = topo_cos_lat * topo_sin_lon;
    topo_cos_cos = topo_cos_lat * topo_cos_lon;

} /* end of ComputeTopocentricConstants */

/***************************************************************************
*  Routine name:  NIU_InitializeTopocentric                                *
*                                                                          *
*  Description :                                                           *
*      Primary initialization. Pass in the Latitude, Longitude, and        *
*      Height for the database in use, this will set up the parameters     *
*      for the transformation routines. This must be called prior to use   *
*      of any of the transformation routines.                              *
*                                                                          *
*  Parameters  :  Geodetic coordinates for the origin of the DB            *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*   Author:                                                                *
*      John Gagnon, TSI.                                                   *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::NIU_InitializeTopocentric(FLOAT_64 x,FLOAT_64 y,FLOAT_64 z)
{
    static FLOAT_64 gx, gy, gz;

    InitializeEllipsoid(6378137.0,(1.0 / 298.257223563));

    NIU_GeodeticToGeocentric(x, y, z, &gx, &gy, &gz);

    ComputeTopocentricConstants(gx, gy, gz);

    /* save the origin of the database in       */
    /* geocentric coordinates to be used later. */
    /* added by Huat Ng                         */

    xo = gx;
    yo = gy;
    zo = gz;

} /* end of NIU_InitializeTopocentric */


/***************************************************************************
*  Routine name:  NIU_GeodeticToGeocentric                                 *
*                                                                          *
*  Description :  Converts a position specified by the geodetic coordinate *
*        lat, lon, height to cartesian geocentric coordinates.             *
*        InitializeEllipsoid() must have been called prior to using this.  *
*        The algorithm is obtained from the paper titled:                  *
*        Use of Global Coordinates in the SIMNET Protocol by Burchfield    *
*        and Smyth,  BBN Systems and Technologies Corporation (Jan. 1990). *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*   Author:                                                                *
*      John Gagnon, TSI.                                                   *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::NIU_GeodeticToGeocentric(
        FLOAT_64 lat,
        FLOAT_64 lon,
        FLOAT_64 height,
        FLOAT_64 *x,
        FLOAT_64 *y,
        FLOAT_64 *z
        )
{
    FLOAT_64 sinlat, temp1, temp2, w;
    FLOAT_64 sqrt_term;

    /* Obtain the vertical and horizontal projection of the      */
    /* point on the ellipsoid                                    */

    sinlat = sin(lat);
    sqrt_term = 1.0 - (ellipse_e * (sinlat * sinlat));

    if (sqrt_term == 0.0)
    {
        sqrt_term = 0.0001;
    }
    else if (sqrt_term < 0.0)
    {
        sqrt_term *= -1.0;
    }

    temp1 = ellipse_a / sqrt(sqrt_term);
    temp2 = temp1 * ellipse_c1;

    temp1 += height;
    temp2 += height;

    /* Obtain the projected horizontal position on the equatorial plane */

    w = temp1 * cos(lat);

    /* Obtain the projected vertical position on the polar axis */

    *z = temp2 * sinlat;

    /* Project the horizontal position on the two axes in the       */
    /* equatorial plane.                                            */

    *x = w * cos(lon);

    /* Cannot use sqrt here, y will always be positive if this is the case */
    /* changed by Huat Ng                                                  */
    /* *y = sqrt((w * w) - (*x * *x));                                     */

    *y = w * sin(lon);

} /* end of NIU_GeodeticToGeocentric */

/***************************************************************************
*  Routine name:  NIU_GeocentricToGeodetic                                 *
*                                                                          *
*  Description :                                                           *
*     Performs the transformation between geocentric and geodetic          *
*     coordinate systems.  This routine receives geocentric coordinates    *
*     (X,Y,Z) in meters and converts it into geodetic coordinates given    *
*     in latitude, longitude, and height.  This algorithm uses Newton-     *
*     Raphson's convergence algorithm, and will stop iteration at values   *
*     less than 50 cm.                                                     *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*   Author:                                                                *
*       Huat Ng, IST.                                                      *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::NIU_GeocentricToGeodetic(
        FLOAT_64 xp,
        FLOAT_64 yp,
        FLOAT_64 zp,
        FLOAT_64 *lat,
        FLOAT_64 *lon,
        FLOAT_64 *height
        )
{
    LOGICAL  special_case1, special_case2;
    FLOAT_64 m,h,f,
            f_prime,h_previous,
            xp_sq,yp_sq,zp_sq,
            wp,wp_sq,x,y,z,w,w_sq,
            tanphi,temp1,temp2,temp1_sq,temp2_sq,temp_m;

    FLOAT_64 sqrt_term;

    /*************************************************/
    /* Test for special cases on longitude.          */
    /* Initialize both special cases to FALSE first. */
    /*************************************************/

    special_case1 = FALSE;
    special_case2 = FALSE;

    if (xp != 0) /* xp not equal to zero: ordinary case */
    {
        *lon = atan2(yp,xp);
    }
    else /* xp is zero */
    {
        if(yp > 0)
        {
            *lon = PIOVER2;
        }
        else /* yp is either zero or less than zero */
        {
            if(yp < 0)
            {
                *lon = -PIOVER2;
            }
            else /* xp and yp is both zero: special case */
            {

                special_case2 = TRUE;
                if(zp > 0.0)
                {
                    *lat = PIOVER2;
                }
                else
                {
                    if (zp < 0.0)
                    {
                        *lat = -PIOVER2;
                    }
                    else
                    {
                        special_case1 = TRUE;

                        //                 NIU_Debug(DEBUG_CONV,"Both latitude & h are undefined when X = Y = Z = 0\n");
                    }
                }

                //           NIU_Debug(DEBUG_CONV,"Longitude is undefined when X = Y = 0\n");

            }

        }
    }


    if (special_case1 == FALSE)
    {

        /***************************************/
        /* calculate squares of xp, yp, and zp */
        /***************************************/
        xp_sq = xp*xp;
        yp_sq = yp*yp;
        zp_sq = zp*zp;

        /***********************/
        /* calculate wp square */
        /***********************/
        wp_sq = xp_sq + yp_sq;
        wp = sqrt(wp_sq);

        /*****************/
        /* Initial guess */
        /*****************/
        temp_m = ellipse_a_sq*zp_sq + ellipse_b_sq*wp_sq;

        /*
      m = 0.5 * ((ellipse_a_b*temp_m*(sqrt(temp_m) - ellipse_a_b))/
         (ellipse_a_sq_sq*zp_sq + ellipse_b_sq_sq*wp_sq));
*/

        /* EA Simplify initial guess to avoid FLOAT_32ing overflow on the VAX */
        m = 0.5 * (sqrt(temp_m)-ellipse_a_b);

        /*******************/
        /* calculate x,y,z */
        /*******************/
        x = (1.0/(1.0+(two_over_ellipse_a_sq*m)))*xp; /* RAT, Save 1 divide */
        y = (1.0/(1.0+(two_over_ellipse_a_sq*m)))*yp; /* RAT, Save 1 divide */
        z = (1.0/(1.0+(two_over_ellipse_b_sq*m)))*zp; /* RAT, Save 1 divide */

        /********************/
        /* calculate height */
        /********************/
        h = sqrt((xp-x)*(xp-x) + (yp-y)*(yp-y) + (zp-z)*(zp-z));

        /****************************************/
        /* begins the iteration for convergence */
        /****************************************/
        do
        {
            h_previous = h;

            temp1 = ellipse_a + (two_over_ellipse_a*m); /* RAT, Save 1 divide */
            temp2 = ellipse_b + (two_over_ellipse_b*m); /* RAT, Save 1 divide */
            temp1_sq = temp1*temp1;
            temp2_sq = temp2*temp2;

            /***************************/
            /* calculate f and f prime */
            /***************************/
            f = wp_sq/temp1_sq + zp_sq/temp2_sq - 1.0;

            f_prime = - 4.0*(wp_sq/(ellipse_a*temp1*temp1_sq) +
                             zp_sq/(ellipse_b*temp2*temp2_sq)); /* RAT, Save 1 mult */

            /******************************************/
            /* Newton-Raphson's convergence algorithm */
            /******************************************/
            m = m - f/f_prime;

            w = (1.0/(1.0+(two_over_ellipse_a_sq*m)))*wp;  /* RAT, Save 1 divide */
            z = (1.0/(1.0+(two_over_ellipse_b_sq*m)))*zp;  /* RAT,Save 1 divide */

            /**************************/
            /* recalculate the height */
            /**************************/
            h = sqrt((wp-w)*(wp-w) + (zp-z)*(zp-z));


        } while(fabs(h-h_previous) > 0.5);

        /******************************************************/
        /* convert x,y,z into latitude, longitude, and height */
        /******************************************************/

        w_sq = w*w;

        /*******************************/
        /* assign the value for height */
        /*******************************/

        *height = h;

        if((wp_sq + zp_sq) < (w_sq + z*z))
        {
            *height = -(*height);
        }

        /**************************/
        /* calculate for latitude */
        /**************************/
        if(special_case2 == FALSE)
        {

            sqrt_term = fabs(1.0 - w_sq / ellipse_a_sq);
            if (sqrt_term < 0.0)
                sqrt_term *= -1.0;
            tanphi = (ellipse_a_sq_over_b *
                      sqrt(sqrt_term)) / w;

            *lat = atan(tanphi);

            if ( zp < 0 ) { *lat = -(*lat); }

        } /* if special case 2 is false */

    }  /* end of special case 1 */

} /* end of NIU_GeocentricToGeodetic */

/***************************************************************************
*  Routine name:  NIU_TopocentricToGeocentric                              *
*                                                                          *
*  Description :  Performs world coordinate transformation from SIMNETs    *
*                 Topocentric to DISs Geocentric coordinate system. This   *
*                 corrects the problem of radius of the earth.             *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*   Author:                                                                *
*       Huat Ng, IST.                                                      *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::NIU_TopocentricToGeocentric(
        FLOAT_64 xt,
        FLOAT_64 yt,
        FLOAT_64 zt,
        FLOAT_64 *xg,
        FLOAT_64 *yg,
        FLOAT_64 *zg
        )
{

    *xg = xt * (-topo_sin_lon) -
            yt * topo_sin_cos +
            zt * topo_cos_cos + xo;

    *yg = xt * topo_cos_lon -
            yt * topo_sin_sin +
            zt * topo_cos_sin + yo;

    *zg = yt * topo_cos_lat +
            zt * topo_sin_lat + zo;

} /* end of NIU_TopocentricToGeocentric */

/***************************************************************************
*  Routine name:  NIU_GeocentricToTopocentric                              *
*                                                                          *
*  Description :  Performs the translation from DIS geocentric coordinate  *
*                 system into SIMNET topocentric coordinate system.        *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*   Author:                                                                *
*       Huat Ng, IST.                                                      *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::NIU_GeocentricToTopocentric(
        FLOAT_64 xg,
        FLOAT_64 yg,
        FLOAT_64 zg,
        FLOAT_64 *xt,
        FLOAT_64 *yt,
        FLOAT_64 *zt
        )
{
    *xt = (xg - xo) * (-topo_sin_lon) +
            (yg - yo) * topo_cos_lon;

    *yt = (xg - xo) * (-topo_sin_cos) -
            (yg - yo) * topo_sin_sin +
            (zg - zo) * topo_cos_lat;

    *zt = (xg - xo) * topo_cos_cos +
            (yg - yo) * topo_cos_sin +
            (zg - zo) * topo_sin_lat;

} /* end of NIU_GeocentricToTopocentric */

/***************************************************************************
*  Routine name: NIU_GeodeticToRadian                                      *
*                                                                          *
*  Description : Performs the translation between a geodetic coordinate    *
*                given in degrees, minutes and seconds into radians.       *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*   Author:                                                                *
*       Huat Ng, IST.                                                      *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::NIU_GeodeticToRadian( FLOAT_64  deg, FLOAT_64 min, FLOAT_64 sec,
                                     FLOAT_64 *radian)
{
    FLOAT_64 dms;

    /* Convert minutes and seconds into degrees */
    dms = (min / 60.0) + (sec / 3600.0);

    if (deg < 0.0)
        deg -= dms;
    else
        deg += dms;

    /* Convert degrees into radians */
    *radian = deg*(PITIMES2 / 360.0);

} /* end of NIU_GeodeticToRadian */

/***************************************************************************
*  Routine name:  NIU_RadianToGeodetic                                     *
*                                                                          *
*  Description :  Performs the translation between a values in radians and *
*                 geodetic coordinates ( degrees, minutes and seconds)     *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*   Author:                                                                *
*       Huat Ng, IST.                                                      *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::NIU_RadianToGeodetic( FLOAT_64 radian, FLOAT_64 *deg, FLOAT_64 *min,
                                     FLOAT_64 *sec)
{
    FLOAT_64 deg_min_sec, min_and_sec, sec_only;

    deg_min_sec = fabs(radian*(360.0/PITIMES2));

    /* rounds the argument down to an integer */
    *deg = floor(deg_min_sec);

    /* get the fractional part of radian argument */
    min_and_sec = deg_min_sec - *deg;

    /* get the minutes part out from the fraction */
    *min = floor(min_and_sec * 60.0);

    /* get the fractional part of the min_and_sec argument */
    sec_only = (min_and_sec*60.0) - *min;

    *sec = floor(sec_only * 60.0);

    /* take care of negative radian case */
    if (radian < 0.0)
        *deg = -(*deg);

} /* end of NIU_RadianToGeodetic */

/***************************************************************************
*  Routine name:  NIU_TopovelocityToGeovelocity                            *
*                                                                          *
*  Description :  Converts a Topocentric to Geocentric velocity.           *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::NIU_TopovelocityToGeovelocity(
        FLOAT_32  vxt,
        FLOAT_32  vyt,
        FLOAT_32  vzt,
        FLOAT_32 *vxg,
        FLOAT_32 *vyg,
        FLOAT_32 *vzg
        )
{

    *vxg = (FLOAT_32) (vxt * (-topo_sin_lon) -
                       vyt * topo_sin_cos +
                       vzt * topo_cos_cos);

    *vyg = (FLOAT_32) (vxt * topo_cos_lon -
                       vyt * topo_sin_sin +
                       vzt * topo_cos_sin);

    *vzg = (FLOAT_32) (vyt * topo_cos_lat +
                       vzt * topo_sin_lat);

} /* end of NIU_TopovelocityToGeovelocity */

/***************************************************************************
*  Routine name:  NIU_GeovelocityToTopovelocity                            *
*                                                                          *
*  Description :  Converts geocentric velocity to topocentic values.       *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::NIU_GeovelocityToTopovelocity(
        FLOAT_32 vxg,
        FLOAT_32 vyg,
        FLOAT_32 vzg,
        FLOAT_32 *vxt,
        FLOAT_32 *vyt,
        FLOAT_32 *vzt
        )
{
    *vxt = (FLOAT_32) (vxg * (-topo_sin_lon) +
                       vyg * topo_cos_lon);

    *vyt = (FLOAT_32) (vxg * (-topo_sin_cos) -
                       vyg * topo_sin_sin +
                       vzg * topo_cos_lat);

    *vzt = (FLOAT_32) (vxg * topo_cos_cos +
                       vyg * topo_cos_sin +
                       vzg * topo_sin_lat);

} /* end of NIU_GeovelocityToTopovelocity */

/***************************************************************************
*  Routine name:  NIU_TopoeulerToGeoeuler                                  *
*                                                                          *
*  Description :  Convert SIMNET Euler Angles in RADIANS (Roll, Pitch, and *
*                 Yaw) into DIS Euler Angles in RADIANS (Phi, Theta, and   *
*                 Psi). Topocentric must be initialized prior to using     *
*                 this routine.                                            *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*  Author:  Huat Ng                                                        *
*                                                                          *
*  NOTE::                                                                  *
*  Routines obtained from IST Computer Generated Force Source (See file    *
*  SAFOR/PROTO/APP/DIS/DIS_COOR.CPP ).  Was called topoeuler_to_geoeuler   *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::NIU_TopoeulerToGeoeuler(
        FLOAT_32 inRoll,  FLOAT_32 inPitch,  FLOAT_32 inYaw,
        FLOAT_32 *psi,    FLOAT_32 *theta,   FLOAT_32 *phi)
{
    FLOAT_64
            cosInRoll,sinInRoll,    /* sin/cos of incoming simulator roll */
            cosInPitch,sinInPitch,  /* sin/cos of incoming simulator pitch */
            cosInYaw,sinInYaw;      /* sin/cos of incoming simulator yaw */
    FLOAT_64
            roll,pitch,yaw,         /* DIS's roll, pitch and yaw */
            A_sub_12, A_sub_11,
            A_sub_23, A_sub_33,
            poly1, poly2;
    FLOAT_64 val;

    /* */
    /* Values already obtained when Topocentric was initialized. */
    /* latitude == phi   longitude == lambda */
    /* */
    /* topo_cos_lat = cos(phi) */
    /* topo_sin_lat = sin(phi) */
    /* topo_cos_lon = cos(lambda) */
    /* topo_sin_lon = sin(lambda) */
    /* topo_sin_sin = sin(phi)*sin(lambda) */
    /* topo_sin_cos = sin(phi)*cos(lambda) */
    /* topo_cos_sin = cos(phi)*sin(lambda) */
    /* topo_cos_cos = cos(phi)*cos(lambda) */
    /* */

    cosInRoll = cos(inRoll);
    sinInRoll = sin(inRoll);

    cosInPitch = cos(inPitch);
    sinInPitch = sin(inPitch);

    cosInYaw = cos(inYaw);
    sinInYaw = sin(inYaw);

    /* */
    /* Calculate pitch for DIS */
    /* */
    val = (-topo_cos_lat*cosInYaw*cosInPitch -  topo_sin_lat*sinInPitch);
    pitch = asin(val);

    /* */
    /* Calculate yaw for DIS */
    /* */
    poly1 = sinInYaw*cosInPitch;
    poly2 = cosInYaw*cosInPitch;

    A_sub_12 =  topo_cos_lon*poly1-topo_sin_sin*poly2+topo_cos_sin*sinInPitch;
    A_sub_11 = -topo_sin_lon*poly1-topo_sin_cos*poly2+topo_cos_cos*sinInPitch;

    yaw = atan2(A_sub_12,A_sub_11);

    /* */
    /* Calculate roll for DIS */
    /* */
    A_sub_23 = topo_cos_lat *
            (-sinInYaw*cosInRoll+cosInYaw*sinInPitch*sinInRoll) -
            topo_sin_lat*cosInPitch*sinInRoll;

    A_sub_33 = topo_cos_lat *
            ( sinInYaw*sinInRoll+cosInYaw*sinInPitch*cosInRoll) -
            topo_sin_lat*cosInPitch*cosInRoll;

    roll = atan2(A_sub_23,A_sub_33);

    /* */
    /* Assign results of DIS yaw, pitch and roll */
    /* */
    *psi   = (FLOAT_32) yaw;
    *theta = (FLOAT_32) pitch;
    *phi   = (FLOAT_32) roll;

} /* end of NIU_TopoeulerToGeoeuler */

/***************************************************************************
*  Routine name:  NIU_GeoeulerToTopoeuler                                  *
*                                                                          *
*  Description :  Convert DIS Euler Angles (Phi, Theta, and Psi) into      *
*                 the simulator Euler Angles (Roll, Pitch, and Yaw).       *
*                 Topocentric initialization must be done prior to using   *
*                 this routine.                                            *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*  Author:  Huat Ng                                                        *
*                                                                          *
*  NOTE::                                                                  *
*  Routines obtained from IST Computer Generated Force Source (See file    *
*  SAFOR/PROTO/APP/DIS/DIS_COOR.CPP ).  Was called geoeuler_to_topoeuler   *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::NIU_GeoeulerToTopoeuler(
        FLOAT_32 psi,      FLOAT_32 theta,     FLOAT_32 phi,
        FLOAT_32 *outRoll, FLOAT_32 *outPitch, FLOAT_32 *outYaw )
{
    FLOAT_64
            inRoll,inPitch,inYaw,   /* Incoming DIS roll, pitch and yaw */
            roll,pitch,yaw,         /* the simulator's roll, pitch and yaw */
            cosInRoll,sinInRoll,    /* cos/sin of incoming roll */
            cosInPitch,sinInPitch,  /* cos/sin of incoming pitch */
            cosInYaw,sinInYaw;      /* cos/sin of incoming yaw */
    FLOAT_64
            B_sub_11, B_sub_12,
            B_sub_23, B_sub_33,
            poly1, poly2;
    FLOAT_64 val;

    inYaw   = psi;
    inPitch = theta;
    inRoll  = phi;

    /***************************************/
    /* Values already obtained when        */
    /* Topocentric() was initialized.      */
    /* latitude == phi longitude == lambda */
    /* */
    /* topo_cos_lat = cos(phi)             */
    /* topo_sin_lat = sin(phi)             */
    /* topo_cos_lon = cos(lambda)          */
    /* topo_sin_lon = sin(lambda)          */
    /* topo_sin_sin = sin(phi)*sin(lambda) */
    /* topo_sin_cos = sin(phi)*cos(lambda) */
    /* topo_cos_sin = cos(phi)*sin(lambda) */
    /* topo_cos_cos = cos(phi)*cos(lambda) */
    /***************************************/

    cosInRoll   = cos(inRoll);
    sinInRoll   = sin(inRoll);

    cosInPitch  = cos(inPitch);
    sinInPitch  = sin(inPitch);

    cosInYaw    = cos(inYaw);
    sinInYaw    = sin(inYaw);

    /* */
    /* Calculate pitch for the simulator */
    /* */

    val = (topo_cos_cos * cosInPitch * cosInYaw   +
           topo_cos_sin * cosInPitch * sinInYaw   -
           topo_sin_lat * sinInPitch);
    pitch = asin(val);


    /* */
    /* Calculate the yaw for the simulator */
    /* */
    poly1 = cosInPitch*cosInYaw;
    poly2 = cosInPitch*sinInYaw;

    B_sub_11 = -topo_sin_lon*poly1+topo_cos_lon*poly2;
    B_sub_12 = -topo_sin_cos*poly1-topo_sin_sin*poly2 - topo_cos_lat*sinInPitch;

    yaw = atan2(B_sub_11,B_sub_12);

    /* */
    /* Calculate the roll for the simulator */
    /* */
    B_sub_23 = topo_cos_cos *
            (-cosInRoll*sinInYaw+sinInRoll*sinInPitch*cosInYaw)     +
            topo_cos_sin *
            ( cosInRoll*cosInYaw + sinInRoll*sinInPitch*sinInYaw)   +
            topo_sin_lat *
            ( sinInRoll*cosInPitch);

    B_sub_33 =  topo_cos_cos *
            ( sinInRoll*sinInYaw + cosInRoll*sinInPitch*cosInYaw)   +
            topo_cos_sin *
            (-sinInRoll*cosInYaw + cosInRoll*sinInPitch*sinInYaw)   +
            topo_sin_lat *
            ( cosInRoll*cosInPitch);

    roll = atan2(-B_sub_23,-B_sub_33);

    *outYaw   = (FLOAT_32) yaw;
    *outPitch = (FLOAT_32) pitch;
    *outRoll  = (FLOAT_32) roll;

} /* end of NIU_GeoeulerToTopoeuler */

/******************************************************************************/
/* RAT, Added to save values for optimized                                    */
/******************************************************************************/
void CoordCnv::SaveGeocentricSinCos( void )
{
    saved_geod_sin_lat = sin(saved_geo.phi);
    saved_geod_cos_lat = cos(saved_geo.phi);
    saved_geod_sin_lon = sin(saved_geo.lambda);
    saved_geod_cos_lon = cos(saved_geo.lambda);
    saved_geod_sin_cos = saved_geod_sin_lat * saved_geod_cos_lon;
    saved_geod_sin_sin = saved_geod_sin_lat * saved_geod_sin_lon;
    saved_geod_cos_cos = saved_geod_cos_lat * saved_geod_cos_lon;
    saved_geod_cos_sin = saved_geod_cos_lat * saved_geod_sin_lon;

} /* end of SaveGeocentricSinCos */

/***************************************************************************
*  Routine name:  NIU_Initialize_WGS84                                     *
*                                                                          *
*  Description :  Sets up a mathematical model for the WGS84 spheroid.     *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::NIU_Initialize_WGS84()
{
    FLOAT_64 f;  /* WGS84 flattening constant */

    f = 1.0 - SEMI_MINOR/SEMI_MAJOR;

    e_sq  = f *  ( 2.0 - f );
    ep_sq = e_sq / ( 1.0 - e_sq );
    ef    = f / ( 2.0 - f );

    e_sq_to_3 = e_sq * e_sq * e_sq;
    ef_to_3   = ef * ef * ef;
    ef_to_4   = ef_to_3 * ef;

    /********************************************************************/
    /* (RAT, 9/30/92) Added the following variables for optimization... */
    /********************************************************************/
    poly1_a = 1.0 - e_sq / 4.0 - 3.0 * e_sq * e_sq
            / 64.0 - 5.0 * e_sq_to_3 / 256.0;

    poly2_a = 3.0 * ef / 2.0 - 27.0 * ef_to_3 / 32.0;
    poly3_a = 21.0 * ef * ef / 16.0 - 55.0 * ef_to_4 / 32.0;
    poly4_a = 151.0 * ef_to_3 / 96.0;
    poly5_a = 1097.0 * ef_to_4 / 512.0;

    poly1_b = 1.0 - (e_sq / 4.0) - (3.0 * e_sq * e_sq)
            / 64.0 - 5.0 * e_sq_to_3 / 256.0;

    poly2_b = 3.0*e_sq/8.0 + (3.0*e_sq*e_sq)/32.0 + 45.0*e_sq_to_3/1024.0;
    poly3_b = 15.0*e_sq*e_sq/256.0 + 45.0*e_sq_to_3/1024.0;
    poly4_b = 35.0*e_sq_to_3/3072.0;

} /* end of NIU_Initialize_WGS84 */

/***************************************************************************
*  Routine name:  NIU_UTMToGeodetic                                        *
*                                                                          *
*  Description :  Performs the conversion from UTM into Geodetic           *
*                 coordinates.                                             *
*                                                                          *
*   NOTICE : Subroutine initialize_WGS84 has to be called prior to using   *
*            NIU_UTMToGeodetic.                                            *
*                                                                          *
*            Equations are obtained from:                                  *
*            "Map Projections - A Working Manual" by John Snyder,          *
*            USGS Professional Paper 1395, pg. 63-64.                      *
*                                                                          *
*  Parameters  :                                                           *
*         Inbound  :                                                       *
*             UTM *utm  ( UTM location x,y,z (meters) )                    *
*         Outbound :                                                       *
*             GEO *geo  ( Geodetic coordinates, latitude (phi) and         *
*                         longitude (lambda) will be return in radians. )  *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::NIU_UTMToGeodetic( UTM *utm, GEO *geo )
{
    FLOAT_64 northing,   /* UTM Northing coordinate       */
            easting,    /* UTM Easting coordinate        */
            lambda0,    /* longitude of central meridian */
            M,
            poly1,      /* poly1 thru poly5 are used for */
            poly2,      /* storing the polynomials to    */
            poly3,      /* calculate phi1 and mu.        */
            // poly4,
            // poly5,
            phi1,       /* footpoint latitude            */
            mu,
            cos_phi1,   /* cos of phi1                   */
            sin_phi1,   /* sin of phi1                   */
            tan_phi1,   /* tan of phi1                   */
            sqrt_1_minus_poly1,
            C1,
            T1,
            N1,
            R1,
            D,
            T1_sq,      /* T1 square                     */
            C1_sq,      /* C1 square                     */
            D_sq,       /* D square                      */
            D_cube,     /* D cube                        */
            D_four,     /* D to the power 4              */
            D_five,     /* D to the power 5              */
            D_six;      /* D to the power 6              */

    FLOAT_64 sqrt_term;

    /* Calculate false easting and northing.   Since Hunter_Liggett */
    /* is northern hemisphere, the northing will not change.        */

    northing = utm->northing - False_North;
    easting  = utm->easting  - False_East;

    /* Calculate longitude of the central meridian.  Hunter-Ligget  */
    /* is in zone 10.  lambda0 (in radians) = (zone*6-183)*2PI/360  */

    lambda0 = Lambda0;

    /* Calculate true distance along central meridian from equator  */
    /* to phi.  Scale on central meridian for UTM is 0.9996.        */

    M = northing/CENTRAL_SCALE;

    /* Calculate mu and phi1 */

    /***********************************************************/
    /* (RAT, 9/30/92) Changed mu and phi1 calc. to use poly#_a */
    /* instead of local variables poly#.                       */
    /***********************************************************/
    mu = M/(SEMI_MAJOR*poly1_a);
    phi1 = mu + poly2_a*sin(2.0*mu) + poly3_a*sin(4.0*mu) +
            poly4_a*sin(6.0*mu) + poly5_a*sin(8.0*mu);

    /* Calculate the trigonometric functions for phi1 */

    cos_phi1 = cos(phi1);
    sin_phi1 = sin(phi1);
    tan_phi1 = sin_phi1/cos_phi1;

    /* Calculate C1, T1, N1, R1, and D                         */
    /* NOTE: the constant names have been kept the same as the */
    /* referenced text as stated above.                        */

    C1    = ep_sq*cos_phi1*cos_phi1;
    T1    = tan_phi1*tan_phi1;
    poly1 = e_sq*sin_phi1*sin_phi1;

    sqrt_term = 1.0 - poly1;

    if (sqrt_term == 0.0)
    {
        sqrt_term = 1.0;
    }
    else if (sqrt_term < 0.0)
    {
        sqrt_term *= -1.0;
    }

    sqrt_1_minus_poly1 = sqrt(sqrt_term);

    N1    = SEMI_MAJOR / sqrt_1_minus_poly1;
    R1    = ( SEMI_MAJOR * ( 1.0 - e_sq ) ) /
            ( ( 1.0 - poly1 ) * sqrt_1_minus_poly1 );
    D     = easting /( N1 * CENTRAL_SCALE );

    /* calculate the powers of D, C1, and T1 */

    D_sq   = D*D;
    D_cube = D_sq*D;
    D_four = D_cube*D;
    D_five = D_four*D;
    D_six  = D_five*D;

    C1_sq  = C1*C1;
    T1_sq  = T1*T1;

    /* calculate the latitude (phi) */

    poly1 = D_sq/2.0;
    poly2 = 5.0 + 3.0*T1 + 10.0*C1 - 4.0*C1_sq - 9.0*ep_sq;
    poly3 = 61.0 + 90.0*T1 + 298.0*C1 + 45.0*T1_sq - 252.0*ep_sq - 3.0*C1_sq;

    geo->phi = phi1 - ( N1 * tan_phi1 / R1 )
            * ( poly1-poly2 * D_four / 24.0 + poly3 * D_six / 720.0 );

    /* calculate the longitude (lambda) */

    poly1 = 1.0 + 2.0*T1 + C1;
    poly2 = 5.0 - 2.0*C1 + 28.0*T1 - 3.0*C1_sq + 8.0*ep_sq + 24.0*T1_sq;

    geo->lambda = lambda0 +(D - poly1*D_cube/6.0 + poly2*D_five/120.0)/cos_phi1;
} /* end of NIU_UTMToGeodetic */

/***************************************************************************
*  Routine name:  NIU_GeodeticToUTM                                        *
*                                                                          *
*  Description :  Performs the conversion from Geodetic into UTM           *
*                 coordinates.                                             *
*                                                                          *
*   NOTICE : Subroutine initialize_WGS84 has to be called prior to using   *
*            NIU_UTMToGeodetic.                                            *
*                                                                          *
*            Equations are obtained from:                                  *
*            "Map Projections - A Working Manual" by John Snyder,          *
*            USGS Professional Paper 1395, pg. 63-64.                      *
*                                                                          *
*  Parameters  :                                                           *
*         Inbound  :                                                       *
*             GEO *geo  ( Geodetic coordinates, latitude (phi) and         *
*                         longitude (lambda) in radians. )                 *
*         Outbound :                                                       *
*             UTM *utm  ( UTM location x,y,z (meters) )                    *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::NIU_GeodeticToUTM( GEO *geo, UTM *utm )
{
    FLOAT_64 lambda0,   /* longitude of central meridian          */
            cos_phi,   /* cosine of phi                          */
            sin_phi,   /* sin of phi                             */
            tan_phi,   /* tan of phi                             */
            poly1,     /* poly1 thru poly5 are polynomials for   */
            poly2,     /* calculating eq. 3-21 pg. 61 of source. */
            // poly3,
            // poly4,
            // poly5,
            N,T,C,A,M,
            T_sq,      /* T*T                                    */
            C_sq,      /* C*C                                    */
            A_sq,      /* A*A                                    */
            A_cube,    /* A to the power of 3                    */
            A_four,    /* A to the power of 4                    */
            A_five,    /* A to the power of 5                    */
            A_six;     /* A to the power of 6                    */
    FLOAT_64 sqrt_term;

    /* assign value to central meridian for zone 10, where       */
    /* Hunter-Liggett database lies.  lambda0 is in radians.     */
    /* lambda0 = (zone*6 - 183)*(2PI/360)                        */

    lambda0 = Lambda0;

    /* calculate the trigonometry functions of phi and lambda    */

    cos_phi = cos(geo->phi);
    sin_phi = sin(geo->phi);
    tan_phi = sin_phi/cos_phi; /* (RAT, 10/1/92) Replaced tan(geo->phi) */

    /* calculate the needed polynomials */
    /* note:  one term is missing for each polynomial */
    /* and also poly5 is missing compared with BBN.   */

    /*************************************************************************/
    /* (RAT, 9/30/92) The following 4 polynomials are now calculated in      */
    /* Initialize_WGS84 and saved in poly#_b globals. This is for optimizing.*/
    /*************************************************************************/
    /**(RAT)*************************************************************
    poly1 = 1.0 - (e_sq/4.0) - (3.0*e_sq*e_sq)/64.0 -
            5.0*pow(e_sq,3.0)/256.0;
    poly2 = 3.0*e_sq/8.0 + (3.0*e_sq*e_sq)/32.0 +
            45.0*pow(e_sq, 3.0)/1024.0;
    poly3 = 15.0*e_sq*e_sq/256.0 + 45.0*pow(e_sq, 3.0)/1024.0;
    poly4 = 35.0*pow(e_sq, 3.0)/3072.0;
   ********************************************************************/


    /* calculate the constants N, T, C, A, M */
    /* note: the constants names have been kept the same as the */
    /* referenced text as stated above.                         */

    sqrt_term = 1.0 - e_sq*sin_phi*sin_phi;

    if (sqrt_term == 0.0)
    {
        sqrt_term = 1.0;
    }
    else if (sqrt_term < 0.0)
    {
        sqrt_term *= -1.0;
    }

    N = SEMI_MAJOR/sqrt(sqrt_term);
    T = tan_phi*tan_phi;
    C = ep_sq*cos_phi*cos_phi;
    A = (geo->lambda - lambda0)*cos_phi;

    /******************************************************/
    /* (RAT, 9/30/92) replaced poly# with globals poly#_b */
    /******************************************************/
    M = SEMI_MAJOR * ( poly1_b * geo->phi -
                       poly2_b * sin( 2.0 * geo->phi ) +
                       poly3_b * sin( 4.0 * geo->phi ) -
                       poly4_b * sin( 6.0 * geo->phi ) );

    /* calculate the powers of T, C, and A from above */

    T_sq   = T*T;
    C_sq   = C*C;
    A_sq   = A*A;
    A_cube = A_sq*A;
    A_four = A_cube*A;
    A_five = A_four*A;
    A_six  = A_five*A;

    /* calculate easting (x) */

    poly1  =  1.0 - T + C;
    poly2  =  5.0 - 18.0*T + T_sq + 72.0*C - 58.0*ep_sq;
    utm->easting = CENTRAL_SCALE*N*(A + poly1*A_cube/6.0 + poly2*A_five/120.0);

    /* calculate the northing (y) */

    poly1  =  5.0 - T + 9.0*C + 4.0*C_sq;
    poly2  =  61.0 - 58.0*T + T_sq + 600.0*C - 330.0*ep_sq;
    utm->northing = CENTRAL_SCALE * ( M + N * tan_phi * ( A_sq / 2.0 +
                                                          poly1 * A_four / 24.0
                                                          + poly2 * A_six  / 720.0));

    /* add false northing and easting */

    utm->northing += False_North;
    utm->easting  += False_East;

} /* end of NIU_GeodeticToUTM */

/***************************************************************************
*  Routine name:  NIU_UTMToGeocentric                                      *
*                                                                          *
*  Description :  Performs the conversion from Universal Transverse        *
*                 Mercator (UTM) coordinates to geocentric coordinates     *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*   NOTICE: MUST BE CALLED ONCE BEFORE utmvel_to_geovel AND                *
*           NIU_UTMEulerToGeoEuler!!!!!!!!!!!!!!!!                         *
*                                                                          *
*  Author: Huat Ng, IST.                                                   *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::NIU_UTMToGeocentric( FLOAT_64 xu,  FLOAT_64 yu,  FLOAT_64 zu,
                                    FLOAT_64 *xg, FLOAT_64 *yg, FLOAT_64 *zg )
{
    UTM     database_utm;
    FLOAT_64 X, Y, Z;       /* geocentric coordinates */

    database_utm.easting  = xu;
    database_utm.northing = yu;

    /* calls NIU_UTMToGeodetic to perform utm to geodetic conversion */

    NIU_UTMToGeodetic(&database_utm, &saved_geo);

    /* converts geodetic to geocentric */

    NIU_GeodeticToGeocentric(saved_geo.phi, saved_geo.lambda, zu,
                             &X, &Y, &Z);

    /* assigns the geocentric coordinates */

    *xg = X;
    *yg = Y;
    *zg = Z;

    /*************************************************************/
    /* (RAT, 10/7/92) Calculate sin and cos for optimizing...... */
    /*************************************************************/
    SaveGeocentricSinCos();

} /* end of NIU_UTMToGeocentric */

/***************************************************************************
*  Routine name:  NIU_UTMLocalToUTM                                        *
*                                                                          *
*  Description :  Performs the conversion from a local coordinate          *
*                 Universal Transverse Mercator (UTM) projection described *
*                 by the origin listed in database.def to straight UTM.    *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*  Author: Gary Hall.                                                      *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  10-Sept 1996 Documented                                                 *
***************************************************************************/
void CoordCnv::NIU_UTMLocalToUTM( FLOAT_64  xl, FLOAT_64  yl, FLOAT_64  zl,
                                  FLOAT_64 *xu, FLOAT_64 *yu, FLOAT_64 *zu )
{
    /* add the utm offset to the x and y coordinates */

    *xu = Database_Origin_X + xl;
    *yu = Database_Origin_Y + yl;
    *zu = zl;

} /* end of NIU_UTMLocalToUTM */

/***************************************************************************
*  Routine name:  NIU_UTMToUTMLocal                                        *
*                                                                          *
*  Description :  Performs the conversion from Universal Transverse        *
*                 Mercator (UTM) projection to a Local UTM described       *
*                 by the origin listed in database.def to straight UTM.    *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*  Author: Gary Hall.                                                      *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  10-Sept 1996 Documented                                                 *
***************************************************************************/
void CoordCnv::NIU_UTMToUTMLocal( FLOAT_64  xu, FLOAT_64  yu, FLOAT_64  zu,
                                  FLOAT_64 *xl, FLOAT_64 *yl, FLOAT_64 *zl )
{
    /* add the utm offset to the x and y coordinates */

    *xl = xu - Database_Origin_X;
    *yl = yu - Database_Origin_Y;
    *zl = zu;

} /* end of NIU_UTMToUTMLocal */

/***************************************************************************
*  Routine name:  NIU_UTMLocalToGeocentric                                 *
*                                                                          *
*  Description :  Performs the conversion from a local coordinate          *
*                 Universal Transverse Mercator (UTM) projection described *
*                 by the origin listed in database.def to geocentric       *
*                 coordinates with applied offset.                         *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*   NOTICE: MUST BE CALLED ONCE BEFORE utmvel_to_geovel AND                *
*           NIU_UTMEulerToGeoEuler!!!!!!!!!!!!!!!!                         *
*                                                                          *
*  Author: Huat Ng, IST.                                                   *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::NIU_UTMLocalToGeocentric( FLOAT_64  xu, FLOAT_64  yu, FLOAT_64  zu,
                                         FLOAT_64 *xg, FLOAT_64 *yg, FLOAT_64 *zg )
{
    FLOAT_64  adj_xu, adj_yu;

    /* add the utm offset to the x and y coordinates */

    adj_xu = Database_Origin_X + xu;
    adj_yu = Database_Origin_Y + yu;

    NIU_UTMToGeocentric( adj_xu, adj_yu, zu,
                         xg,     yg, zg );

} /* end of NIU_UTMLocalToGeocentric */


/***************************************************************************
*  Routine name:  NIU_GeocentricToUTM                                      *
*                                                                          *
*  Description :  Performs the conversion from geocentric coordinates      *
*                 into Universal Transverse Mercator (UTM) coordinates.    *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*   NOTICE: MUST BE CALLED ONCE BEFORE geovelocity_to_utmvelocity AND      *
*           NIU_GeoEulerToUTMEuler!!!!!!!!!!!!!!!!                         *
*                                                                          *
*  Author: Huat Ng, IST.                                                   *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::NIU_GeocentricToUTM( FLOAT_64 xg,  FLOAT_64 yg,  FLOAT_64 zg,
                                    FLOAT_64 *xu, FLOAT_64 *yu, FLOAT_64 *zu )
{

    UTM  database_utm;
    FLOAT_64 latitude, longitude, height;

    /* Converts geocentric to geodetic */

    NIU_GeocentricToGeodetic(xg, yg, zg, &latitude, &longitude, &height);

    /* Assigns the variables */

    saved_geo.phi    = latitude;
    saved_geo.lambda = longitude;

    /*************************************************************/
    /* (RAT, 10/7/92) Calculate sin and cos for optimizing...... */
    /*************************************************************/
    SaveGeocentricSinCos();

    /* converts geodetic to utm */

    NIU_GeodeticToUTM(&saved_geo, &database_utm);

    /* Compensate for the UTM origin */

    *xu = database_utm.easting ;
    *yu = database_utm.northing;
    *zu = height;

} /* end of NIU_GeocentricToUTM */

/***************************************************************************
*  Routine name:  NIU_GeocentricToUTMLocal                                 *
*                                                                          *
*  Description :  Performs the conversion from geocentric coordinates      *
*                 into a Universal Transverse Mercator (UTM) projection    *
*                 in the local data coordinates described by the origin    *
*                 listed in database.def                                   *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*   NOTICE: MUST BE CALLED ONCE BEFORE geovelocity_to_utmvelocity AND      *
*           NIU_GeoEulerToUTMEuler!!!!!!!!!!!!!!!!                         *
*                                                                          *
*  Author: Huat Ng, IST.                                                   *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::NIU_GeocentricToUTMLocal( FLOAT_64  xg, FLOAT_64  yg, FLOAT_64  zg,
                                         FLOAT_64 *xu, FLOAT_64 *yu, FLOAT_64 *zu )
{

    NIU_GeocentricToUTM( xg, yg, zg, xu, yu, zu );

    *xu -= Database_Origin_X;
    *yu -= Database_Origin_Y;

} /* end of NIU_GeocentricToUTM */

/***************************************************************************
*  Routine name:  CalcFalseNorthEast                                       *
*                                                                          *
*  Description :  Calculate false north and east values for WGS 84.        *
*                                                                          *
*  Parameters  :  FLOAT_64 lat_rad    The latitude in radians              *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::CalcFalseNorthEast ( FLOAT_64 latitude_radians )
{
    if (latitude_radians  >= 0.0)
    {
        False_North = 0.0;
        False_East  = 500000.0;
    }
    else
    {
        False_North = 10000000.0;
        False_East  =   500000.0;
    }
}

/***************************************************************************
*  Routine name:  CalcZone                                                 *
*                                                                          *
*  Description :  Calculate origin zone for WGS 84                         *
*                                                                          *
*  Parameters  :  FLOAT_64 longitude_radians  Longitude in radians         *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
FLOAT_64 CoordCnv::CalcZone(FLOAT_64 longitude_radians)
{
    FLOAT_64 longitude_deg = fabs( longitude_radians * (180.0 / M_PI) );
    FLOAT_64 zone;

    if (longitude_radians >= 0.0)
    {
        zone = floor( ( longitude_deg / 6.0 ) ) + 31;
    }
    else
    {
        zone = 30 - floor( ( longitude_deg / 6.0 ) );
    }

    return zone;

}

/***************************************************************************
*  Routine name:  CalcLambda0                                              *
*                                                                          *
*  Description :  Calculate lambda 0 for particular zone.                  *
*                                                                          *
*  Parameters  :  FLOAT_64 zone                                            *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::CalcLambda0(FLOAT_64 zone)
{
    Lambda0 = 0;
    if ( (zone < 31) && ( zone > 0) )      /* 1-30 */
    {
        Lambda0 = (zone * 6.0 - 183.0) * (M_PI/180.0);
    }
    else if ( (zone > 30) && (zone < 61) ) /* 31-60 */
    {
        Lambda0 = ((zone - 31.0) * 6.0 + 3.0) * (M_PI/180.0);
    }

}

/***************************************************************************
*  Routine name:  CalcDatabaseOrigin                                       *
*                                                                          *
*  Description :  Calculate database origin in UTM                         *
*                                                                          *
*  Parameters  :  FLOAT_64 latitude                                        *
*                 FLOAT_64 longitude                                       *
*                 FLOAT_64 height                                          *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::CalcDatabaseOrigin(
        FLOAT_64 latitude,
        FLOAT_64 longitude,
        FLOAT_64 height)
{
    FLOAT_64 gcx,  gcy,  gcz; /* geocentric */
    FLOAT_64 utmx, utmy, utmz; /* UTM */

    /* Zero Origin -- ie. used in NIU_GeocentricToUTM */
    Database_Origin_X = 0.0;
    Database_Origin_Y = 0.0;

    NIU_GeodeticToGeocentric(latitude, longitude, height, &gcx, &gcy, &gcz);

    NIU_GeocentricToUTM(gcx, gcy, gcz, &utmx, &utmy, &utmz);

    Database_Origin_X = utmx;
    Database_Origin_Y = utmy;

#ifdef FNIU_DEBUG

    fprintf(stderr, "Debug Database_Origin_X %lf \n", Database_Origin_X );
    fprintf(stderr, "Debug Database_Origin_Y %lf \n", Database_Origin_Y );

#endif

}

/***************************************************************************
*  Routine name:  NIU_InitializeCoordinates                                *
*                                                                          *
*  Description :  Central routine to initialize all coordinate conversion  *
*                 routines for a new center of gaming area.                *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
*  29-Nov 1995 Documented                                                  *
***************************************************************************/
void CoordCnv::NIU_InitializeCoordinates( FLOAT_64 lat_rad,
                                          FLOAT_64 lon_rad,
                                          FLOAT_64 hgt_mtr)
{
    NIU_InitializeTopocentric(lat_rad, lon_rad, hgt_mtr);
    NIU_Initialize_WGS84();

    CalcFalseNorthEast(lat_rad);

    Zone = CalcZone(lon_rad);

    CalcLambda0(Zone);
    CalcDatabaseOrigin(lat_rad,lon_rad,hgt_mtr);
}

/***************************************************************************
*  Routine name:  NIU_UTMVelocityToGeoVelocity                             *
*                                                                          *
*  Description :  Convert UTM veloctiy into Geocentric Velocity.           *
*                 NIU_UTMToGeocentric(...) must be called first to         *
*                 initialize the constants.                                *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
***************************************************************************/
void CoordCnv::NIU_UTMVelocityToGeoVelocity
(
        FLOAT_32 srcx,   FLOAT_32 srcy,   FLOAT_32 srcz,
        FLOAT_32 *destx, FLOAT_32 *desty, FLOAT_32 *destz
        )
{
    /* apply the rotation matrix to the velocity vector */

    *destx = (FLOAT_32) (srcx * (-saved_geod_sin_lon) -
                         srcy * saved_geod_sin_cos +
                         srcz * saved_geod_cos_cos);

    *desty = (FLOAT_32) (srcx * saved_geod_cos_lon -
                         srcy * saved_geod_sin_sin +
                         srcz * saved_geod_cos_sin);

    *destz = (FLOAT_32) (srcy * saved_geod_cos_lat +
                         srcz * saved_geod_sin_lat);
}

/***************************************************************************
*  Routine name:  NIU_GeoVelocityToUTMVelocity                             *
*                                                                          *
*  Description :  Convert Geocentric Velocity into UTM Velocity.           *
*                 NIU_GeocentricToUTM(...) must be called first to         *
*                 initialize the constants.                                *
*                                                                          *
*  Parameters  :                                                           *
*                                                                          *
*  Returns                                                                 *
*  (Success)   :  N/A                                                      *
*  (Failure)   :  N/A                                                      *
*                                                                          *
*  Revision History:                                                       *
*                                                                          *
***************************************************************************/
void CoordCnv::NIU_GeoVelocityToUTMVelocity
(
        FLOAT_32 srcx,   FLOAT_32 srcy,   FLOAT_32 srcz,
        FLOAT_32 *destx, FLOAT_32 *desty, FLOAT_32 *destz
        )
{
    /* multiplying the velocity vector in DIS with the rotation matrix */

    *destx = (FLOAT_32) (srcx * (-saved_geod_sin_lon) +
                         srcy * saved_geod_cos_lon);

    *desty = (FLOAT_32) (srcx * (-saved_geod_sin_cos) -
                         srcy * saved_geod_sin_sin +
                         srcz * saved_geod_cos_lat);

    *destz = (FLOAT_32) (srcx * saved_geod_cos_cos +
                         srcy * saved_geod_cos_sin +
                         srcz * saved_geod_sin_lat);
}

