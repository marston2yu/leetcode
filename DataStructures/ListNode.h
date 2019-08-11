/**
 * This file contains `ListNode` class (linked list) that conform with leetcode definition as well as some useful method.
 * For example, method convert vector to list and vice versa are helpful when comparing two lists.
 */
#ifndef LEETCODE_LISTNODE_H
#define LEETCODE_LISTNODE_H

#include <vector>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Create a linked list from vector.
 * @param v Integer vector. \warning vector can not be empty.
 * @return Head of a linked list.
 */
ListNode *vectorToList(vector<int> &v);

/**
 * Create a vector from linked list.
 * @param head Head of a linked list.
 * @return Vector of integers.
 */
vector<int> listToVector(ListNode *head);

#endif //LEETCODE_LISTNODE_H
