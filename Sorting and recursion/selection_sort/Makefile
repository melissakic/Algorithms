all: main.cpp ura.hpp
	clang++ main.cpp -o zadatak9

tests: ura.hpp test/test.cpp	
	clang++ test/test.cpp -o test/tests

test: tests
	./test/tests -s

clean:
	rm -rf zadatak9 test/tests

