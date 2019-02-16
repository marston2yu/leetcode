//
// Created by Marston Yu on 2019-02-07.
//
#include <iostream>
#include "LongestPrefix.h"

string longestCommonPrefix(vector<string> &strs) {
  if (strs.empty()) return "";
  if (strs.size()==1) return strs[0];

  // find the string with minimum length
  string ms = strs[0];
  for (auto &str : strs) {
    if (ms.length() > str.length()) {
      ms = str;
    }
  }

  // vertical scanning. Increasing array index and compare chars in same position.
  for (int i = 0; i < ms.length(); i++) {

    for (auto &str : strs) {
      // When two chars not matching, string before the unmatched chars is the longest common prefix.
      if (ms[i]!=str[i]) {
        return ms.substr(0, i);
      }
    }
  }
  // if all strings are equal, return one of those.
  return ms;
}
