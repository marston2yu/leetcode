#include "UniquePathsII.h"

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();

  if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0; // start or target is blocked.
  if (m == 1 || n == 1) return 1;

  // memoization of how many path are there from start to (i, j).
  vector<vector<unsigned>> P(m, vector<unsigned>(n, 1)); // use unsigned integer to avoid overflow.

  // initialize first row.
  for (int j = 1; j < n; ++j) {
    if (obstacleGrid[0][j] == 0 && P[0][j - 1] == 1) {
      P[0][j] = 1;
    } else {
      P[0][j] = 0;
    }
  }


  for (int i = 1; i < m; ++i) {
    // initialize first column.
    if (obstacleGrid[i][0] == 0 && P[i - 1][0] == 1) {
      P[i][0] = 1;
    } else {
      P[i][0] = 0;
    }

    for (int j = 1; j < n; ++j) {
      if (obstacleGrid[i][j] == 1) {
        P[i][j] = 0;
      } else {
        P[i][j] = P[i - 1][j] + P[i][j - 1];
      }
    }
  }
  return P[m - 1][n - 1];
}