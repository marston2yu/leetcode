#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "MedianOfTwoSortedArrays.h"

TEST_CASE("Test median of two sorted arrays.") {
  vector<int> a1{1, 3};
  vector<int> b1{2};
  vector<int> a2{1, 2};
  vector<int> b2{3, 4};
  REQUIRE(findMedianSortedArrays(a1, b1) == 2);
  REQUIRE(findMedianSortedArrays(a2, b2) == 2.5);
}
