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


ListNode *brentAlgorithm(ListNode *head) {
  // make hare increase and turtle stationary. after hare moves 2^i-1 steps, move turtle to the position of hare.
  // if there is a cycle, then finally hare will meet turtle after cycling.
  if (head == NULL) return NULL;
  ListNode *a = head; // stationary turtle
  ListNode *b = head->next; // hare
  int counter = 1; // counter for hare steps.
  int power = 1;
  while (a != b) {
    if (!b) return NULL;
    if (power == counter) {
      a = b;
      power *= 2;
      counter = 0; // if there is a cycle, counter will be the cycle length.
    }
    counter++;
    b = b->next;
  }

  // unlike the floyd's algorithm, after searching, the distance of hare to head is not k*u.
  // but because we have the length of cycle(u), it's easy to make the distance equal to u.
  a = head;
  b = head;
  for (; counter > 0; counter--) {
    b = b->next;
  }
  while (a != b) {
    a = a->next;
    b = b->next;
  }
  return a;
}