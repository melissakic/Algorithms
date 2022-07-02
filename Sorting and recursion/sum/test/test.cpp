#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iterator>
#include "../ura.hpp"
#include "doctest.h"

TEST_CASE("Test 1: Niz od nula elemenata") {
  int t[0];
  CHECK(sum(t, 0) == 0);
}

TEST_CASE("Test 2: Niz od vise elemenata") {
  int t[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  CHECK(sum(t, 1) == 10);
  CHECK(sum(t, 2) == 30);
  CHECK(sum(t, 3) == 60);
  CHECK(sum(t, 4) == 100);
  CHECK(sum(t, 5) == 150);
  CHECK(sum(t, 6) == 210);
  CHECK(sum(t, 7) == 280);
  CHECK(sum(t, 8) == 360);
  CHECK(sum(t, 9) == 450);
  CHECK(sum(t, 10) == 550);
}
