/*********************************************************************************
 *   Copyright (c) 2022 Andy Kirkham  All rights reserved.
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"),
 *   to deal in the Software without restriction, including without limitation
 *   the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *   and/or sell copies of the Software, and to permit persons to whom
 *   the Software is furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included
 *   in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 *   IN THE SOFTWARE.
 ***********************************************************************************/

/**
 * This isn't a Unit Test but an overview of using the librray and a worked example.
 */
 
#include <cmath>
#include <string>
#include <sstream>
#include <gtest/gtest.h>

#include "csgp4/Tle.h"
#include "csgp4/SGP4.h"
#include "csgp4/DateTime.h"
#include "csgp4/Observer.h"
#include "csgp4/CoordGeodetic.h"
#include "csgp4/OrbitalElements.h"
#include "csgp4/CoordTopocentric.h"

TEST(Overview_suite, Overview_demo)
{
    // Begin by defining an Observer position on Earth
    csgp4::CoordGeodetic obs_pos(51.0, -3.0, 10);
    
    // Next define an observer (which is a position at a specific time)
    csgp4::Observer observer(obs_pos);
    
    // Next, define a TLE for the satellite of interest
    std::string line0("ISS");
    std::string line1("1 25544U 98067A   22315.39284736  .00014043  00000-0  25399-3 0  9998");
    std::string line2("2 25544  51.6439 327.3552 0006927  60.3945  19.4853 15.49940881368015");
    csgp4::Tle tle = csgp4::Tle(line0, line1, line2);

    // Next create a propergation model for the satellite.
    csgp4::SGP4 sgp4 = csgp4::SGP4(tle);

    // Next define a moment in time the obseration takes place
    csgp4::DateTime attime(2022, 11, 19, 18, 27, 58);

    // Next, find the satellite position in space in ECI frame of reference at the given time
    csgp4::Eci sat_pos = sgp4.FindPosition(attime);
    
    // Finally get a look angle from the observer to the satellite
    csgp4::CoordTopocentric look_angle = observer.GetLookAngle(sat_pos);

    // Prepare expectations
    std::stringstream expect;
    expect << "Az:  204.313, El:    9.568, Rng:   1482.658, Rng Rt:  -5.797";
    
    // Get actual dut results
    std::string actual = look_angle.ToString();
        
    EXPECT_STREQ(expect.str().c_str(), actual.c_str());
}

