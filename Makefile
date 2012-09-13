CC       = 	clang++
CXXFLAGS = 	-std=c++11 -stdlib=libc++ -g -Wall

all: bigint test

bigint: src/bigint.cpp
	$(CC) $(CXXFLAGS) -c src/bigint.cpp -o src/bigint.o

test:
	$(CC) $(CXXFLAGS) \
		tests/test.cpp \
		tests/arithmetic.cpp \
		tests/assignment.cpp \
		-o tests/test \
		src/bigint.o /usr/local/lib/boost/libboost_unit_test_framework.a

clean:
	rm -v src/bigint.o
	rm -v tests/test

.PHONY: clean
