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

#include "SunModel.h"
#include "DateTime.h"
#include "CoordEcliptic.h"
#include "CoordEquatorial.h"

namespace csgp4
{

class CoordsLunarModel
{
public:
    CoordsLunarModel() = default;

    CoordsLunarModel(double ecliptic_lat, double ecliptic_lon, CoordsSunModel& sun)
    {
        _pos = CoordEcliptic(ecliptic_lat, ecliptic_lon);
        _sun = sun;
    }

    /**
     * Copy constructor
     * @param[in] e object to copy from
     */
    CoordsLunarModel(const CoordsLunarModel& e)
    {
        _pos = e._pos;
        _sun = e._sun;
    }

    /**
     * Assignment operator
     * @param[in] e object to copy from
     */
    CoordsLunarModel& operator=(const CoordsLunarModel& e)
    {
        if (this != &e)
        {
            _pos = e._pos;
            _sun = e._sun;
        }
        return *this;
    }

    std::string ToString() const
    {
        std::stringstream ss;
        ss << _pos.ToString();
        return ss.str();
    }

    CoordsLunarModel& SetJD(double d)
    {
        _pos.JulianDate(d);
        return *this;
    }
    
    CoordEcliptic  _pos;
    CoordsSunModel _sun;
};

/**
 * @brief Find the position of the sun in Equatorial coordinate system.
 */
class LunarModel
{
private:

    void Initialise(const DateTime& dt);
    double _atTime_JD{};
    DateTime _atDateTime;

public:

    LunarModel() = default;

    LunarModel(const DateTime& dt);

    double   GetAtDateJD(void) { return _atTime_JD; }
    DateTime GetAtDate(void)   { return _atDateTime; }
    
    CoordsLunarModel Position(void);
};

}; // end namespace csgp4
