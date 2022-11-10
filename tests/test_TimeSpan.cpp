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

#include "TimeSpan.h"

TEST(TimeSpan_test_case, TimeSpan_ctor_3)
{
    csgp4::TimeSpan ts(23, 59, 59);
    std::string expect = std::string("23:59:59");
    std::string actual = ts.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    

TEST(TimeSpan_test_case, TimeSpan_ctor_4)
{
    csgp4::TimeSpan ts(1, 23, 59, 59);
    std::string expect = std::string("01.23:59:59");
    std::string actual = ts.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    

TEST(TimeSpan_test_case, TimeSpan_ctor_5)
{
    csgp4::TimeSpan ts(1, 23, 59, 59, 500);
    std::string expect = std::string("01.23:59:59.000500");
    std::string actual = ts.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    

TEST(TimeSpan_test_case, TimeSpan_Add)
{
    csgp4::TimeSpan tsn(0,  0,  0);
    csgp4::TimeSpan ts1(1, 23, 59, 59);
    csgp4::TimeSpan ts2(2, 23, 59, 59);
    tsn = ts1.Add(ts2);
    std::string expect = std::string("04.23:59:58");
    std::string actual = tsn.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    

TEST(TimeSpan_test_case, TimeSpan_Subtract)
{
    csgp4::TimeSpan tsn(0,  0,  0);
    csgp4::TimeSpan ts1(2, 23, 59, 59);
    csgp4::TimeSpan ts2(1, 23, 59, 59);
    tsn = ts1.Subtract(ts2);
    std::string expect = std::string("01.00:00:00");
    std::string actual = tsn.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    

TEST(TimeSpan_test_case, TimeSpan_Compare_Equal)
{
    csgp4::TimeSpan ts1(1, 23, 59, 59);
    csgp4::TimeSpan ts2(1, 23, 59, 59);
    EXPECT_EQ(0, ts1.Compare(ts2));
}    

TEST(TimeSpan_test_case, TimeSpan_Compare_Greater)
{
    csgp4::TimeSpan ts1(0, 23, 59, 59);
    csgp4::TimeSpan ts2(1, 23, 59, 59);
    EXPECT_EQ(-1, ts1.Compare(ts2));
}    

TEST(TimeSpan_test_case, TimeSpan_Compare_Less)
{
    csgp4::TimeSpan ts1(1, 23, 59, 59);
    csgp4::TimeSpan ts2(0, 23, 59, 59);
    EXPECT_EQ(1, ts1.Compare(ts2));
}    

TEST(TimeSpan_test_case, TimeSpan_Equal_To)
{
    csgp4::TimeSpan ts1(1, 23, 59, 59);
    csgp4::TimeSpan ts2(1, 23, 59, 59);
    EXPECT_EQ(true, ts1.Equals(ts2));
}    

TEST(TimeSpan_test_case, TimeSpan_Not_Equal_To)
{
    csgp4::TimeSpan ts1(0, 23, 59, 59);
    csgp4::TimeSpan ts2(1, 23, 59, 59);
    EXPECT_EQ(false, ts1.Equals(ts2));
}    

TEST(TimeSpan_test_case, TimeSpan_streamable)
{
    std::stringstream actual;
    csgp4::TimeSpan ts(23, 59, 59);
    std::string expect = std::string("23:59:59");
    actual << ts;
    EXPECT_STREQ(expect.c_str(), actual.str().c_str());
}    

TEST(TimeSpan_test_case, TimeSpan_Operator_Add)
{
    csgp4::TimeSpan tsn(0,  0,  0);
    csgp4::TimeSpan ts1(1, 23, 59, 59);
    csgp4::TimeSpan ts2(2, 23, 59, 59);
    tsn = ts1 + ts2;
    std::string expect = std::string("04.23:59:58");
    std::string actual = tsn.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    

TEST(TimeSpan_test_case, TimeSpan_Operator_Subtract)
{
    csgp4::TimeSpan tsn(0,  0,  0);
    csgp4::TimeSpan ts1(2, 23, 59, 59);
    csgp4::TimeSpan ts2(1, 23, 59, 59);
    tsn = ts1 - ts2;
    std::string expect = std::string("01.00:00:00");
    std::string actual = tsn.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    

TEST(TimeSpan_test_case, TimeSpan_Operator_Equal_To)
{
    csgp4::TimeSpan ts1(1, 23, 59, 59);
    csgp4::TimeSpan ts2(1, 23, 59, 59);
    EXPECT_EQ(true, ts1 == ts2);
}    

TEST(TimeSpan_test_case, TimeSpan_Operator_Not_Equal_To)
{
    csgp4::TimeSpan ts1(0, 23, 59, 59);
    csgp4::TimeSpan ts2(1, 23, 59, 59);
    EXPECT_EQ(true, ts1 != ts2);
}    

TEST(TimeSpan_test_case, TimeSpan_Operator_GreaterThan)
{
    csgp4::TimeSpan ts1(0, 23, 59, 59);
    csgp4::TimeSpan ts2(1, 23, 59, 59);
    EXPECT_EQ(true, ts2 > ts1);
}    

TEST(TimeSpan_test_case, TimeSpan_Operator_LessThan)
{
    csgp4::TimeSpan ts1(0, 23, 59, 59);
    csgp4::TimeSpan ts2(1, 23, 59, 59);
    EXPECT_EQ(true, ts1 < ts2);
}    

TEST(TimeSpan_test_case, TimeSpan_Operator_GreaterThanOrEqual)
{
    csgp4::TimeSpan ts1(0, 23, 59, 59);
    csgp4::TimeSpan ts2(1, 23, 59, 59);
    csgp4::TimeSpan ts3(1, 23, 59, 59);
    EXPECT_EQ(true, ts2 >= ts1);
    EXPECT_EQ(true, ts2 >= ts3);
}    

TEST(TimeSpan_test_case, TimeSpan_Operator_LessThanOrEqual)
{
    csgp4::TimeSpan ts1(0, 23, 59, 59);
    csgp4::TimeSpan ts2(1, 23, 59, 59);
    csgp4::TimeSpan ts3(1, 23, 59, 59);
    EXPECT_EQ(true, ts1 <= ts2);
    EXPECT_EQ(true, ts2 <= ts3);
}    





