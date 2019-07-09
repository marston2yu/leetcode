#include "UniquePathsII.h"

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();

  if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0; // start or target is blocked.
  if (m == 1 || n == 1) return 1;

  // memoization of how many path are there from start to (i, j).
  // using obstacleGrid as memo to optimize memory consumption.

  // initialize first row.
  obstacleGrid[0][0] = 1;
  for (int j = 1; j < n; ++j) {
    if (obstacleGrid[0][j] == 0 && obstacleGrid[0][j - 1] == 1) {
      obstacleGrid[0][j] = 1;
    } else {
      obstacleGrid[0][j] = 0;
    }
  }


  for (int i = 1; i < m; ++i) {
    // initialize first column.
    if (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) {
      obstacleGrid[i][0] = 1;
    } else {
      obstacleGrid[i][0] = 0;
    }

    for (int j = 1; j < n; ++j) {
      if (obstacleGrid[i][j] == 1) {
        obstacleGrid[i][j] = 0;
      } else {
        // enforce type conversion to avoid signed integer overflow.
        obstacleGrid[i][j] = (unsigned) obstacleGrid[i - 1][j] + (unsigned) obstacleGrid[i][j - 1];
      }
    }
  }
  return obstacleGrid[m - 1][n - 1];
}