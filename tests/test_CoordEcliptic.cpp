/*********************************************************************************
 *   Copyright (c) 2022 Andy Kirkham
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
#include "csgp4/Vector.h"
#include "csgp4/DateTime.h"
#include "csgp4/CoordEcliptic.h"
#include "csgp4/CoordEquatorial.h"

TEST(CoordEcliptic_suite, CoordEcliptic_ctor)
{
    csgp4::CoordEcliptic dut(d2r(180.0), d2r(45.0));
    std::string expect = std::string("Ecliptic lat:  180.000, ecliptic lon:   45.000, JD:    0.000");
    std::string actual = dut.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}

TEST(CoordEcliptic_suite, CoordEcliptic_ctor2)
{
    csgp4::CoordEcliptic dut(d2r(180.0), d2r(45.0), 1.5);
    std::string expect = std::string("Ecliptic lat:  180.000, ecliptic lon:   45.000, JD:    1.500");
    std::string actual = dut.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}

TEST(CoordEcliptic_suite, CoordEcliptic_asEquatorial)
{
    // Page 53, section 27
    csgp4::DateTime dt(2009, 7, 6);
    csgp4::CoordEcliptic dut(d2r(4.875277778), d2r(139.6861111), dt.ToJulian());
    csgp4::CoordEquatorial res = dut.asEquatorial();
    {
        std::string expect = std::string("Dec:   19.535, RA:  143.722, JD: 2455018.500");
        std::string actual = res.ToString();
        EXPECT_STREQ(expect.c_str(), actual.c_str());
    }
    csgp4::Vector v = res.HourAngle();
    {
        std::string expect = std::string("X:     9.000, Y:    34.000, Z:    53.321, W:     9.581");
        std::string actual = v.ToString();
        EXPECT_STREQ(expect.c_str(), actual.c_str());
    }
}
