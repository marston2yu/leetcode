#ifndef LEETCODE_LRUCACHE_H
#define LEETCODE_LRUCACHE_H
// #include <bits/stdc++.h>
#include <list>
#include <unordered_map>
using namespace std;
class LRUCache {
  typedef pair<int, int> Node;
  typedef list<Node>::iterator ref;
  int capacity;
  unordered_map<int, ref> cache;
  list<Node> access;
 public:
  LRUCache(int v) : capacity(v) {
      // access = list<Node>();
      // cache = map<int, ref>(capacity);
      // cache.reserve(capacity);
  }

  void put(int key, int value);

  int get(int key);

};

#endif //LEETCODE_LRUCACHE_H