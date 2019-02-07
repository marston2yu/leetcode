//
// Created by Marston Yu on 2019-02-07.
//
#include "PrintLibrary.h"
#include <iostream>

string longestCommonPrefix(vector<string> &strs) {
  if (strs.size()==0) return "";
  if (strs.size()==1) return strs[0];

  // vertical scanning. Increasing array index and compare chars in same position.
  for (int i = 0; i < strs[0].size(); i++) {

    for (int j = 0; j < strs.size(); j++) {
      // When two chars not matching, string before the unmatched chars is the longest common prefix.
      if (strs[0][i]!=strs[j][i]) {
        return strs[0].substr(0, i);
      }
    }
  }
  // if all strings are equal, return one of those.
  return strs[0];
}
