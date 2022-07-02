all: main.cpp ura.hpp
	clang++ main.cpp -o zadatak8

tests: ura.hpp test/test.cpp	
	clang++ test/test.cpp -o test/tests

test: tests
	./test/tests -s

clean:
	rm -rf zadatak8 test/tests

