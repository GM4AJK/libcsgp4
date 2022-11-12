/*
 * Copyright 2013 Daniel Warner <contact@danrw.com>
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


#ifndef ORBITALELEMENTS_H_
#define ORBITALELEMENTS_H_

#include "Util.h"
#include "DateTime.h"

namespace csgp4
{

class Tle;

/**
 * @brief The extracted orbital elements used by the SGP4 propagator.
 */
class OrbitalElements
{
public:
    OrbitalElements(const Tle& tle);

    /*
     * XMO
     */
    double MeanAnomoly() const
    {
        return mean_anomoly_;
    }

    /*
     * XNODEO
     */
    double AscendingNode() const
    {
        return ascending_node_;
    }

    /*
     * OMEGAO
     */
    double ArgumentPerigee() const
    {
        return argument_perigee_;
    }

    /*
     * EO
     */
    double Eccentricity() const
    {
        return eccentricity_;
    }

    /*
     * XINCL
     */
    double Inclination() const
    {
        return inclination_;
    }

    /*
     * XNO
     */
    double MeanMotion() const
    {
        return mean_motion_;
    }

    /*
     * BSTAR
     */
    double BStar() const
    {
        return bstar_;
    }

    /*
     * AODP
     */
    double RecoveredSemiMajorAxis() const
    {
        return recovered_semi_major_axis_;
    }

    /*
     * XNODP
     */
    double RecoveredMeanMotion() const
    {
        return recovered_mean_motion_;
    }

    /*
     * PERIGE
     */
    double Perigee() const
    {
        return perigee_;
    }

    /*
     * Period in minutes
     */
    double Period() const
    {
        return period_;
    }

    /*
     * EPOCH
     */
    DateTime Epoch() const
    {
        return epoch_;
    }

    /**
     * Dump this object to a string
     * @returns string
     */
    std::string ToString() const
    {
        std::stringstream ss;
        ss << std::right << std::fixed << std::setprecision(3) 
            << "MEAN ANA: " << std::setw(8) << mean_anomoly_ << std::endl
            << "ASC NODE: " << std::setw(8) << ascending_node_ << std::endl
            << "ARG PERI: " << std::setw(8) << argument_perigee_ << std::endl
            << "ECCENTRI: " << std::setw(8) << eccentricity_ << std::endl
            << "INCLINAT: " << std::setw(8) << inclination_ << std::endl
            << "MEAM MOT: " << std::setw(8) << mean_motion_ << std::endl
            << "BSTAR   : " << std::setw(8) << bstar_ << std::endl
            << "RSEMIMAJ: " << std::setw(8) << recovered_semi_major_axis_ << std::endl
            << "RMEAN MO: " << std::setw(8) << recovered_mean_motion_ << std::endl
            << "PERIGEE : " << std::setw(8) << perigee_ << std::endl
            << "PERIOD  : " << std::setw(8) << period_  << std::endl;
        return ss.str();
    }


private:
    double mean_anomoly_;
    double ascending_node_;
    double argument_perigee_;
    double eccentricity_;
    double inclination_;
    double mean_motion_;
    double bstar_;
    double recovered_semi_major_axis_;
    double recovered_mean_motion_;
    double perigee_;
    double period_;
    DateTime epoch_;
};

}; // end namespace csgp4

#endif
