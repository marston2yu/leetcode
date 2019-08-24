#include "PartitionToKEqualSumSubsets.h"
#include <numeric>
vector<int> visited;
int avg;

/**
 * @brief DFS for partitioning a set to k equal groups.
 * Partition a subset nums[pos:] to k groups.
 * 
 * @param nums Set of integers for patitioning.
 * @param k Group numbers.
 * @param sum Accumulated set value.
 * @param pos Searching start position.
 * @return true Partition succeed.
 * @return false Partition failed.
 */
bool dfs(const vector<int>& nums, int k, int sum, int pos) {
  if (sum == avg) return dfs(nums, k - 1, 0, 0);  // One group found, find the other groups.
  if (sum > avg) return false;                    // Exceed average, there is no need to add more number.
  if (k == 0) return true;                        // All groups are partitioned.
  for (int i = pos; i < nums.size(); i++) {
    if (!visited[i]) {
      visited[i] = 1;
      if (dfs(nums, k, sum + nums[i], pos + 1)) return true;  // Add current number to sum and check if a group is found.
      visited[i] = 0;                                         // Back to the most recent node only when accumulating group failed.
    }
  }
  return false;  // All search failed.
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
  int sum = accumulate(nums.begin(), nums.end(), 0.0);
  if (sum % k) return false;
  avg = sum / k;

  // Sort can make the algorithm faster?
  sort(nums.rbegin(), nums.rend());

  visited.resize(nums.size());
  return dfs(nums, k, 0, 0);
}