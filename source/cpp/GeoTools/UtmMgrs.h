//--------------------------------------------------------
// Copyright © 2009 by APTUS. All rights reserved.
//--------------------------------------------------------
// DESCRIPTION : Interface of UtmMgrs
//    The util class for UTM & MGRS 
// DATE : 05/01/2009
// AUTHOR : Sotheavut UK
// PROJECT: SCIP1_PAC14
// MODULE:  SDKLVB
//--------------------------------------------------------

#pragma once


/*! \class UtmMgrs
\brief
\author Sotheavut UK
\date 05/01/2009
*/
#include "../qtplus_global.h"

class QTPLUSSHARED_EXPORT UtmMgrs
{
public:
    typedef struct _OrientationMDS
    {
        int degrees;
        int minutes;
        float secondes;
        char ExWxNxS;
    } OrientationMDS;


    /*! The function convertDecimalDegreeToDegMinSec converts Decimal degrees into degree, minutes, seconds
     \param  decDegree         : Decimal degrees                        (input)
     \param  degrees           : degree                                 (output)
     \param  minutes           : minutes                                (output)
     \param  seconds           : seconds                                (output)
     */
    static void convertDecimalDegreeToDegMinSec( double decDegree, int& degrees, int& minutes, float& seconds );


    /*! The function convertUTMtoGeodeticDegMinSec converts UTM projection (zone, hemisphere, easting and northing)
     * coordinates to geodetic (latitude and  longitude) coordinates, according to the current ellipsoid parameters.
     * The latitude and  longitude are in the format of DEGREES, MUNIUTES, SECONDS wwhich are members of latOrientationMDS and longOrientationMDS.
     *
     \param  zone              : UTM zone                               (input)
     \param  hemisphere        : North or South hemisphere              (input)
     \param  easting           : Easting (X) in meters                  (input)
     \param  northing          : Northing (Y) in meters                 (input)
     \param  latOrientationMDS : Latitude in Deg,Min,Sec                (output)
     \param  longOrientationMDS: Longitude in Deg,Min,Sec               (output)
     */
    static bool convertUTMtoGeodeticDegMinSec( int zone, char hemisphere, double easting, double northing, UtmMgrs::OrientationMDS& latOrientationMDS, UtmMgrs::OrientationMDS& longOrientationMDS );

private:
    UtmMgrs(){}
    ~UtmMgrs(){}
};


