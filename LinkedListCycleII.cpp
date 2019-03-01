//
// Created by marston on 2019/3/1.
//

#include "LinkedListCycleII.h"

ListNode *floydAlgorithm(ListNode *head) {
  if (!head) return NULL; // empty list.
  // If there is a cycle, then any index i in the loop(i >= u, u is the start of the cycle)
  // satisfies that x[i] == x[i+k*m], in which m is the length of the cycle.
  // Suppose x[v] = x[2*v], then v == c*m. And x[u] = x[u + v].
  // So if we increase two node pointer from head with speed 1 and 2 until they meet, then node pointer
  // must point to x[v]. Then we increase one node from x[v] and another from head synchronously until they meet.
  // The meet point is u.

  ListNode *a = head;
  ListNode *b = head;
  do {
    if (a == NULL || b == NULL || b->next == NULL) return NULL;
    a = a->next;
    b = b->next->next;
  } while (a != b);
  a = head;
  while (a != b) {
    a = a->next;
    b = b->next;
  }
  return a;
}