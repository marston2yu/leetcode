#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "LargestRectangleInHistogram.h"

TEST_CASE("Test largest rectangle in histogram") {
  vector<int> d = {4, 2, 0, 3, 2, 5};
  REQUIRE(largestRectangleArea(d)==6);
  vector<int> c = {1, 2, 2};
  REQUIRE(largestRectangleArea(c)==4);
  vector<int> a = {2, 1, 5, 6, 2, 3};
  REQUIRE(largestRectangleArea(a)==10);
  vector<int> b = {1, 1};
  REQUIRE(largestRectangleArea(b)==2);
}