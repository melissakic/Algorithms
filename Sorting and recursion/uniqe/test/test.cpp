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

TEST_CASE("Test 1: Niz koji nema duplikata") {
  std::vector<int> expected{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> t{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto ret = ::unique(t.begin(), t.end());
  CHECK(ret == t.end());
  CHECK(t == expected);
}

TEST_CASE("Test 2: Niz sa nekoliko duplih elemenata") {
  std::vector<int> expected{1, 2, 3, 4, 5, 6};
  SUBCASE("Na pocetku") {
    std::vector<int> t{1, 1, 1, 2, 3, 4, 5, 6};
    auto ret = ::unique(t.begin(), t.end());
    CHECK(std::vector<int>{t.begin(), ret} == expected);
  }
  SUBCASE("U sredini") {
    std::vector<int> t{1, 2, 3, 3, 3, 4, 5, 6};
    auto ret = ::unique(t.begin(), t.end());
    CHECK(std::vector<int>{t.begin(), ret} == expected);
  }
  SUBCASE("Na kraju") {
    std::vector<int> t{1, 2, 3, 4, 5, 6, 6, 6};
    auto ret = ::unique(t.begin(), t.end());
    CHECK(std::vector<int>{t.begin(), ret} == expected);
  }
  SUBCASE("Dosta duplikata") {
    std::vector<int> t{1, 1, 2, 3, 3, 4, 5, 5, 6, 6, 6};
    auto ret = ::unique(t.begin(), t.end());
    CHECK(std::vector<int>{t.begin(), ret} == expected);
  }
}

TEST_CASE("Test 3: Niz od jednog elementa") {
  std::vector<int> expected{1};
  SUBCASE("Samo jedan element") {
    std::vector<int> t{1};
    auto ret = ::unique(t.begin(), t.end());
    CHECK(std::vector<int>{t.begin(), ret} == expected);
  }
  SUBCASE("Vise puta se ponavlja jedan element") {
    std::vector<int> t{1, 1, 1, 1, 1, 1, 1, 1};
    auto ret = ::unique(t.begin(), t.end());
    CHECK(std::vector<int>{t.begin(), ret} == expected);
  }
}

TEST_CASE("Test 4: Prazan niz") {
  std::vector<int> expected;
  std::vector<int> t;
  auto ret = ::unique(t.begin(), t.end());
  CHECK(std::vector<int>{t.begin(), ret} == expected);
}
