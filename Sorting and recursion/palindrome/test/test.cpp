#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iterator>
#include "../ura.hpp"
#include "doctest.h"

TEST_CASE("Test 1: Test palindroma") {
  auto t1 = "a";
  INFO("Testing: ", t1);
  CHECK(palindrome(t1, strlen(t1)));

  auto t2 = "aha";
  INFO("Testing: ", t2);
  CHECK(palindrome(t2, strlen(t2)));

  auto t3 = "anavolimilovana";
  INFO("Testing: ", t3);
  CHECK(palindrome(t3, strlen(t3)));
}

TEST_CASE("Test 2: Test ne-palindroma") {
  auto t1 = "ab";
  INFO("Testing: ", t1);
  CHECK(!palindrome(t1, strlen(t1)));

  auto t2 = "ahu";
  INFO("Testing: ", t2);
  CHECK(!palindrome(t2, strlen(t2)));

  auto t3 = "ananevolimilovana";
  INFO("Testing: ", t3);
  CHECK(!palindrome(t3, strlen(t3)));
}

TEST_CASE("Test 3: Prazan string je palindrom") {
  auto t1 = "";
  CHECK(palindrome(t1, strlen(t1)));
}
