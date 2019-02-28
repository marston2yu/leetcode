//
// Created by marston on 2019/2/27.
//

#include "QueueReconstructionbyHeight.h"

vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people) {
  // sort by height first then position.
  sort(people.begin(), people.end(), [](pair<int, int> a, pair<int, int> b) {
      if (a.first == b.first) return a.second < b.second;
      return a.first < b.first;
  });
  vector<char> probe(people.size()); // probe vector for linear probing.
  vector<pair<int, int>> q(people.size()); // result vector.
  for (auto e: people) {
    int shortNum = 0; // the number of shorter people ahead of e.
    int limit = e.second; // searching limit for shorter people ahead of e.
    for (int i = 0; i <= limit; i++) {
      // For a pair e=(h, k), e's real position == k + the number of shorter people ahead of e.
      // In searching range [0, limit], increase shortNum when one people is ahead of e and its height smaller than e.
      // BTW, We need update limit for searching shorter people when e's real position is update.
      if (probe[i] && q[i].first < e.first) {
        shortNum++;
        limit = e.second + shortNum;
      }
    }
    int pos = e.second + shortNum;
    q[pos] = e;
    probe[pos] = 1;
  }
  return q;
}
