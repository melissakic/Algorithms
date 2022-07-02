all: main.cpp ura.hpp
	clang++ main.cpp -o zadatak5

tests: ura.hpp test/test.cpp	
	clang++ test/test.cpp -o test/tests

test: tests
	./test/tests -s

clean:
	rm -rf zadatak5 test/tests

