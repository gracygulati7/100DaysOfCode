//! leetcode question 237. Delete Node in a Linked List

//? link: https://leetcode.com/problems/delete-node-in-a-linked-list/description/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};