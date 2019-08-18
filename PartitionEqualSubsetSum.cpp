#include "PartitionEqualSubsetSum.h"
#include <numeric>

bool canPartition(vector<int> &nums) {
  int sum = accumulate(nums.begin(), nums.end(), 0.0);
  if (sum % 2) return false;

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
