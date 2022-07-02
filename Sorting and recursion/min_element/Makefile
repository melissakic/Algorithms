all: main.cpp ura.cpp ura.hpp
	clang++ main.cpp ura.cpp -o zadatak4

tests: ura.cpp ura.hpp test/test.cpp	
	clang++ ura.cpp test/test.cpp -o test/tests

test: tests
	./test/tests -s

clean:
	rm -rf zadatak4 test/tests

