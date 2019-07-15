#include "MergeIntervals.h"

bool compare(vector<int> &a, vector<int> &b) {
  if (a[0] == b[0]) return a[1] < b[1];
  return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>> &intervals) {
  sort(intervals.begin(), intervals.end(), compare);
  vector<vector<int>> mergedInt;
  for (int i = 0; i < intervals.size();) {
    int start = intervals[i][0];
    int end = intervals[i][1];
    while (++i < intervals.size() && end >= intervals[i][0]) {
      end = max(end, intervals[i][1]); // inclusive and part-overlapping situation.
    }
    vector<int> a{start, end};
    mergedInt.push_back(a);
  }
  return mergedInt;
}