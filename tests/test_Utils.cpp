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

#include <string>
#include <gtest/gtest.h>

#include "csgp4/config.h"
#include "csgp4/Util.h"

TEST(util_suite, TrimLeft_test)
{
    auto dut = std::string("   foobarbaz");
    csgp4::Util::TrimLeft(dut);
    EXPECT_EQ(9, dut.length());
    EXPECT_STREQ("foobarbaz", dut.c_str());
}

TEST(util_suite, TrimRight_test)
{
    auto dut = std::string("foobarbaz   ");
    csgp4::Util::TrimRight(dut);
    EXPECT_EQ(9, dut.length());
    EXPECT_STREQ("foobarbaz", dut.c_str());
}

TEST(util_suite, Trim_test)
{
    auto dut = std::string("   foobarbaz   ");
    csgp4::Util::Trim(dut);
    EXPECT_EQ(9, dut.length());
    EXPECT_STREQ("foobarbaz", dut.c_str());
}

TEST(util_suite, FromStringDoubleTrue_test)
{
    auto str = std::string("1.234");
    double dut;
    auto rval = csgp4::Util::FromString<double>(str, dut);
    EXPECT_EQ(1.234, dut);
    EXPECT_EQ(true, rval);
}

TEST(util_suite, FromStringDoubleFalse_test)
{
    auto str = std::string("foo");
    double dut;
    auto rval = csgp4::Util::FromString<double>(str, dut);
    EXPECT_EQ(false, rval);
}

