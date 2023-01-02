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

/*
 * This class is formulated from the book:-
 *   Practical Astronomy with your Calculator or Spreadsheet
 *   by Peter Duffett-Smith and Jonathon Zwart
 * ISBN: 978-1-108-43607-6
 * Cambridge University Press
 */

#pragma once

#include <string>
#include <sstream>

#include "DateTime.h"
#include "CoordEquatorial.h"

namespace csgp4
{

class CoordsSolarModel
{
public:
    CoordsSolarModel() = default;

    CoordsSolarModel(double ecliptic_lat, double ecliptic_lon, double Mo, double D, double N) :
        _ecliptic_lat(ecliptic_lat),
        _ecliptic_lon(ecliptic_lon),
        _Mo(Mo),
        _D(D),
        _N(N)
    {}

    /**
     * Copy constructor
     * @param[in] e object to copy from
     */
    CoordsSolarModel(const CoordsSolarModel& e)
    {
        _ecliptic_lat = e._ecliptic_lat;
        _ecliptic_lon = e._ecliptic_lon;
        _Mo  = e._Mo;
        _D   = e._D;
        _N   = e._N;
    }

    /**
     * Assignment operator
     * @param[in] e object to copy from
     */
    CoordsSolarModel& operator=(const CoordsSolarModel& e)
    {
        if (this != &e)
        {
            _ecliptic_lat = e._ecliptic_lat;
            _ecliptic_lon = e._ecliptic_lon;
            _Mo  = e._Mo;
            _D   = e._D;
            _N   = e._N;
        }
        return *this;
    }

    std::string ToString() const
    {
        std::stringstream ss;
        ss << std::right << std::fixed << std::setprecision(3);
        ss << "Lat (degrees): " << std::setw(8) << Util::RadiansToDegrees(_ecliptic_lat);
        ss << ", Lon (degrees): " << std::setw(8) << Util::RadiansToDegrees(_ecliptic_lon) << std::endl;
        ss << "Mo: " << std::fixed << _Mo;
        ss << ", D: " << std::fixed << _D;
        ss << ", N: " << std::fixed << _N;
        return ss.str();
    }

    double _ecliptic_lat{};
    double _ecliptic_lon{};
    double _Mo{};
    double _D{};
    double _N{};
};

/**
 * @brief Find the position of the sun in Equatorial coordinate system.
 */
class SolarModel
{
private:

    void Initialise(const DateTime& dt);
    double _atTime_JD{};
    DateTime _atDateTime;

public:

    SolarModel() = default;

    SolarModel(const DateTime& dt);

    double   GetAtDateJD(void) { return _atTime_JD; }
    DateTime GetAtDate(void)   { return _atDateTime; }
    
    CoordsSolarModel Position(void);
};

}; // end namespace csgp4
