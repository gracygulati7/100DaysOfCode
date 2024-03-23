//! leetcode question 61. Rotate List

//? link: https://leetcode.com/problems/rotate-list/description/

#include<bits/stdc++.h>
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        int count=1; // number of nodes
        ListNode* newhead=head,*tail=head;
        while(tail->next!=NULL){ // get the number of nodes in the list
            tail=tail->next;
            count++;
        }
        tail->next=head; // circle the link
        if(k=k%count){
            for(int i=0;i<count-k;i++){ // the tail node is the (count-k)th node , (1st node is head)
                tail=tail->next;
            }
        }
        newhead=tail->next;
        tail->next=NULL;
        return newhead;
    }
};