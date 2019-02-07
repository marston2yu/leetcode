//
// Created by Marston Yu on 2019-02-07.
//
#include "PrintLibrary.h"
#include <iostream>

string longestCommonPrefix(vector<string> &strs) {
  if (strs.size()==0) return "";
  if (strs.size()==1) return strs[0];

  string common = "";
  string pattern = "";
  string content = "";
  for (int i = 0; i < strs.size() - 1; i++) {
    // compare the first and second string at the beginning
    // while compare next string with common prefix in future iteration.
    if(i == 0) {
      pattern = strs[i].size() < strs[i + 1].size() ? strs[i] : strs[i + 1];
      content = strs[i].size() < strs[i + 1].size() ? strs[i + 1] : strs[i];
    } else {
      pattern = common;
      content = strs[i+1];
    }
    // shrink the pattern to find the common prefix of the pattern and content strings.
    for (int j = pattern.size(); j > 0; j--) {
      if (content.substr(0, j) == pattern.substr(0, j)) {
        common = pattern.substr(0, j);
        break;
      }
      // set common to empty when pattern and content have no common prefix
      // common prefix in last iteration has been stored in pattern variable.
      common = "";
    }
    // finish searching when pattern and content have no common prefix.
    if(common == "") break;
  }
  return common;
}
