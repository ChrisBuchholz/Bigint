CC       = 	clang++
CXXFLAGS = 	-std=c++11 -stdlib=libc++ -g -Wall

all: prepare bigint

prepare:
	@mkdir -p build/Bigint/include/ build/Bigint/lib/
	@cp LICENSE build/Bigint/

bigint: src/bigint.cpp
	$(CC) $(CXXFLAGS) -c src/bigint.cpp -o build/Bigint/lib/bigint.o
	@cp src/bigint.h build/Bigint/include/

test:
	$(CC) $(CXXFLAGS) \
		tests/test.cpp \
		tests/arithmetic.cpp \
		tests/assignment.cpp \
		-o tests/test \
		build/Bigint/lib/bigint.o \
		/usr/local/lib/boost/libboost_unit_test_framework.a
	./tests/test

clean:
	rm -rfv build/
	rm -v tests/test

.PHONY: clean
