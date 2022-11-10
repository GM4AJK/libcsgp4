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

#include <sstream>
#include <gtest/gtest.h>

#include "config.h"
#include "version.h"

using csgp4::version;

TEST(version_test_case, version_test)
{
	std::stringstream oss;
	std::string gittag = std::string(GIT_TAG);
	oss << LIBCSGP4_VERSION; 
	if(gittag.length() > 0) {
		oss << "-" << gittag;
	}

	std::string expect = oss.str(); 
	std::string actual = version::get();

	EXPECT_STREQ(expect.c_str(), actual.c_str());
}

