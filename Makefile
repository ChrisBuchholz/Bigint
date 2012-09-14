CC       = 	clang++
CXXFLAGS = 	-std=c++11 -stdlib=libc++ -g -Wall

all: prepare bigint

prepare:
	@mkdir -p build/Bigint/include/ build/Bigint/lib/
	@cp LICENSE build/Bigint/

bigint: src/bigint.cpp
	$(CC) $(CXXFLAGS) -c src/bigint.cpp -o build/Bigint/lib/bigint.o
	@cp src/bigint.h build/Bigint/include/

tests:
	$(CC) $(CXXFLAGS) \
		tests/test.cpp \
		tests/arithmetic.cpp \
		tests/assignment.cpp \
		-o tests/run_tests \
		build/Bigint/lib/bigint.o \
		/usr/local/lib/boost/libboost_unit_test_framework.a
	./tests/run_tests

clean:
	rm -rfv build/
	rm -v tests/run_tests

.PHONY: all tests clean
