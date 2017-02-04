//--------------------------------------------------------
// Copyright © 2009 by APTUS. All rights reserved.
//--------------------------------------------------------
// DESCRIPTION : Implementation of UtmMgrs
//    The util class for UTM & MGRS 
// DATE : 05/01/2009
// AUTHOR : Sotheavut UK
// PROJECT: SCIP1_PAC14
// MODULE:  SDKLVB
//--------------------------------------------------------

#include "UtmMgrs.h"
#include "utm.h"
#define _USE_MATH_DEFINES
#include <math.h>

#define _180onPI (57.295779513)


void UtmMgrs::convertDecimalDegreeToDegMinSec( double decDegree, int& degrees, int& minutes, float& seconds )
{
	int tmpDegrees = 0;
	int tmpMinutes = 0;

	tmpDegrees = (int)floor (decDegree);
	double res = ( decDegree - (double)tmpDegrees ) * 60.0;

	tmpMinutes  = (int)floor (res);
	seconds  = (float)( (float)(res - (double)tmpMinutes) * 60.0f );

	degrees = tmpDegrees;
	minutes = tmpMinutes;
}

bool UtmMgrs::convertUTMtoGeodeticDegMinSec( int zone, char hemisphere, double easting, double northing, UtmMgrs::OrientationMDS& latOrientationMDS, UtmMgrs::OrientationMDS& longOrientationMDS )
{
	double latitude  = 0.0;
	double longitude = 0.0;

	long res = Convert_UTM_To_Geodetic ( zone, hemisphere, easting, northing, &latitude, &longitude );
	if ( UTM_NO_ERROR != res )
	{
			return false;
	}

	// Radian to Degree:
	latitude  = latitude  * _180onPI;
	longitude = longitude * _180onPI;

	if ( latitude >= 0.0 )
	{
		latOrientationMDS.ExWxNxS = 'N';
	}
	else
	{
		latOrientationMDS.ExWxNxS = 'S';
		latitude = fabs( latitude );
	}

	if ( longitude >= 0.0 )
	{
		longOrientationMDS.ExWxNxS = 'E';
	}
	else
	{
		longOrientationMDS.ExWxNxS = 'W';
		longitude = fabs( longitude );
	}

	UtmMgrs::convertDecimalDegreeToDegMinSec( latitude,  latOrientationMDS.degrees,  latOrientationMDS.minutes,  latOrientationMDS.secondes );
	UtmMgrs::convertDecimalDegreeToDegMinSec( longitude, longOrientationMDS.degrees, longOrientationMDS.minutes, longOrientationMDS.secondes );

	return true;
}

