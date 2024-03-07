//! leetcode question 876. Middle of the Linked List (PROBLEM OF THE DAY 7-3-2024)

//? link: https://leetcode.com/problems/middle-of-the-linked-list/description/?envType=daily-question&envId=2024-03-07

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast=head,*slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};


//* LOGIC:
// Each time, slow go 1 steps while fast go 2 steps.
// when fast reaches end of list, slow will reach at middle of list