#include "ReverseNodesInKGroup.h"

ListNode *reverseKGroup(ListNode *head, int k) {
    // Corner case for empty list and group size 1.
    if (!head) return head;
    if (k==1) return head;
    ListNode *pg = NULL;  // Final node for the last group.
    ListNode *end = head;
    ListNode *start = end;
    while (true) {
        for (int i = 0; i < k - 1; i++) {
            if (!end->next) {
                return head;  // Some of nodes remain unchanged in partition.
            }
            end = end->next;
        }

        ListNode *pr = end->next; // Previous node.
        ListNode *cu = start; // Current node.
        ListNode *ne = start->next; // Next node.
        while (pr!=end) {
            cu->next = pr; // Only modify current node's `next` field in loops.
            // Update pointers.
            pr = cu;
            cu = ne;
            if (cu) { // If all node are exactly partitioned, `cu` could be NULL.
                ne = cu->next;
            }
        }
        if (pg) {
            pg->next = pr;
        } else {
            head = pr;
        }

        pg = start;
        if (!pg->next) return head; // All node are exactly partitioned.
        start = pg->next;
        end = start;
    }
}