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

#include "Eci.h"

static std::string expected()
{
    std::stringstream expect;
    expect << "DateTime: 2022-11-10 19:00:00.000000 UTC" << std::endl
        << "Position: X:  3178.660, Y: -1695.965, Z:  5305.893, W:  6413.476" << std::endl
        << "Velocity: X:     0.124, Y:     0.232, Z:     0.000, W:     0.263" << std::endl;
    return expect.str();
}

TEST(Eci_suite, Eci_ctor_4args)
{
    csgp4::DateTime dt(2022, 11, 10, 19, 0, 0);
    csgp4::Eci dut(dt, 56, -3, 50);
    std::string expect = expected();
    std::string actual = dut.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    

TEST(Eci_suite, Eci_ctor_geodetic)
{
    csgp4::DateTime dt(2022, 11, 10, 19, 0, 0);
    csgp4::CoordGeodetic geo(56, -3, 50);
    csgp4::Eci dut(dt, geo);
    std::string expect = expected();
    std::string actual = dut.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    

