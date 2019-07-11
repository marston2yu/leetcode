#include "DistinctSubsequences.h"

int numDistinct(string s, string t) {
  int m = s.length();
  int n = t.length();
  if (m < n) return 0;

  vector<vector<int>> ds(m, vector<int>(n, 0));
  ds[0][0] = (int) (s[0]==t[0]);
  for (int i = 1; i < m; ++i) {
    ds[i][0] = ds[i - 1][0] + (s[i]==t[0] ? 1 : 0);
    for (int j = 1; j < n; ++j) {
      if (s[i]==t[j]) {
        ds[i][j] = ds[i - 1][j - 1] + ds[i - 1][j];
      } else {
        ds[i][j] = ds[i - 1][j];
      }
    }

  }
  return ds[m - 1][n - 1];
}