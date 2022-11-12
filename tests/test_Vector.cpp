/*********************************************************************************
 *   Copyright (c) 2008-2022 Andy Kirkham  All rights reserved.
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

#include "config.h"
#include "Vector.h"

TEST(Vector_suite, Vector_base_ctor)
{
    csgp4::Vector v;
    std::string expect = std::string("X:     0.000, Y:     0.000, Z:     0.000, W:     0.000");
    std::string actual = v.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    

TEST(Vector_suite, Vector_base_ctor_with_3values)
{
    csgp4::Vector v(1.0, 1.0, 1.0);
    std::string expect = std::string("X:     1.000, Y:     1.000, Z:     1.000, W:     0.000");
    std::string actual = v.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    

TEST(Vector_suite, Vector_base_ctor_with_4values)
{
    csgp4::Vector v(1.0, 1.0, 1.0, 1.0);
    std::string expect = std::string("X:     1.000, Y:     1.000, Z:     1.000, W:     1.000");
    std::string actual = v.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    

TEST(Vector_suite, Vector_base_copy_ctor)
{
    csgp4::Vector v_dst;
    csgp4::Vector v_src(1.0, 1.0, 1.0, 1.0);
    v_dst = v_src;
    std::string expect = std::string("X:     1.000, Y:     1.000, Z:     1.000, W:     1.000");
    std::string actual = v_dst.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    

TEST(Vector_suite, Vector_operator_subtract)
{
    csgp4::Vector v_dut;
    csgp4::Vector v_dst(1.0, 1.0, 1.0, 1.0);
    csgp4::Vector v_src(1.0, 1.0, 1.0, 1.0);
    v_dut = v_dst - v_src;
    std::string expect = std::string("X:     0.000, Y:     0.000, Z:     0.000, W:     0.000");
    std::string actual = v_dut.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    

TEST(Vector_suite, Vector_magnitude)
{
    double x = 1.0, y = 2.0, z = 3.0;
    csgp4::Vector v(x, y, z, 0.0);
    double expect = sqrt((x*x) + (y*y) + (z*z));
    double actual = v.Magnitude();
    EXPECT_DOUBLE_EQ(expect, actual);
}    

TEST(Vector_suite, Vector_dot)
{
    double x1 = 1.0, y1 = 2.0, z1 = 3.0;
    double x2 = 4.0, y2 = 5.0, z2 = 6.0;
    csgp4::Vector v1(x1, y1, z1), v2(x2, y2, z2);
    double expect = (x1*x2) + (y1*y2) + (z1*z2);
    double actual = v1.Dot(v2);
    EXPECT_DOUBLE_EQ(expect, actual);
}    

TEST(Vector_suite, Vector_streamable)
{
    std::stringstream oss;
    csgp4::Vector v(1.0, 1.0, 1.0, 1.0);
    std::string expect = std::string("X:     1.000, Y:     1.000, Z:     1.000, W:     1.000");
    oss << v;
    std::string actual = oss.str();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    
