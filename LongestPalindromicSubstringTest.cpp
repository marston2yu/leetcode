//
// Created by Marston Yu on 2019-02-20.
//
#define CATCH_CONFIG_MAIN
#include <string>
#include <catch2/catch.hpp>
#include "LongestPalindromicSubstring.h"

using namespace std;

TEST_CASE("Test dynamic programming solution.") {
  REQUIRE(dynamicProgrammingSolution("abcba")=="abcba");
  REQUIRE(dynamicProgrammingSolution("bananas")=="anana");
  REQUIRE(dynamicProgrammingSolution("")=="");
  REQUIRE(dynamicProgrammingSolution("babad")=="bab");
  REQUIRE(dynamicProgrammingSolution("cbbd")=="bb");
}