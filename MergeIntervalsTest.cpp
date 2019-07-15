#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "MergeIntervals.h"

TEST_CASE("Test merge intervals.") {
  vector<vector<int>> a{
          {2, 3},
          {4, 5},
          {6, 7},
          {8, 9},
          {1, 10}
  };
  vector<vector<int>> b{
          {1, 10}
  };
  REQUIRE(merge(a) == b);
}


