//
// Created by Marston Yu on 2019-02-08.
//

#include "Trie.h"
void Trie::insert(std::string word) {
  // searching from root
  Trie *curr = this;
  for (char c : word) {
    // create a new node if path doesn't exist.
    if (curr->children[c - 'a']==nullptr) {
      curr->childNumber += 1;
      curr->children[c - 'a'] = new Trie();
    }

    // got to next node
    curr = curr->children[c - 'a'];
  }
  curr->isLeaf = true;
}

bool Trie::contain(std::string word) {
  if (this->childNumber==0) return false;
  Trie *curr = this;
  for (char c : word) {
    // search ending with false when char isn't in a trie.
    curr = curr->children[c - 'a'];
    if (curr==nullptr) return false;
  }
  // all chars in the word is found in the trie
  // but only when last char is a leaf, the word is contained in the trie
  // or else the word is only a prefix.
  return curr->isLeaf;
}

bool Trie::startWith(std::string word) {
  if (this->childNumber==0) return false;
  if (word.empty()) return true; // any string starts with an empty string.
  Trie *curr = this;
  for (char c : word) {
    // search ending with false when char isn't in a trie.
    curr = curr->children[c - 'a'];
    if (curr==nullptr) return false;
  }
  // all chars in the word is found in the trie
  return true;
}

std::string Trie::longestPrefix(std::string word) {
  if (this->childNumber==0) return "";
  Trie *curr = this;
  for (int i = 0; i < word.length(); i++) {
    // LCP subject to:
    // 1. it is prefix of query string q
    // 2. each node along the path must contain only one child element.
    //    Otherwise the found path will not be a common prefix among all strings.
    // 3. the path doesn't comprise of nodes which are marked as end of key.
    //    Otherwise the path couldn't be a prefix a of key which is shorter than itself.
    if (curr->startWith(word.substr(i, 1)) && curr->childNumber==1 && !curr->isLeaf) {
      curr = curr->children[word[i] - 'a'];
      continue;
    }
    return word.substr(0, i);
  }
  return word;
}
