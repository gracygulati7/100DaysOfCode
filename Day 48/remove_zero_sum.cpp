//! leetcode question 1171. Remove Zero Sum Consecutive Nodes from Linked List (PROBLEM OF THE DAY 12-3-2024)

//? link: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/?envType=daily-question&envId=2024-03-12

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *curr=head,*prev=NULL,*ans=head; 
        while(head!=NULL){
            int sum=0;
            while(curr!=NULL){
                sum+=curr->val;
                curr=curr->next;
                if(sum==0){
                    if(ans==head){
                        ans=curr;
                    }
                    if(prev!=NULL){
                        prev->next=curr;
                    }
                    head=curr;
                    curr=head;
                }
            }
            if(head!=NULL){
                prev=head;
                head=head->next;
                curr=head;
            }
        }
        return ans;
    }
};


//* LOGIC:
/*
prev, ans, and curr are three pointers used to traverse and manipulate the linked list.
The outer while (head) loop iterates through each node of the linked list.
Inside the outer loop, there is an inner while (curr) loop that calculates the sum of 
the elements from the current node (curr) until the end of the list.
If the sum becomes zero during this inner loop, it means there is a sequence of consecutive nodes whose values sum up to zero.
In that case, the code updates the pointers:
If ans is pointing to the head, it is updated to curr, effectively moving the head to the next non-zero sum node.
If prev is not null, it means there was a previous non-zero sum sequence, 
so it adjusts the next pointer of the previous non-zero sum sequence to skip the current zero-sum sequence.
The head pointer is updated to curr, effectively skipping the zero-sum sequence.
curr is reset to the new head position for the next iteration.
After the inner loop completes, prev is updated to the current head.
The head pointer is then moved to the next node.
The curr pointer is reset to head to start the inner loop for the next sequence.
The process continues until the end of the list.
The function returns the updated ans, which points to the head of the modified linked list without zero-sum sequences.
*/
