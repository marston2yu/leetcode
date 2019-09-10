#include "UniqueBinarySearchTreesII.h"

vector<TreeNode *> helper(int start, int end) {
  if (start > end) return {nullptr};
  vector<TreeNode *> v;
  for (int root = start; root <= end; root++) {
    vector<TreeNode *> left = helper(start, root - 1);
    vector<TreeNode *> right = helper(root + 1, end);
    for (auto lt:left) {
      for (auto rt:right) {
        auto *t = new TreeNode(root);
        t->left = lt;
        t->right = rt;
        v.push_back(t);
      }
    }
  }
  return v;
}

vector<TreeNode *> generateTrees(int n) {
  if (n <= 0) return {};
  return helper(1, n);
}

