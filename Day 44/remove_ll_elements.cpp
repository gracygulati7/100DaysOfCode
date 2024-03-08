//! leetcode question 203. Remove Linked List Elements

//? link: https://leetcode.com/problems/remove-linked-list-elements/description/

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head; 
        while(head!=NULL && head->val==val){
            head=head->next; 
        }
        ListNode *curr=head;
        while(curr!=NULL && curr->next!=NULL){
            if(curr->next->val==val){
                curr->next=curr->next->next;
            }
            else{
                curr=curr->next;
            }
        }
        return head;
    }
};