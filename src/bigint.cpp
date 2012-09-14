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

#include "bigint.h"
#include <iostream>
#include <vector>
#include <string>
#include <ostream>

Bigint &Bigint::operator=(const std::string &strNum)
{
    std::string::const_iterator i;

    if (strNum[0] == '-') {
        this->isSigned = false;
        i = strNum.begin() + 1;
    }
    else {
        this->isSigned = true;
        i = strNum.begin();
    }

    for (; i != strNum.end(); ++i)
        this->number.push_back(*i - '0');

    return *this;
}

Bigint& Bigint::operator+(Bigint &num)
{
    std::vector<int> big_num, lil_num;
    std::vector<int>::reverse_iterator k;
    std::vector<int>::const_reverse_iterator j;

    if (num.to_vector().size() > this->number.size()) {
        big_num = num.to_vector();
        lil_num = this->to_vector();
    }
    else {
        big_num = this->to_vector();
        lil_num = num.to_vector();
    }

    for (k = big_num.rbegin(), j = lil_num.rbegin();
            j != lil_num.rend(); ++k, ++j)
        *k = *k + *j;

    for (k = big_num.rbegin(); k < big_num.rend(); ++k) {
        if (*k >= 10) {
            int inc = *k / 10;
            *k -= inc * 10;
            *(k+1) += inc;
            if (k == big_num.rend() - 1) {
                big_num.insert(big_num.begin(), inc);
            }
        }
    }

    return *(new Bigint(big_num));
}

Bigint::Bigint(const int &num)
{
    std::string str = std::to_string(num);
    *this = str;
}

Bigint::Bigint(const std::string &strNum)
{
    std::string::const_iterator i;

    if (strNum[0] == '-') {
        this->isSigned = false;
        i = strNum.begin() + 1;
    }
    else {
        this->isSigned = true;
        i = strNum.begin();
    }

    for (; i != strNum.end(); ++i)
        this->number.push_back(*i - '0');
}

Bigint::Bigint(const std::vector<int> &vnum)
{
    for (int i : vnum)
        this->number.push_back(i);
}

Bigint::Bigint(const Bigint &num)
{
    for (int i : num.to_vector())
        this->number.push_back(i);

    this->isSigned = false; 
}

std::ostream &operator<<(std::ostream &os, Bigint &num)
{
    return (os << num.to_string());
}

bool operator==(const Bigint &first, const Bigint &last)
{
    bool rtrn = true;
    std::vector<int> firstv = first.to_vector();
    std::vector<int> lastv = last.to_vector();

    for (std::vector<int>::const_iterator i = firstv.begin(), j = lastv.begin();
            i < firstv.end(), j < lastv.end(); ++i, ++j) {
        if (*i != *j)
            rtrn = false;
    }

    return rtrn;
}

std::string Bigint::to_string() const
{
    std::string str;

    for (std::vector<int>::const_iterator i = this->number.begin();
            i != this->number.end(); ++i)
        str += std::to_string(*i);

    return str;
}

std::vector<int> Bigint::to_vector() const
{
    return this->number;
}
