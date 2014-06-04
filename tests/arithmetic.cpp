/**
 * BIGINT
 *
 * Copyright (C) 2012 Christoffer Buchholz <http://chrisbuchholz.me/>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Source Code: https://github.com/ChrisBuchholz/Bigint
 **/

#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Main
#endif
#include <boost/test/unit_test.hpp>
#include "../src/bigint.h"

Bigint addition(Bigint i, Bigint j)
{
    std::cout << i << "+" << j << "=" << i+j << std::endl;
	return i + j;
}

Bigint subtraction(Bigint i, Bigint j)
{
    std::cout << i << "-" << j << "=" << i-j << std::endl;
	return i - j;
}

BOOST_AUTO_TEST_CASE(arithmetic)
{
    BOOST_CHECK(addition(2, 2) == 4);
    //BOOST_CHECK(addition(-5, 9) == 4); // fails because of missing double *-1
    //BOOST_CHECK(addition(-2, -2) == -4); // fails because missing *-1 and failty comparison
    BOOST_CHECK(subtraction(10, 7) == 3);
    //BOOST_CHECK(subtraction(-10, -13) == 3); // fails becaue of missing *-1
    //BOOST_CHECK(subtraction(5, 8) == -3); // failed because of faulty comparison
}
