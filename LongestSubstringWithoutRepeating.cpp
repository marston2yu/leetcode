//
// Created by marston on 2019/2/20.
//

#include "LongestSubstringWithoutRepeating.h"
#include <unordered_set>
#include <unordered_map>

int sliderWindow(string s) {
  // slider window
  unordered_set<char> us;
  int ans = 0;
  for (int i = 0, j = 0; i < s.length() && j < s.length();) {
    // When s[i, j-1] has no duplication, only s[j] needs to be checked to judge whether s[i, j] has duplications.
    // Create a set containing characters in s[i, j-1] and check whether it contains s[j].
    // If s[j] is not found, increase j and update ans.
    // If s[j] is found, increase i, remove s[i] in the set and maintain j unchanged (Set j equal to i is unnecessary!)
    // because if s[i, j-1] has no duplications, s[i+1, j-1] certainly has no duplications.
    if (us.find(s[j]) == us.end()) {
      us.insert(s[j++]);
      ans = ans > (j - i) ? ans : (j - i);
    } else {
      us.erase(s[i++]);
    }
  }
  return ans;
}

int sliderWindowMap(string s) {
  // slider window optimized.
  // Incrementation of i in last implementation can be lager, more specifically, to the next letter of duplication.
  // Create a map of character and its index in the string.
  unordered_map<char, int> um;
  int ans = 0;
  for (int j = 0, i = 0; j < s.length(); j++) {
    if (um.find(s[j]) != um.end()) {
      // erase is not suitable here because erase needs to be operated multiple times.
      i = i > (um[s[j]] + 1) ? i : (um[s[j]] + 1);
    }
    // no erase needed, but map should be updated.
    um[s[j]] = j;
    // s[i, j] is a substring without duplication because we have update i before.
    ans = ans > (j - i + 1) ? ans : (j - i + 1);
  }
  return ans;
}

int sliderWindowTable(string s) {
  // using an array as a map because the keys are limited.
  int table[256];
  fill(table, table + 256, -1); // initialize table with -1 because string index can not be a negative number.
  int ans = 0;
  for (int j = 0, i = 0; j < s.length(); j++) {
    if (table[s[j]] != -1) {
      i = i > (table[s[j]] + 1) ? i : (table[s[j]] + 1);
    }
    // no erase needed, but map should be updated.
    table[s[j]] = j;
    // s[i, j] is a substring without duplication because we have update i before.
    ans = ans > (j - i + 1) ? ans : (j - i + 1);
  }
  return ans;
}