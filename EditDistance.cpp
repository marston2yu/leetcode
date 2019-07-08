#include "EditDistance.h"

int minDistance(string word1, string word2) {
  int n = word1.length();
  int m = word2.length();
  if (m == 0) return n;
  if (n == 0) return m;
  // create memoization cache.
  vector<int> prev(n + 1); // DP array for previous line.
  // calculate top-down rows.
  for (int j = 0; j <= n; ++j) {
    prev[j] = j; // target string is empty, delete all characters in source string.
  }

  for (int i = 1; i <= m; ++i) {
    int prev_upleft = prev[0];
    prev[0] = i; // source string is empty, insert all characters in target string.

    for (int j = 1; j <= n; ++j) {
      int ins = 1 + prev[j]; // insertion operation.
      int del = 1 + prev[j - 1]; // deletion operation.
      int rep;
      if (word1[j - 1] == word2[i - 1]) {
        rep = prev_upleft; // same charaters, so operation number do not accumulate.
      } else {
        rep = 1 + prev_upleft; // replacement operation.
      }
      prev_upleft = prev[j]; // current data will become upleft value in next iteration.
      prev[j] = min(ins, min(del, rep)); // choose minimum path.
    }
  }
  return prev[n];
}