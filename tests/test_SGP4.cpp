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

#include "SGP4.h"

static std::string iss_tle0("ISS");
static std::string iss_tle1("1 25544U 98067A   22314.50373836  .00014546  00000-0  26300-3 0  9991");
static std::string iss_tle2("2 25544  51.6436 331.7596 0006814  57.2751  98.3376 15.49917581367874");

static std::string expected()
{
    std::stringstream oss;
    oss << "DateTime: 2022-11-10 12:05:22.994304 UTC" << std::endl
        << "Position: X: -4639.336, Y:  4456.111, Z:  2185.196, W:     0.000" << std::endl
        << "Velocity: X:    -4.830, Y:    -2.323, Z:    -5.477, W:     0.000" << std::endl;
    return oss.str();
}

TEST(SGP4_test_case, SGP4_pos_at_epoch)
{
    csgp4::Tle tle(iss_tle0, iss_tle1, iss_tle2);
    csgp4::SGP4 sgp4(tle);
    csgp4::Eci  dut = sgp4.FindPosition(0);
    std::string expect = expected();;
    std::string actual = dut.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}
