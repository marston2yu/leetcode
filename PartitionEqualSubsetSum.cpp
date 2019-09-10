#include "PartitionEqualSubsetSum.h"
#include <numeric>

bool canPartition(vector<int> &nums) {
  // Calculate sum of numbers.
  int sum = accumulate(nums.begin(), nums.end(), 0.0);
  if (sum % 2) return false; // Not possible to divide a odd sum into two equal part.

  // 0-1 package problem. Choosing numbers that add up to sum/2.
  // dp[i][j]: For first i number, whether we choose numbers add up to j. 
  //    dp[i][j] = dp[i-1][j-nums[i]] for choosing the i th number,
  //    dp[i][j] = dp[i-1][j] for not choosing the i th number.
  //    Initial condition: dp[k][0] = True.
  int half = sum / 2;
  int n = nums.size();
  vector<int> dp(half + 1);
  vector<int> pre(half + 1);
  dp[0] = 1;
  pre[0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= half; j++) {
      if (j - nums[i - 1] >= 0) {
        dp[j] = (pre[j - nums[i - 1]] || dp[j]);
      }
    }
    pre = dp;
  }
  return dp[half];
}
