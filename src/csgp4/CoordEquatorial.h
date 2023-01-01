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


#pragma once

#include "csgp4/Util.h"

#include <string>
#include <sstream>
#include <iomanip>

namespace csgp4
{
    
/**
 * @brief Stores an equatorial coord (declination, right ascension).
 *
 * Declination and Right Ascension are stored in radians.
 */
class CoordEquatorial
{
public:
    /**
     * Default constructor
     */
    CoordEquatorial() = default;

    /**
     * Constructor
     * @param[in] dec_in declination in radians
     * @param[in] ra_in right ascension in radians
     */
    CoordEquatorial(
            double dec_in,
            double ra_in)
        : dec(dec_in)
        , ra(ra_in)
    {}

    /**
     * Copy constructor
     * @param[in] equa object to copy from
     */
    CoordEquatorial(const CoordEquatorial& equa)
    {
        dec = equa.dec;
        ra = equa.ra;
    }

    /**
     * Assignment operator
     * @param[in] equa object to copy from
     */
    CoordEquatorial& operator=(const CoordEquatorial& equa)
    {
        if (this != &equa)
        {
            dec = equa.dec;
            ra = equa.ra;
        }
        return *this;
    }

    /**
     * Equallity operator
     * @param[in] equa object to compare from
     */
    bool operator==(const CoordEquatorial& equa)
    {
        return (dec == equa.dec && ra == equa.ra);
    }

    /**
     * Dump this object to a string
     * @returns string
     */
    std::string ToString() const
    {
        std::stringstream ss;
        ss << std::right << std::fixed << std::setprecision(3);
        ss << "Dec: " << std::setw(8) << Util::RadiansToDegrees(dec);
        ss << ", RA: " << std::setw(8) << Util::RadiansToDegrees(ra);
        return ss.str();
    }

    /**
     * Get the declination value in radians
     * @returns double
     */
    double Dec(void) {
        return dec;
    }
    
    /**
     * Get the right ascension value in radians
     * @returns double
     */
    double RA(void)
    {
        return ra;
    }

    /**
     * Set the declination value in radians
     * @returns this
     */
    CoordEquatorial& Dec(double d) {
        dec = d;
        return *this;
    }
    
    /**
     * Get the right ascension value in radians
     * @returns double
     */
    CoordEquatorial& RA(double d)
    {
        ra = d;
        return *this;
    }

private:

    /** declination in radians */
    double dec{};
    
    /** right ascension in radians */
    double ra{};
};


inline std::ostream& operator<<(std::ostream& strm, const CoordEquatorial& t)
{
    return strm << t.ToString();
}

}; // end namespace csgp4

