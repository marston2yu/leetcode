#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "Triangle.h"

TEST_CASE("Test Triangle") {
  vector<vector<int>> v{{2},
                        {3, 4},
                        {6, 5, 7},
                        {4, 1, 8, 3}};

  REQUIRE(minimumTotal(v) == 11);
}