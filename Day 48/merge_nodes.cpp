//! leetcode question 2181. Merge Nodes in Between Zeros

//? link: https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr=head->next,*prev=head; int sum=0;
        while(curr!=NULL){
            sum+=curr->val;
            if(curr->val==0){
                prev->val=sum;
                sum=0;
                if(curr->next!=NULL){
                    prev->next=curr->next;
                    prev=prev->next;
                }
                if(curr->next==NULL){
                    prev->next=NULL;
                    break;
                }
            }
            curr=curr->next;
        }
        return head;
    }
};