#include "Triangle.h"

int minimumTotal(vector<vector<int>> &triangle) {
  int n = triangle.size();
  int m = triangle[n - 1].size();
  vector<vector<int>> dp(n, vector<int>(m));
  dp[0][0] = triangle[0][0];
  for (int i = 1; i < n; i++) {
    dp[i][0] = dp[i - 1][0] + triangle[i][0];
    if (i >= 1) dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    for (int j = 1; j <= i - 1; j++) {
      dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
    }
  }
  int mi = 100000;
  for (int i = 0; i < m; i++) {
    mi = min(mi, dp[n - 1][i]);
  }
  return mi;
}