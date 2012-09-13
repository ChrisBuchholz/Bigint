#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <vector>
#include <string>
#include <ostream>

class Bigint {
	private:
		bool isSigned;
		std::vector<int> number; 

	public:
		Bigint& operator=(const Bigint &);
		Bigint& operator=(const std::string &);
		Bigint& operator=(const int);
		Bigint& operator+(Bigint &);
		Bigint operator+(int);

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
