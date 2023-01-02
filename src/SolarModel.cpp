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

#include "csgp4/SolarModel.h"

#include "csgp4/Globals.h"
#include "csgp4/Util.h"

namespace csgp4
{

SolarModel::SolarModel(const DateTime& dt)
{
    Initialise(dt);
}

void 
SolarModel::Initialise(const DateTime& dt)
{
    _atDateTime = dt;
    _atTime_JD  = dt.ToJulian();
}

CoordsSolarModel
SolarModel::Position()
{
    double D  = _atDateTime.ToJulian() - 2455196.5;
    double eg = 279.557208; // Mean Ecliptic Longitude in degrees.
    double wg = 283.112438; // Longitude of the Sun at perigee in degrees.
    double e  = 0.016705;   // Eccentricity of the Sun-Earth orbit in degrees.
    double N  = Util::Wrap360((360.0/365.242191)*D);
    if(N < 0) N += 360;
    double Mo = Util::Wrap360(N + eg - wg); // Mean Anomaly in degrees
    if(Mo < 0) Mo += 360.0;
    double v = Mo + (360.0/M_PI) * e * std::sin(Mo * M_PI/180.0);
    double ecliptic_lon = v+ wg;
    if(ecliptic_lon > 360.0) ecliptic_lon -= 360.0;
    double ecliptic_lat = 0.0;
    return CoordsSolarModel(ecliptic_lat, Util::DegreesToRadians(ecliptic_lon), Mo, D, N);
}

}; // end namespace csgp4

