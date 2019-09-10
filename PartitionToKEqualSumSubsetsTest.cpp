#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "PartitionToKEqualSumSubsets.h"
TEST_CASE("Test Partition To K Equal Sum Subsets") {
  vector<int> nums1{4, 3, 2, 3, 5, 2, 1};
  int k1 = 4;
  vector<int> nums2{85, 35, 40, 64, 86, 45, 63, 16, 5364, 110, 5653, 97, 95};
  int k2 = 7;
  vector<int> nums3{8, 2, 5, 3, 3};
  int k3 = 3;
  REQUIRE(!canPartitionKSubsetsDP(nums3, k3));
  REQUIRE(!canPartitionKSubsetsDP(nums2, k2));
  REQUIRE(canPartitionKSubsetsDP(nums1, k1));
  REQUIRE(!canPartitionKSubsets(nums3, k3));
  REQUIRE(!canPartitionKSubsets(nums2, k2));
  REQUIRE(canPartitionKSubsets(nums1, k1));
}