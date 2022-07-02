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
  std::vector<int> t{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  INFO(t);
  auto neparan = [](int el) { return el % 2; };
  auto r = ::partition(t.begin(), t.end(), neparan);

  SUBCASE("Svi prije povratnog iteratora su neparni") {
    for (auto it = t.begin(); it < r; it++) CHECK(neparan(*it));
  }
  SUBCASE("Svi poslije povratnog iteratora su parni") {
    for (auto it = r; it < t.end(); it++) CHECK(!neparan(*it));
  }
}

TEST_CASE("Test 2: Niz od jednog elemenata") {
  std::vector<int> t{1};
  INFO(t);

  SUBCASE("Ako je uslov tacan") {
    auto neparan = [](int el) { return el % 2; };
    auto r = ::partition(t.begin(), t.end(), neparan);
    CHECK(r == t.end());
  }

  SUBCASE("Ako uslov nije tacan") {
    auto paran = [](int el) { return el % 2 == 0; };
    auto r = ::partition(t.begin(), t.end(), paran);
    CHECK(r == t.begin());
  }
}
