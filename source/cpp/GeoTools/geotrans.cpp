/**
        @file			GeoTrans.cpp
        @brief			Librairie de conversion de coordonn?es
        @author			Guillaume DARIER
        @date			06/10/2010
**/

#include "geotrans.h"

#include <vector>
#include <float.h>
#include <limits>
#include <string.h>

#ifndef WIN32
#include <cstdio>
#endif

#include "utm.h"
#include "geocent.h"
#include "coordcnv.h"
#include "mgrs.h"

using namespace std;

//-------------------------------------------------------------------------------------------------

const double GeoTrans::POS_Q3D_INFINITY = std::numeric_limits<double>::infinity();
const double GeoTrans::NEG_Q3D_INFINITY = -std::numeric_limits<double>::infinity();
const double GeoTrans::PI = 4.0 * atan( 1.0 );
const double GeoTrans::TWO_PI = 2.0 * PI;
const double GeoTrans::HALF_PI = 0.5 * PI;
const double GeoTrans::fDeg2Rad = PI / 180.0;
const double GeoTrans::fRad2Deg = 180.0 / PI;

//-------------------------------------------------------------------------------------------------

void GeoTrans::mgrsToLatLong( std::string UTMPosition, double& _latitude, double& _longitude, char& _latOrient, char& _longOrient)
{
#ifdef WIN32
    _controlfp_s( NULL, _PC_64, _MCW_PC);
#endif

        /*
        *    UTMPosition        : UTM position (ex: 35000;05000;31U;DQ)	(input)
        *    _latitude			: Latitude in Degrees decimal           (output)
        *    _longitude         : Longitude in Degrees decimal          (output)
        *    _latOrient         : N(ord)or S(outh)						(output)
        *    _longOrient        : E(st) or W(est)						(output)
        */

        // Reference in SCIPIA upper left corner :
        // MGRS : 31 TEJ 09879 65184
        // UTM : Easting 509879 Northing 4865184 Timezone 31
        // Long : 3.1230947?E / Lat : 43.9397103?N  (Degrees decimal)
        // Long : 3?07.38568E / Lat : 43?56.38262N  (Degrees Minutes)
        // Long : 3?7'23.1" E / Lat : 43?56'23.0" N (Degrees Minutes Seconds)
        // X : -178.9 m / Y : -199.1 m

        /* get longitude and latitude */
        double coord_x = 0, coord_y = 0;
        long zone = 0;
        long precision = 0;
        char hemisphere[2], subgrid[3], MGRS[16];
        const char* trame=UTMPosition.c_str();
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int letters[3];

        memset(hemisphere, 0, sizeof(hemisphere));
        memset(subgrid, 0, sizeof(subgrid));

        // R?cup?ration des donn?es Position dans la trame
    sscanf((const char*)UTMPosition.c_str(),"%lf;%lf;%2ld%1s;%2s", &coord_x, &coord_y, &zone, hemisphere, subgrid);

        // Pr?cision
        precision = static_cast<long>((UTMPosition.length() - 8.0)/2.0);

        //Code geographique
        letters[0]=alphabet.find(hemisphere[0]);
        letters[1]=alphabet.find(subgrid[0]);
        letters[2]=alphabet.find(subgrid[1]);

        Make_MGRS_String(MGRS, zone, letters, coord_x, coord_y, precision);

        Convert_MGRS_To_Geodetic((char*)&MGRS, &_latitude,&_longitude);

        // Results are in radians
        // Conversion in degrees
        _latitude = _latitude * 180.0 / PI;
        _longitude = _longitude * 180.0 / PI;


        if ( _latitude >= 0.0f)
                _latOrient = 'N';
        else
                _latOrient = 'S';

        if ( _longitude >= 0.0f)
                _longOrient = 'E';
        else
                _longOrient = 'W';
}

//-------------------------------------------------------------------------------------------------

long GeoTrans::Convert_Geodetic_To_UTM (double Latitude, double Longitude, long *Zone, char *Hemisphere, double *Easting, double *Northing)
{
        return ::Convert_Geodetic_To_UTM(Latitude, Longitude, Zone, Hemisphere, Easting, Northing);
}

//-------------------------------------------------------------------------------------------------

long GeoTrans::Convert_UTM_To_Geodetic(long Zone, char Hemisphere, double Easting, double Northing, double *Latitude, double *Longitude)
{
        return ::Convert_UTM_To_Geodetic(Zone, Hemisphere, Easting, Northing, Latitude, Longitude);
}

//-------------------------------------------------------------------------------------------------

long GeoTrans::Convert_Geodetic_To_MGRS (double Latitude, double Longitude, long Precision, char* MGRS)
{
        return ::Convert_Geodetic_To_MGRS(Latitude, Longitude, Precision, MGRS);
}

//-------------------------------------------------------------------------------------------------

void GeoTrans::DegreeToDegMinSec(double Degree, int* Deg, int* Min, int* Sec)
{
        *Deg = (int) Degree;
        Degree = fabs(Degree) - fabs((double) *Deg);
        Degree *= 60.0;
        *Min = (int) Degree;
        Degree = fabs(Degree) - fabs((double) *Min);
        Degree *= 60.0;
        *Sec = (int) Degree;
}
