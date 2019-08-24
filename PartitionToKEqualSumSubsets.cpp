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

/**
 * @brief DFS solution(brute force method).
 * 
 */
bool canPartitionKSubsets(vector<int>& nums, int k) {
  int sum = accumulate(nums.begin(), nums.end(), 0.0);
  if (sum % k) return false;
  avg = sum / k;

  // Sort can make the algorithm faster?
  sort(nums.rbegin(), nums.rend());

  visited.resize(nums.size());
  return dfs(nums, k, 0, 0);
}

/**
 * @brief Mask dynamic programming solution.
 * 
 */
bool canPartitionKSubsetsDP(vector<int>& nums, int k) {
  int sum = accumulate(nums.begin(), nums.end(), 0.0);
  if (sum % k) return false;
  int avg = sum / k;

  sort(nums.begin(), nums.end());

  int n = nums.size();
  // DP array store whether a crossing occurs when adding up the subset specified by a mask.
  // A crossing occurs when adding a new number, the total value bypass `m` groups' sum.
  // For example, when average value of each group is `avg` and current sum is `m*avg-3` which indicate
  // we need more value to form m groups. But when a new number 6 adding to sum, a crossing occurs from
  // m groups to m+1 groups.
  // ==> We say a subset is without crossing only when subset of this subset is without crossing.
  // In fact, all numbers' sum equal to k*nums exactly. But what we have to figure out is whether a
  // subset sum up to m * avg.
  vector<int> dp(1 << n);     // 1 indicate no crossing occurs.
  vector<int> total(1 << n);  // Sum of subset specified by mask.
  dp[0] = 1;                  // Initial condition, {} is a subset without crossing.
  for (int mask = 0; mask < dp.size(); mask++) {
    if (dp[mask]) {  // Only when subset s is without crossing, subset + nums[j] can be a subset without crossing.
      for (int j = 0; j < nums.size(); j++) {
        int mask_next = mask | (1 << j);               // Mask of subset + nums[j].
        if (mask != mask_next) {                       // Current subset should not contain nums[j].
          if (nums[j] <= avg - (total[mask] % avg)) {  // Check whether crossing occur when adding nums[j].
            dp[mask_next] = 1;
            total[mask_next] = total[mask] + nums[j];
          } else { // When adding a smaller number will trigger crossing, there is no need to check greater numbers.
            break;
          }
        }
      }
    }
  }
  return dp[(1 << n) - 1];
}