//
// Created by marston on 2019/2/20.
//

#define CATCH_CONFIG_MAIN

#include <string>
#include <catch2/catch.hpp>
#include "LongestSubstringWithoutRepeating.h"

using namespace std;

TEST_CASE("Test sliding windows solution.") {
  REQUIRE(sliderWindow("bbbbbb") == 1);
  REQUIRE(sliderWindow("abcabcbb") == 3);
  REQUIRE(sliderWindow("pwwkew") == 3);
}

TEST_CASE("Test sliding windows with map.") {
  REQUIRE(sliderWindowMap("tmmzuxt") == 5);
  REQUIRE(sliderWindowMap("bbbbbb") == 1);
  REQUIRE(sliderWindowMap("abcabcbb") == 3);
  REQUIRE(sliderWindowMap("pwwkew") == 3);
}

TEST_CASE("Test sliding windows with array as look-up table.") {
  REQUIRE(sliderWindowTable(" ") == 1);
  REQUIRE(sliderWindowTable("tmmzuxt") == 5);
  REQUIRE(sliderWindowTable("bbbbbb") == 1);
  REQUIRE(sliderWindowTable("abcabcbb") == 3);
  REQUIRE(sliderWindowTable("pwwkew") == 3);
}