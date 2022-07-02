#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../ura.hpp"

TEST_CASE("Test 1: Dijeljenje bez ostatka") {
  CHECK(divide(5, 5) == 1);
  CHECK(divide(10, 5) == 2);
  CHECK(divide(15, 5) == 3);
  CHECK(divide(20, 5) == 4);
}

TEST_CASE("Test 2: Dijeljenje sa ostatkom") {
  CHECK(divide(7, 5) == 1);
  CHECK(divide(17, 5) == 3);
  CHECK(divide(22, 5) == 4);
}

TEST_CASE("Test 3: Dijeljenje nulom") {
  REQUIRE_THROWS(divide(10, 0));
}
