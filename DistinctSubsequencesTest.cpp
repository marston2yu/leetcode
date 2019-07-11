#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "DistinctSubsequences.h"

TEST_CASE("Test Distinct Sub-sequences solution.") {
  REQUIRE(numDistinct("a", "b")==0);
  REQUIRE(numDistinct("rabbbit", "rabbit")==3);
  REQUIRE(numDistinct("aacaacca", "ca")==5);
}

