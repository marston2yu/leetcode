#include "StoneGame.h"

bool stoneGame(vector<int> &piles) {
  int n = piles.size();
  vector<vector<pair<int, int>>> maxP;
  for (int i = 0; i < n; i++) {
    vector<pair<int, int>> v(n, make_pair(0, 0));
    maxP.push_back(v);
  }

  maxP[n - 1][n - 1].first = piles[n - 1];
  maxP[n - 1][n - 1].second = 0;

  for (int i = n - 2; i >= 0; i--) {
    maxP[i][i].first = piles[i];
    maxP[i][i].second = 0;
    for (int j = i + 1; j < n; j++) {
      int maxLeft = piles[i] + maxP[i + 1][j].second;
      int maxRight = piles[j] + maxP[i][j - 1].second;
      maxP[i][j].first = max(maxLeft, maxRight);
      maxP[i][j].second =
          maxLeft > maxRight ? maxP[i + 1][j].first : maxP[i][j - 1].first;
    }
  }
  return maxP[0][n - 1].first - maxP[0][n - 1].second > 0;
}
