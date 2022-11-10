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

#include "SolarPosition.h"

static std::string expect_sun()
{
    std::stringstream expect;
    expect << "DateTime: 2022-12-25 00:00:00.000000 UTC" << std::endl
        << "Position: X: 8114735.538, Y: -134791804.891, Z: -58436445.997, W: 147137683.206" << std::endl
        << "Velocity: X:     0.000, Y:     0.000, Z:     0.000, W:     0.000" << std::endl;
    return expect.str();
}


TEST(SolarPosition_test_case, SolarPosition_FindPosition)
{
    csgp4::SolarPosition sp;
    csgp4::DateTime dt(2022, 12, 25, 0, 0, 0);
    csgp4::Eci dut = sp.FindPosition(dt);
    std::string expect = expect_sun();
    std::string actual = dut.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}
