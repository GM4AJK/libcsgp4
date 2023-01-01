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

#include <string>
#include <gtest/gtest.h>

#include "common.h"
#include "csgp4/config.h"
#include "csgp4/CoordEquatorial.h"

TEST(CoordEquatorial_suite, CoordEquatorial_ctor)
{
    csgp4::CoordEquatorial ct(d2r(180.0), d2r(45.0));
    std::string expect = std::string("Dec:  180.000, RA:   45.000");
    std::string actual = ct.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}

TEST(CoordEquatorial_suite, CoordEquatorial_equality)
{
    csgp4::CoordEquatorial c1(d2r(180.0), d2r(45.0));
    csgp4::CoordEquatorial c2(d2r(180.0), d2r(45.0));
    EXPECT_TRUE(c1 == c2);
}

TEST(CoordEquatorial_suite, CoordEquatorial_assignment)
{
    csgp4::CoordEquatorial c1(d2r(180.0), d2r(45.0));
    auto c2 = c1;
    EXPECT_TRUE(c1 == c2);
}

TEST(CoordEquatorial_suite, CoordEquatorial_set)
{
    csgp4::CoordEquatorial dut;
    dut.Dec(d2r(180.0)).RA(d2r(45.0));
    std::string expect = std::string("Dec:  180.000, RA:   45.000");
    std::string actual = dut.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}
