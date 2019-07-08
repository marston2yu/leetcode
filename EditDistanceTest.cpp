#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "EditDistance.h"

TEST_CASE("Test edit distance algorithm.") {
  REQUIRE(minDistance("a", "a") == 0);
  REQUIRE(minDistance("sea", "ate") == 3);
}