
#include "ListNode.h"

ListNode *vectorToList(vector<int> &v) {
  ListNode *head = new ListNode(v[0]); // Assume vector is not empty.
  ListNode *tail = head;
  if (v.size() <= 1) return head;
  for (unsigned int i = 1; i < v.size(); i++) {
    ListNode *item = new ListNode(v[i]);
    tail->next = item;
    tail = item;
  }
  return head;
}

vector<int> listToVector(ListNode *head) {
  // Assume list is not empty. There is no empty list unless we define empty list as `NULL`, but in
  // this way we can not clear a given list in any function body when list is a parameter.
  vector<int> v;
  while (head) {
    v.push_back(head->val);
    head = head->next;
  }
  return v;
}