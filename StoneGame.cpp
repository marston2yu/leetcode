#include "StoneGame.h"

bool stoneGame(vector<int> &piles) {
  int n = piles.size();
  vector<pair<int, int>> maxP(n, make_pair(0, 0));

  // Store maximum point one can get with pile[i...j].
  // First is the point that one can get on offensive.
  // Second is the point that one can get on defensive.
  maxP[n - 1].first = piles[n - 1];
  maxP[n - 1].second = 0;

  for (int i = n - 2; i >= 0; i--) {
    maxP[i].first = piles[i];
    maxP[i].second = 0;
    for (int j = i + 1; j < n; j++) {
      int maxLeft = piles[i] + maxP[j].second;
      int maxRight = piles[j] + maxP[j - 1].second;
      maxP[j].first = max(maxLeft, maxRight);
      // When the offensive side determines its move, the defensive side becomes offensive side
      // with remaining piles.
      maxP[j].second = maxLeft > maxRight ? maxP[j].first : maxP[j - 1].first;
    }
  }
  // Return whether the offensive side will win.
  return maxP[n - 1].first - maxP[n - 1].second > 0;
}
