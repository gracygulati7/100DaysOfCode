//! leetcode question 328. Odd Even Linked List

//? link: https://leetcode.com/problems/odd-even-linked-list/description/

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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return head;
        }
        ListNode *odd=head,*even=head->next, *evenst=head->next;
        while(odd->next!=NULL && even->next!=NULL){
            odd->next=even->next; //Connect all odds
            even->next=odd->next->next; //Connect all evens
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenst; //Place the first even node after the last odd node.
        return head;
    }
};