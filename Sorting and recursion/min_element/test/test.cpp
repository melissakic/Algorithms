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

TEST_CASE("Test 1: Niz od vise elemenata") {
  std::vector<int> t;
  SUBCASE("") {
    t = std::vector<int>{10};
    INFO(t);
    REQUIRE(min(t.data(), t.size()) == 10);
  }

  SUBCASE("") {
    t = std::vector<int>{50, 40, 30, 20, 10};
    INFO(t);
    CHECK(min(t.data(), t.size()) == 10);
  }

  SUBCASE("") {
    t = std::vector<int>{10, 50, 40, 30, 20, 10};
    INFO(t);
    CHECK(min(t.data(), t.size()) == 10);
  }

  SUBCASE("") {
    t = std::vector<int>{50, 40, 10, 30, 20};
    INFO(t);
    REQUIRE(min(t.data(), t.size()) == 10);
  }
}

TEST_CASE("Test 2: Niz od nula elemenata baca iznimku") {
  int t[0];
  REQUIRE_THROWS(min(t, 0));
}
