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

#include "csgp4/DateTime.h"

TEST(DateTime_suite, DateTime_ctor_0args)
{
    csgp4::DateTime dt;
    std::string expect = std::string("0001-01-01 00:00:00.000000 UTC");
    std::string actual = dt.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    

TEST(DateTime_suite, DateTime_ctor_year_doy)
{
    csgp4::DateTime dt(2022, 250.56);
    std::string expect = std::string("2022-09-07 13:26:24.000008 UTC");
    std::string actual = dt.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    

TEST(DateTime_suite, DateTime_ctor_3args)
{
    csgp4::DateTime dt(2022, 6, 4);
    std::string expect = std::string("2022-06-04 00:00:00.000000 UTC");
    std::string actual = dt.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    

TEST(DateTime_suite, DateTime_ctor_6args)
{
    csgp4::DateTime dt(2022, 6, 4, 12, 34, 56);
    std::string expect = std::string("2022-06-04 12:34:56.000000 UTC");
    std::string actual = dt.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}    

TEST(DateTime_suite, DateTime_Initialise)
{
    csgp4::DateTime dt;
    dt.Initialise(2022, 6, 4, 12, 34, 56, 500000);
    std::string expect = std::string("2022-06-04 12:34:56.500000 UTC");
    std::string actual = dt.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}

TEST(DateTime_suite, DateTime_ctor_Initialise_leapyear)
{
    csgp4::DateTime dt;
    dt.Initialise(2020, 6, 4, 12, 34, 56, 500000);
    std::string expect = std::string("2020-06-04 12:34:56.500000 UTC");
    std::string actual = dt.ToString();
    EXPECT_STREQ(expect.c_str(), actual.c_str());
}

TEST(DateTime_suite, DateTime_IsLeapYear)
{
    EXPECT_TRUE(csgp4::DateTime::IsLeapYear(2020));
    EXPECT_FALSE(csgp4::DateTime::IsLeapYear(2021));
}

TEST(DateTime_suite, DateTime_IsValidYear)
{
    EXPECT_TRUE(csgp4::DateTime::IsValidYear(2020));
    EXPECT_FALSE(csgp4::DateTime::IsValidYear(-2021));
    EXPECT_FALSE(csgp4::DateTime::IsValidYear(10001));
}

TEST(DateTime_suite, DateTime_IsValidYearMonth)
{
    EXPECT_TRUE(csgp4::DateTime::IsValidYearMonth(2020, 6));
    EXPECT_FALSE(csgp4::DateTime::IsValidYearMonth(2020, -1));
    EXPECT_FALSE(csgp4::DateTime::IsValidYearMonth(2020, 13));
}

TEST(DateTime_suite, DateTime_IsValidYearMonthDay)
{
    EXPECT_TRUE(csgp4::DateTime::IsValidYearMonthDay(2020, 6, 6));
    EXPECT_TRUE(csgp4::DateTime::IsValidYearMonthDay(2020, 2, 29));
    EXPECT_FALSE(csgp4::DateTime::IsValidYearMonthDay(2021, 2, 29));
}

TEST(DateTime_suite, DateTime_DaysInMonth)
{
    EXPECT_EQ(28, csgp4::DateTime::DaysInMonth(2021, 2));
    EXPECT_EQ(29, csgp4::DateTime::DaysInMonth(2020, 2));
}


