#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "PartitionEqualSubsetSum.h"

TEST_CASE("Test Partition Equal Subset Sum") {
  vector<int> nums{1, 2, 5};
  REQUIRE(!canPartition(nums));
}