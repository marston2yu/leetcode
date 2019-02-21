//
// Created by Marston Yu on 2019-02-20.
//

#include "LongestPalindromicSubstring.h"
#include <vector>

string dynamicProgrammingSolution(string s) {
  if (s.length() <= 2) return s; // easy case
  // dynamic programming solution.
  // First, search for palindrome with length one and two, then search for longer palindrome based on shorter one.
  // If a substring is a palindrome with length l, then the palindrome with length l+2 must contain the smaller one.
  // So we need only to check the leftmost and rightmost characters.
  // Store the leftmost character index of a palindrome in the table.
  vector<vector<int>> table;
  // palindrome with length 1.
  vector<int> vec;
  for (int i = 0; i < s.length(); i++) {
    vec.push_back(i);
  }
  table.push_back(vec);
  // palindrome with length 2.
  vec.clear();
  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i]==s[i + 1]) {
      vec.push_back(i);
    }
  }
  table.push_back(vec);
  // search for palindrome length >= 3.
  for (int j = 2; j < s.length(); j += 1) {
    vec.clear();
    for (int last_left:table[j - 2]) {
      // no left char.
      if (last_left==0) {
        continue;
      }
      int left = last_left - 1;
      int right = left + j;
      if (right < s.length() && s[left]==s[right]) {
        vec.push_back(left);
      }
    }
    table.push_back(vec);
  }
  // search result from table. The first vector that is not empty contains a answer.
  int max_length;
  for (int i = table.size() - 1; i >= 0; i--) {
    if (!table[i].empty()) {
      max_length = i + 1;
      break;
    }
  }
  int max_left = table[max_length - 1][0];
  return s.substr(max_left, max_length);
}