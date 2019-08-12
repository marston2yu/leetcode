
#include "ReverseLinkedList.h"

/**
 * Reverse a linked list.
 * List must end with a node with `NULL` link(next).
 * @param head Head of a linked list.
 * @return Head of the revered list.
 */
ListNode *reverse(ListNode *head) {
  if (!head->next) return head;
  ListNode *newHead = reverse(head->next);
  // After above reverse, head's next node is tail node because we construct a reversed list by moving head to tail.
  ListNode *tail = head->next;
  tail->next = head;
  head->next = nullptr;
  return newHead;
}

ListNode *reverseBetween(ListNode *head, int m, int n) {
  if (m == n) return head;  // No exchange needed.

  // Find node in position m-1, m and n.
  ListNode *mNode, *mNodePre, *nNode;
  ListNode *nodeIter = head;
  for (int i = 1; i <= n; i++) {
    if (i == m - 1) mNodePre = nodeIter;
    if (i == m) mNode = nodeIter;
    if (i == n) nNode = nodeIter;
    nodeIter = nodeIter->next;
  }

  // Store node[n+1]. Clear node[n].next to yield a complete list ending with `NULL` for recursive function.
  ListNode *tmp = nNode->next;
  nNode->next = nullptr;

  mNode = reverse(mNode);

  // Put reversed list to origin list.
  // 1. Find the tail node of the reversed part and append node[n+1] to it.
  // 2. Make preceding node point to head of the reversed list.
  ListNode *tail = mNode;
  while (tail->next) tail = tail->next;
  tail->next = tmp;

  if (m != 1) mNodePre->next = mNode;

  if (m == 1) head = nNode;  // Correct head node because it may be swapped.
  return head;
}

ListNode *reverseBetweenIterative(ListNode *head, int m, int n) {

  if (!head) return nullptr;  // Empty list.

  ListNode *prev = nullptr;
  ListNode *cur = head;
  ListNode *after = cur->next;
  ListNode *con = nullptr;  // Node before reversed part.
  ListNode *tail = nullptr;  // Tail of the reversed part.

  ListNode *nodeIter = head;
  for (int i = 1; i <= n; i++) {  // Iterate n times so that cur point to [n+1] node.
    if (i < m) {
      if (i == m - 1) {  // Find the node [m-1].
        prev = nodeIter;
        con = nodeIter;
      }
      nodeIter = nodeIter->next;  // The iterator is useful only before finding the [m] node.
      continue;
    }
    if (i == m) {  // Fine the node [m].
      cur = nodeIter;
      tail = nodeIter;
    }
    after = cur->next;
    cur->next = prev;
    prev = cur;
    cur = after;
  }

  // After iteration, prev is tail of the to-be-reversed part, i.e, head of the reversed part.
  // Cur is the node after reversed part.
  tail->next = cur;

  // When m is 1, con is nullptr.
  // In this circumstance, we do not need to set con's next, but we have to reset head.
  if (!con) {
    head = prev;
  } else {
    con->next = prev;
  }

  return head;
}