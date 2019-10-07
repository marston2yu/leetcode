#include "Triangle.h"

int minimumTotal(vector<vector<int>> &triangle) {
  int n = triangle.size();
  int m = triangle[n - 1].size();
  vector<int> dp(m);
  dp[0] = triangle[0][0];
  for (int i = 1; i < n; i++) {
    if (i >= 1) dp[i] = dp[i - 1] + triangle[i][i];
    int pre = dp[0];
    dp[0] = dp[0] + triangle[i][0];
    for (int j = 1; j <= i - 1; j++) {
      int tmp = dp[j];
      dp[j] = min(pre, dp[j]) + triangle[i][j];
      pre = tmp;
    }
  }
  int mi = 100000;
  for (int i = 0; i < m; i++) {
    mi = min(mi, dp[i]);
  }
  return mi;
}