#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Main
#endif
#include <boost/test/unit_test.hpp>
#include "../src/bigint.h"

Bigint addition(Bigint i, Bigint j)
{
	return i + j;
}

BOOST_AUTO_TEST_CASE(arithmetic)
{
	BOOST_CHECK(addition(2, 2) == 4);
}
