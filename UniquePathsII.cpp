#include "UniquePathsII.h"

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();

  if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0; // start or target is blocked.
  if (m == 1 || n == 1) return 1;

  // memoization of how many path are there from (i, j) to target.
  // using obstacleGrid as memo to optimize memory consumption.

  // initialize last row.
  obstacleGrid[m - 1][n - 1] = 1;
  for (int j = n - 2; j >= 0; --j) {
    if (obstacleGrid[m - 1][j] == 0 && obstacleGrid[m - 1][j + 1] == 1) {
      obstacleGrid[m - 1][j] = 1;
    } else {
      obstacleGrid[m - 1][j] = 0;
    }
  }


  for (int i = m - 2; i >= 0; --i) {
    // initialize last column.
    if (obstacleGrid[i][n - 1] == 0 && obstacleGrid[i + 1][n - 1] == 1) {
      obstacleGrid[i][n - 1] = 1;
    } else {
      obstacleGrid[i][n - 1] = 0;
    }

    for (int j = n - 2; j >= 0; --j) {
      if (obstacleGrid[i][j] == 1) {
        obstacleGrid[i][j] = 0;
      } else {
        // enforce type conversion to avoid signed integer overflow.
        obstacleGrid[i][j] = (unsigned) obstacleGrid[i + 1][j] + (unsigned) obstacleGrid[i][j + 1];
      }
    }
  }
  return obstacleGrid[0][0];
}