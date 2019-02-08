//
// Created by Marston Yu on 2019-02-08.
//

#ifndef LEETCODE_TRIE_H
#define LEETCODE_TRIE_H
#include <string>
#include <vector>
#define ALPHABET_SIZE 26
class Trie {
 private:
  bool isLeaf;
  unsigned childNumber;
  Trie *children[ALPHABET_SIZE]{}; // initialize non-static member variable with nullptr.
  bool startWith(std::string word);

 public:
  Trie() {
    isLeaf = false;
    childNumber = 0;
  };

  // constructor for an array of strings
  explicit Trie(std::vector<std::string> &strs) {
    isLeaf = false;
    childNumber = 0;
    for (const auto &str: strs) {
      insert(str);
    }

  }
  void insert(std::string word);
  bool contain(std::string word);
  std::string longestPrefix(std::string word);
};

#endif //LEETCODE_TRIE_H
