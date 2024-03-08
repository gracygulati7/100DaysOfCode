//! leetcode question 83. Remove Duplicates from Sorted List

//? link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        while(curr!=NULL){ // traversing the list
            while(curr->next!=NULL && curr->val==curr->next->val){ // while curr->next isnt null and current value = curr->next value 
                ListNode* temp=curr->next; // store duplicate value in temp
                curr->next=curr->next->next; // move curr->next to 2 steps forward in list
                delete temp; // delete duplicate value
            }
            curr=curr->next; // if current value != curr->next value then move curr pointer 1 step forward in list
        }
        return head;
    }
};