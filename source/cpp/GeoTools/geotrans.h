#ifndef _GEOTRANS_H_
#define _GEOTRANS_H_

#include "../qtplus_global.h"

/**
        @class	GeoTrans
        @brief	Classe de conversion de coordonn?es
        @author	Guillaume DARIER
        @date	06/10/2010

        Faire un appel ? Initialize en sp?cifiant les coordonn?es
        de r?f?rence avant utilisation
**/

#include <string>
using namespace std;

class QTPLUSSHARED_EXPORT GeoTrans
{

public:

        static void mgrsToLatLong (std::string UTMPosition, double& _latitude, double& _longitude, char& _latOrient, char& _longOrient);
        static long Convert_Geodetic_To_UTM (double Latitude, double Longitude, long *Zone, char *Hemisphere, double *Easting, double *Northing);
        static long Convert_UTM_To_Geodetic(long Zone, char Hemisphere, double Easting, double Northing, double *Latitude, double *Longitude);
        static long Convert_Geodetic_To_MGRS (double Latitude, double Longitude, long Precision, char* MGRS);

        static void DegreeToDegMinSec (double Degree, int* Deg, int* Min, int* Sec);

public:

    static const double POS_Q3D_INFINITY;
    static const double NEG_Q3D_INFINITY;
    static const double PI;
    static const double TWO_PI;
    static const double HALF_PI;
        static const double fDeg2Rad;
        static const double fRad2Deg;
};

#endif // _GEOTRANS_H_

