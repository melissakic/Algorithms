all: main.cpp ura.hpp
	clang++ main.cpp -o zadatak13

tests: ura.hpp test/test.cpp	
	clang++ test/test.cpp -o test/tests

test: tests
	./test/tests -s

clean:
	rm -rf zadatak13 test/tests

