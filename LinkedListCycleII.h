//
// Created by marston on 2019/3/1.
//

#ifndef LEETCODE_LINKEDLISTCYCLEII_H
#define LEETCODE_LINKEDLISTCYCLEII_H

#include <cstddef>
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *floydAlgorithm(ListNode *head);

ListNode *brentAlgorithm(ListNode *head);
#endif //LEETCODE_LINKEDLISTCYCLEII_H
