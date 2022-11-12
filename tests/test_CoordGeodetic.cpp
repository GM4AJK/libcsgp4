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
#include "csgp4/CoordGeodetic.h"

TEST(CoordGeodetic_suite, CoordGeodetic_ctor)
{
    csgp4::CoordGeodetic g;
    std::string expect = std::string("Lat:    0.000, Lon:    0.000, Alt:      0.000");
    std::string actual = g.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}

TEST(CoordGeodetic_suite, CoordGeodetic_operator_assignment)
{
    csgp4::CoordGeodetic g_src(1,1,1);
    csgp4::CoordGeodetic g_dst;
    g_dst = g_src;
    std::string expect = std::string("Lat:    1.000, Lon:    1.000, Alt:      1.000");
    std::string actual = g_dst.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}

TEST(CoordGeodetic_suite, CoordGeodetic_streamable)
{
    std::stringstream oss;
    csgp4::CoordGeodetic v(1,1,1);
    std::string expect = std::string("Lat:    1.000, Lon:    1.000, Alt:      1.000");
    oss << v;
    std::string actual = oss.str();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    

