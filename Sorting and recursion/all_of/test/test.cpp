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
  SUBCASE("Svi su parni") {
    std::vector<int> t{1, 3, 5, 7, 9};
    INFO(t);
    REQUIRE(::all_of(t.begin(), t.end(), [](const auto& el) { return el % 2; }) == true);
  }

  SUBCASE("Jedan neparan") {
    std::vector<int> t{1, 3, 5, 7, 9, 10};
    INFO(t);
    REQUIRE(::all_of(t.begin(), t.end(), [](const auto& el) { return el % 2; }) == false);
  }

  SUBCASE("Svi su neparni") {
    std::vector<int> t{2, 4, 6, 8, 10};
    INFO(t);
    REQUIRE(::all_of(t.begin(), t.end(), [](const auto& el) { return el % 2; }) == false);
  }
}

TEST_CASE("Test 2: Niz od nula elemenata je tacan") {
  std::vector<int> t;
  CHECK(::all_of(t.begin(), t.end(), [](auto el) { return true; }));
}
