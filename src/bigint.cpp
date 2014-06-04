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

#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include "bigint.h"

Bigint &Bigint::operator=(const Bigint &num)
{
    return *this;
}

Bigint &Bigint::operator=(const std::string &strNum)
{
    std::string::const_iterator i;

    if (strNum[0] == '-') {
        this->isPositive = false;
        i = strNum.begin() + 1;
    }
    else {
        i = strNum.begin();
    }

    for (; i != strNum.end(); ++i)
        this->number.push_back(*i - '0');

    return *this;
}

Bigint& Bigint::operator=(const int num)
{
    *this = std::to_string(num);
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

    Bigint *new_num = new Bigint(big_num); 

    //if (num.to_string()[0] == '-' || !this->isPositive) {
        //new_num = new_num * -1;
    //}

    return *new_num;
}

Bigint& Bigint::operator+(const int num)
{
    *this + *(new Bigint(num));
    return *this;
}

Bigint& Bigint::operator-(Bigint &num)
{
    std::vector<int> big_num, lil_num;

    if (num.to_vector().size() > this->number.size()) {
        big_num = num.to_vector();
        lil_num = this->to_vector();
    }
    else {
        big_num = this->to_vector();
        lil_num = num.to_vector();
    }

    std::vector<int>::reverse_iterator k;
    std::vector<int>::const_reverse_iterator j;

    for (k = big_num.rbegin(), j = lil_num.rbegin();
            j != lil_num.rend(); ++k, ++j) {
        if (*j > *k) {
            if (k == big_num.rend() - 1) {
                this->isPositive = false;
            }
            else {
                *(k+1) -= 1;
                *k += 10;
            }
        }
        *k -= *j;
    }

    for (std::vector<int>::iterator i = big_num.begin();
            i != big_num.end(); ++i) {
        if (*i == 0)
            i = big_num.erase(i);
    }

    Bigint *new_num = new Bigint(big_num); 

    //if (num.to_string()[0] == '-' || !this->isPositive) {
        //new_num = new_num * -1;
    //}

    return *new_num;
}

Bigint& Bigint::operator-(const int num)
{
    *this - *(new Bigint(num));
    return *this;
}

Bigint::Bigint(const int &num)
{
    *this = num;
}

Bigint::Bigint(const std::string &strNum)
{
    std::string::const_iterator i;

    if (strNum[0] == '-') {
        this->isPositive = false;
        i = strNum.begin() + 1;
    }
    else {
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

    if (num.to_string()[0] == '-')
        this->isPositive = false; 
}

std::ostream &operator<<(std::ostream &os, Bigint &num)
{
    return (os << num.to_string());
}

bool operator==(const Bigint &first, const Bigint &last)
{
    std::string firstStr = first.to_string();
    std::string lastStr = last.to_string();

    if (firstStr != lastStr)
        return false;

    return true;
}

std::string Bigint::to_string() const
{
    std::string str;

    if (!this->isPositive)
        str = '-';

    for (std::vector<int>::const_iterator i = this->number.begin();
            i != this->number.end(); ++i)
        str += std::to_string(*i);

    return str;
}

std::vector<int> Bigint::to_vector() const
{
    return this->number;
}
