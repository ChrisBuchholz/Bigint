#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Main
#endif
#include <boost/test/unit_test.hpp>
#include <string>
#include "../src/bigint.h"

Bigint fromBigint(Bigint n)
{
	Bigint a = n;
	return a;
}

Bigint fromString(std::string str)
{
	Bigint a = str;
	return a;
}

Bigint fromInt(int n)
{
	Bigint a = n;
	return a;
}

BOOST_AUTO_TEST_CASE(assignment)
{
	BOOST_CHECK(fromBigint(4) == 4);
	BOOST_CHECK(fromString("4") == 4);
	BOOST_CHECK(fromInt(4) == 4);
}
