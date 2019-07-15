#include "DistinctSubsequences.h"

int numDistinct(string s, string t) {
  int m = s.length();
  int n = t.length();
  if (m < n) return 0;

  vector<unsigned> ds(n);
  ds[0] = (int) (s[0]==t[0]);
  for (int i = 1; i < m; ++i) {
    int leftUp = ds[0]; // left upper element in original 2d memo array.
    ds[0] = leftUp + (s[i]==t[0] ? 1 : 0);
    for (int j = 1; j < n; ++j) {
      int tmp = ds[j];
      if (s[i]==t[j]) {
        ds[j] = leftUp + ds[j];
      }
      leftUp = tmp;
    }

  }
  return ds[n - 1];
}