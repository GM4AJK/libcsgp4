/*
 * Copyright 2022 Andy Kirkham
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cmath>

#include "csgp4/LunarModel.h"

#include "csgp4/Globals.h"
#include "csgp4/Util.h"

namespace csgp4
{

LunarModel::LunarModel(const DateTime& dt)
{
    Initialise(dt);
}

void 
LunarModel::Initialise(const DateTime& dt)
{
    _atDateTime = dt;
    _atTime_JD  = dt.ToJulian();
}

// Define to display extra data in Unit tests, don't commit as defined!
// #define UT_SHOW_DATA

CoordsLunarModel
LunarModel::Position()
{
    SunModel sp(_atDateTime);
    CoordsSunModel sun = sp.Position();
    double d2r = M_PI/180.0;
    double lo = 91.929336;	// Moon's mean longitude at epoch 2010.0
    double Po = 130.143076;	// Mean longitude of the perigee at epoch.
    double No = 291.682547;	// Mean longitude of the node at the epoch.
    double i  = 5.145396;   // Inclination of Moon's orbit.
    double e  = 0.0549;	    // Eccentricity of the Moon's orbit.
    double l  = Util::Wrap360(13.1763966 * sun._D + lo);
    if(l < 0) l += 360.0;
    double Mm = Util::Wrap360(l - 0.1114041 * sun._D - Po);
    if(Mm < 0) Mm += 360.0;
    double N = Util::Wrap360(No - 0.0529539 * sun._D);
    if(N < 0) N += 360.0;
    double C = l - sun._ecliptic_lon;
    double Ev = 1.2739 * std::sin(((2 * C) - Mm) * d2r);
    double sinMo = std::sin(Util::DegreesToRadians(sun._Mo));
    double Ae = 0.1858 * sinMo;
    double A3 = 0.37 * sinMo;
    double Mprimem = Mm + Ev - Ae - A3;
    double Ec = 6.2886 * std::sin(Util::DegreesToRadians(Mprimem));
    double A4 = 0.214 * std::sin(Util::DegreesToRadians(2 * Mprimem));
    double lprime = l + Ev + Ec - Ae + A4;
    double V = 0.6583 * std::sin(Util::DegreesToRadians(2 * (lprime-sun._ecliptic_lon)));
    double lprimeprime = lprime + V;
    double Nprime = N - 0.16 * sinMo;
    double lppNp = Util::DegreesToRadians(lprimeprime-Nprime);
    double sinlppNp = std::sin(lppNp);
    double y = sinlppNp * std::cos(Util::DegreesToRadians(i));
    double x = std::cos(lppNp);
    double lm = std::atan2(y,x)/d2r + Nprime;
    double Bm = std::asin(sinlppNp * std::sin(i*d2r))/d2r;
    if(lm > 360) lm -= 360.0;
    CoordsLunarModel rval = CoordsLunarModel(
        Util::DegreesToRadians(Bm), 
        Util::DegreesToRadians(lm), 
        sun
    );
    rval.SetJD(_atDateTime.ToJulian());
    
#ifdef UT_SHOW_DATA
    std::cerr 
        << "Sun: " << sun.ToString() << std::endl
        << "l: " << std::fixed << l << std::endl
        << "Mm: " << std::fixed << Mm << std::endl
        << "N: " << std::fixed << N << std::endl
        << "Ev: " << std::fixed << Ev << std::endl
        << "Ae: " << std::fixed << Ae << std::endl
        << "A3: " << std::fixed << A3 << std::endl
        << "Mprimem: " << std::fixed << Mprimem << std::endl
        << "Ec: " << std::fixed << Ec << std::endl
        << "A4: " << std::fixed << A4 << std::endl
        << "lprime: " << std::fixed << lprime << std::endl
        << "V: " << std::fixed << V << std::endl
        << "lprimeprime: " << std::fixed << lprimeprime << std::endl
        << "Nprime: " << std::fixed << Nprime << std::endl
        << "lppNp: " << std::fixed << lppNp << std::endl
        << "sinlppNp: " << std::fixed << sinlppNp << std::endl
        << "y: " << std::fixed << y << std::endl
        << "x: " << std::fixed << x << std::endl
        << "lm: " << std::fixed << lm << std::endl
        << "Bm: " << std::fixed << Bm << std::endl
        << rval.ToString() << std::endl
        << std::endl;
#endif

    return rval;
}

}; // end namespace csgp4

