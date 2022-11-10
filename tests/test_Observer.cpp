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

#include "Observer.h"

TEST(Observer_test_case, Observer_ctor_4args)
{
    std::stringstream expect;
    csgp4::Observer obs(56, -3, 50);
    expect << "ECI: DateTime: 0001-01-01 00:00:00.000000 UTC" << std::endl;
    expect << "Position: X:  -454.894, Y:  3573.968, Z:  5305.893, W:  6413.476" << std::endl;
    expect << "Velocity: X:    -0.261, Y:    -0.033, Z:     0.000, W:     0.263" << std::endl;
    expect << std::endl;
    expect << "GEO: Lat:   56.000, Lon:   -3.000, Alt:     50.000";
    std::string actual = obs.ToString();
    EXPECT_STREQ(expect.str().c_str(), actual.c_str());
}
