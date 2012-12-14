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

#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <vector>
#include <string>
#include <ostream>

class Bigint {
	private:
		bool isPositive = true;
		std::vector<int> number; 

	public:
		Bigint& operator=(const Bigint &);
		Bigint& operator=(const std::string &);
		Bigint& operator=(const int);
		Bigint& operator+(Bigint &);
		Bigint& operator+(const int);
		Bigint& operator-(Bigint &);
		Bigint& operator-(const int);

        Bigint(); // NULL construction
        Bigint(const int &); // giving int
        Bigint(const std::string &); // giving string of numbers
        Bigint(const std::vector<int> &); // giving vector of ints
        Bigint(const Bigint &); // copy

        friend std::ostream &operator<<(std::ostream &, Bigint &);
        friend bool operator==(const Bigint &first, const Bigint &last);

        std::string to_string() const;
        std::vector<int> to_vector() const;
};

#endif
