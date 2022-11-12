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

#include <cmath>
#include <string>
#include <sstream>
#include <gtest/gtest.h>

#include "common.h"
#include "csgp4/Tle.h"

static std::string expect_string()
{
    if(iss.length() == 0) {
        std::stringstream expect;
        expect 
        
            << "Norad Number:         25544" << std::endl
            << "Int. Designator:      98067A  " << std::endl
            << "Epoch:                2022-11-10 12:05:22.994304 UTC" << std::endl
            << "Orbit Number:         36787" << std::endl
            << "Ephemeris Type        0" << std::endl
            << "Classification Type   " << std::endl
            << "Mean Motion Dt2:        0.00014546" << std::endl
            << "Mean Motion Ddt6:       0.00000000" << std::endl
            << "Eccentricity:           0.00068140" << std::endl
            << "BStar:                  0.00026300" << std::endl
            << "Inclination:           51.64360000" << std::endl
            << "Right Ascending Node: 331.75960000" << std::endl
            << "Argument Perigee:      57.27510000" << std::endl
            << "Mean Anomaly:          98.33760000" << std::endl
            << "Mean Motion:           15.49917581" << std::endl;
        iss = expect.str();
    }
    return iss;
}

TEST(Tle_suite, Tle_ctor_2args)
{
    csgp4::Tle tle(iss_tle1, iss_tle2);
    std::string expect = expect_string();
    std::string actual = tle.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}

TEST(Tle_suite, Tle_ctor_3args)
{
    csgp4::Tle tle(iss_tle0, iss_tle1, iss_tle2);
    std::string expect = expect_string();
    std::string actual = tle.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}

TEST(Tle_suite, Tle_Name)
{
    csgp4::Tle tle(iss_tle0, iss_tle1, iss_tle2);
    std::string expect = iss_tle0;
    std::string actual = tle.Name();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}

TEST(Tle_suite, Tle_Line1)
{
    csgp4::Tle tle(iss_tle0, iss_tle1, iss_tle2);
    std::string expect = iss_tle1;
    std::string actual = tle.Line1();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}

TEST(Tle_suite, Tle_Line2)
{
    csgp4::Tle tle(iss_tle0, iss_tle1, iss_tle2);
    std::string expect = iss_tle2;
    std::string actual = tle.Line2();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}

TEST(Tle_suite, Tle_NoradNumber)
{
    csgp4::Tle tle(iss_tle0, iss_tle1, iss_tle2);
    unsigned int expect = 25544;
    unsigned int actual = tle.NoradNumber();
    EXPECT_EQ(expect, actual);
}

TEST(Tle_suite, Tle_IntDesignator)
{
    csgp4::Tle tle(iss_tle0, iss_tle1, iss_tle2);
    std::string expect("98067A  ");
    std::string actual = tle.IntDesignator();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}

TEST(Tle_suite, Tle_Epoch)
{
    csgp4::Tle tle(iss_tle0, iss_tle1, iss_tle2);
    std::string expect("2022-11-10 12:05:22.994304 UTC");
    std::string actual = tle.Epoch().ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}

/*
Example of current TLE format in JSON from Celestrak.
[{
    "OBJECT_NAME": "STARLINK-1007",
    "OBJECT_ID": "2019-074A",
    "EPOCH": "2022-11-08T06:14:56.037120",
    "MEAN_MOTION": 15.06405436,
    "ECCENTRICITY": 0.0001911,
    "INCLINATION": 53.0559,
    "RA_OF_ASC_NODE": 251.8795,
    "ARG_OF_PERICENTER": 48.9031,
    "MEAN_ANOMALY": 311.2123,
    "EPHEMERIS_TYPE": 0,
    "CLASSIFICATION_TYPE": "U",
    "NORAD_CAT_ID": 44713,
    "ELEMENT_SET_NO": 999,
    "REV_AT_EPOCH": 16525,
    "BSTAR": 0.00033293,
    "MEAN_MOTION_DOT": 4.682e-5,
    "MEAN_MOTION_DDOT": 0
}]
*/

TEST(Tle_suite, Tle_ctor_Args)
{
    std::string expect;
    std::string actual;
    csgp4::TleArgs args;
    args.name = std::string("STARLINK-1007");
    args.int_designator = std::string("2019-074A");
    args.epoch = std::string("2022-11-08T06:14:56.037120");
    args.ephemeris_type = 0;
    args.classification_type = std::string("U");
    args.mean_motion = 15.06405436;
    args.mean_anomaly = 311.2123;
    args.inclination = 53.0559;
    args.right_ascending_node = 251.8795;
    args.eccentricity = 0.0001911;
    args.argument_perigee = 48.9031;
    args.bstar = 0.00033293;
    args.norad_number = 44713;
    args.orbit_number = 16525;
    args.mean_motion_dot = 4.682e-5;
    args.mean_motion_ddot = 0;    
    
    csgp4::Tle dut(args);
    // Note, iso8601 time is to 3 decimal places.
    expect = std::string("2022-11-08 06:14:56.037000 UTC");
    actual = dut.Epoch().ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
    
    expect =  std::string("2019-074A");
    actual = dut.IntDesignator();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}





