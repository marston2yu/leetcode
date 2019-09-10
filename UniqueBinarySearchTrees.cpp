#include "UniqueBinarySearchTrees.h"

int numTrees(int n) {
  if (n <= 2) return n;
  vector<int> a(n + 1);
  a[0] = 1;
  a[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      a[i] += a[j] * a[i - j - 1];
    }
  }
  return a[n];
}