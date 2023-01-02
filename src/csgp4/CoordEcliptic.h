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
#include "csgp4/CoordEquatorial.h"

#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

namespace csgp4
{
    
/**
 * @brief Stores an ecliptic coord.
 *
 * Ecliptic latitude and ecliptic longitude are stored in radians.
 */
class CoordEcliptic
{
public:
    /**
     * Default constructor
     */
    CoordEcliptic() = default;

    /**
     * Constructor
     * @param[in] lat_in ecliptic lat in radians
     * @param[in] lon_in ecliptic lon in radians
     */
    CoordEcliptic(
            double lat_in,
            double lon_in)
        : ecliptic_lat(lat_in)
        , ecliptic_lon(lon_in)
        , jd(0.0)
    {}

    /**
     * Constructor
     * @param[in] lat_in ecliptic lat in radians
     * @param[in] lon_in ecliptic lon in radians
     * @param[in] jd     optional JD value
     */
    CoordEcliptic(
            double lat_in,
            double lon_in,
            double jd_in)
        : ecliptic_lat(lat_in)
        , ecliptic_lon(lon_in)
        , jd(jd_in)
    {}

    /**
     * Copy constructor
     * @param[in] equa object to copy from
     */
    CoordEcliptic(const CoordEcliptic& e)
    {
        ecliptic_lat = e.ecliptic_lat;
        ecliptic_lon = e.ecliptic_lon;
        jd = e.jd;
    }

    /**
     * Assignment operator
     * @param[in] equa object to copy from
     */
    CoordEcliptic& operator=(const CoordEcliptic& e)
    {
        if (this != &e)
        {
            ecliptic_lat = e.ecliptic_lat;
            ecliptic_lon = e.ecliptic_lon;
            jd = e.jd;
        }
        return *this;
    }

    /**
     * Equallity operator
     * @param[in] equa object to compare from
     */
    bool operator==(const CoordEcliptic& e)
    {
        return (ecliptic_lat == e.ecliptic_lat && ecliptic_lon == e.ecliptic_lon);
    }

    /**
     * Return coord transformed to an equatoral coord frame.
     * Julian date as per this->jd value
     */
    CoordEquatorial asEquatorial(void)
    {
        return asEquatorial(this->jd);
    }
    
    /**
     * Return coord transformed to an equatoral coord frame.
     * @param[in] d Julian date
     */
    CoordEquatorial asEquatorial(double d)
    {
        const double T = (d - 2451545.0) / 36525.0;
        const double ed = 23.43929167 - (13.0041666e-3 * T) - (166.66666e-9 * (T*T)) - (502.77777e-9 * (T*T*T));
        const double er = Util::DegreesToRadians(ed);
        const double dec = std::asin(
            std::sin(ecliptic_lat)*std::cos(er) + std::cos(ecliptic_lat)*std::sin(er)*std::sin(ecliptic_lon)
        );
        const double ra = std::atan(
            (std::sin(ecliptic_lon)*std::cos(er) - std::tan(ecliptic_lat)*std::sin(er)) /
                            std::cos(ecliptic_lon)
        );
        return CoordEquatorial(
            dec,
            ((ra < 0) ? (ra + (M_PI)) : ra),
            d
        );
    }

    /**
     * Dump this object to a string
     * @returns string
     */
    std::string ToString() const
    {
        std::stringstream ss;
        ss << std::right << std::fixed << std::setprecision(3);
        ss << "Ecliptic lat: " << std::setw(8) << Util::RadiansToDegrees(ecliptic_lat);
        ss << ", ecliptic lon: " << std::setw(8) << Util::RadiansToDegrees(ecliptic_lon);
        ss << ", JD: " << std::setw(8) << jd;
        return ss.str();
    }

    /**
     * Get the ecliptic_lat value in radians
     * @returns double
     */
    double EclipticLat(void) {
        return ecliptic_lat;
    }

    /**
     * Get the ecliptic_lon value in radians
     * @returns double
     */
    double EclipticLon(void)
    {
        return ecliptic_lon;
    }
    
    /**
     * Get optional Julian Date
     * @returns double
     */
    double JulianDate(void)
    {
        return jd;
    }

    /**
     * Set the ecliptic_lat value in radians
     * @returns this
     */
    CoordEcliptic& EclipticLat(double d) {
        ecliptic_lat = d;
        return *this;
    }

    /**
     * Set the ecliptic longitude value in radians
     * @returns double
     */
    CoordEcliptic& EclipticLon(double d)
    {
        ecliptic_lon = d;
        return *this;
    }
    
    /**
     * Set the optional Julian Date
     * @returns double
     */
    CoordEcliptic& JulianDate(double d)
    {
        jd = d;
        return *this;
    }

private:

    /** Ecliptic latitude in radians */
    double ecliptic_lat{};

    /** Ecliptic longitude in radians */
    double ecliptic_lon{};
    
    /** Option JD timestamp */
    double jd{};
};


inline std::ostream& operator<<(std::ostream& strm, const CoordEcliptic& t)
{
    return strm << t.ToString();
}

}; // end namespace csgp4

