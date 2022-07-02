#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iterator>
#include <list>
#include "../ura.hpp"
#include "doctest.h"

namespace doctest {
template <>
struct StringMaker<std::list<int>> {
  static String convert(const std::list<int>& value) {
    String output = "std::list{";
    for (auto&& el : value) {
      output += toString(el);
      output += ",";
    }
    output[output.size() - 1] = '}';
    return output;
  }
};
}  // namespace doctest

void list_shuffle(std::list<int>& l) {
  std::vector<int> temp(l.begin(), l.end());
  std::random_shuffle(temp.begin(), temp.end());
  std::copy(temp.begin(), temp.end(), l.begin());
}

TEST_CASE("Test: Sortiranje niza od vise elemenata") {
  std::list<int> expected{-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0,
                            1,   2,  3,  4,  5,  6,  7,  8,  9,  10};
  std::list<int> t{-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0,
                     1,   2,  3,  4,  5,  6,  7,  8,  9,  10};

  SUBCASE("1") {
    list_shuffle(t);
    INFO(t);
    bubblesort(t.begin(), t.end());
    CHECK(t == expected);
  }

  SUBCASE("2") {
    list_shuffle(t);
    INFO(t);
    bubblesort(t.begin(), t.end());
    CHECK(t == expected);
  }

  SUBCASE("3") {
    list_shuffle(t);
    INFO(t);
    bubblesort(t.begin(), t.end());
    CHECK(t == expected);
  }

  SUBCASE("4") {
    list_shuffle(t);
    INFO(t);
    bubblesort(t.begin(), t.end());
    CHECK(t == expected);
  }

  SUBCASE("5") {
    list_shuffle(t);
    INFO(t);
    bubblesort(t.begin(), t.end());
    CHECK(t == expected);
  }
}

