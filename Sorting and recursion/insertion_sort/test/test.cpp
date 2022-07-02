#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iterator>
#include "../ura.hpp"
#include "doctest.h"

namespace doctest {
template <>
struct StringMaker<std::vector<int>> {
  static String convert(const std::vector<int>& value) {
    String output = "std::vector{";
    for (auto&& el : value) {
      output += toString(el);
      output += ",";
    }
    output[output.size() - 1] = '}';
    return output;
  }
};
}  // namespace doctest

TEST_CASE("Test: Sortiranje niza od vise elemenata") {
  std::vector<int> expected{-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0,
                            1,   2,  3,  4,  5,  6,  7,  8,  9,  10};
  std::vector<int> t{-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0,
                     1,   2,  3,  4,  5,  6,  7,  8,  9,  10};

  SUBCASE("1") {
    std::random_shuffle(t.begin(), t.end());
    INFO(t);
    insertionsort(t.begin(), t.end());
    CHECK(t == expected);
  }

  SUBCASE("2") {
    std::random_shuffle(t.begin(), t.end());
    INFO(t);
    insertionsort(t.begin(), t.end());
    CHECK(t == expected);
  }

  SUBCASE("3") {
    std::random_shuffle(t.begin(), t.end());
    INFO(t);
    insertionsort(t.begin(), t.end());
    CHECK(t == expected);
  }

  SUBCASE("4") {
    std::random_shuffle(t.begin(), t.end());
    INFO(t);
    insertionsort(t.begin(), t.end());
    CHECK(t == expected);
  }

  SUBCASE("5") {
    std::random_shuffle(t.begin(), t.end());
    INFO(t);
    insertionsort(t.begin(), t.end());
    CHECK(t == expected);
  }

}

