#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "UniqueBinarySearchTrees.h"

TEST_CASE("Test Unique Binary Search Trees") {
  REQUIRE(numTrees(3) == 5);
}