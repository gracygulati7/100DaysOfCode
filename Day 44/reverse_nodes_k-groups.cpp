//! leetcode question25. Reverse Nodes in k-Group (hard level)

//? link: https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cursor=head; // This cursor is used to check if there are at least k nodes remaining in the list for reversal.
        // Move the cursor k nodes ahead to check if there are enough nodes for reversal
        for(int i=0;i<k;i++){
            if(cursor==NULL){  // If there are fewer than k nodes, return the original head
                return head; 
            }
            cursor=cursor->next;
        }
        ListNode* prev=NULL; // track the last node of the reversed group
        ListNode *curr=head; // traverse the group
        int count=0; // keep track of the number of nodes reversed
        // Reverse first k nodes
        while(curr!=NULL && count<k){
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        // Recursively reverse the remaining nodes after the reversed group
        if(curr!=NULL){
            ListNode* new_head=reverseKGroup(curr,k);
            head->next=new_head;
        }
        return prev; // Return the head of the reversed group
    }
};