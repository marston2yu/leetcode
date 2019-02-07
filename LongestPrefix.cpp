//
// Created by Marston Yu on 2019-02-07.
//
#include "PrintLibrary.h"
#include <iostream>

string longestCommonPrefix(vector<string> &strs) {
  if (strs.size()==0) return "";
  if (strs.size()==1) return strs[0];

  // find the string with minimum length
  string ms = strs[0];
  for (int i = 0; i < strs.size(); i++) {
    if (ms.length() > strs[i].length()) {
      ms = strs[i];
    }
  }

  // vertical scanning. Increasing array index and compare chars in same position.
  for (int i = 0; i < ms.length(); i++) {

    for (int j = 0; j < strs.size(); j++) {
      // When two chars not matching, string before the unmatched chars is the longest common prefix.
      if (ms[i]!=strs[j][i]) {
        return ms.substr(0, i);
      }
    }
  }
  // if all strings are equal, return one of those.
  return ms;
}
