//! leetcode question 19. Remove Nth Node From End of List

//? link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=daily-question&envId=2024-03-03

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head; int count=0; // count is to know the total no. of elements in the list
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        int m=count-n+1; // now by this we can know the position of element to be deleted from the start of the list
        temp=head; // reinitialize temp to head
        ListNode* prev=NULL; // prev stores the node before temp and its initialized to null as currently temp points to head
        int curr=1; // we took this as 1 bcoz m stores position of element to be removed in 1-indexed list
        while(curr<m && temp!=NULL){ // now we will traverse temp till m-1 position
            prev=temp; // moving forward prev and temp by 1 step
            temp=temp->next;
            curr++;
        }
        // after loop now temp stores node at mth position that is to be deleted
        if(prev==NULL){ // now if element to be deleted is head
            ListNode* next=temp->next; // so we take next element to head and return it, also deleting head
            delete temp; // deleting head
            return next; // returing element after head which will be now the new head of the linkedlist after deletion of current head
        }
        else{ // if element to be deleted is any other than head
            prev->next=temp->next; 
            // prev now contains the (m+1)th element so after deletio of mth element, th prev ie (m-1) will point to (m+1)th element 
            delete temp; // deleting mth element
            return head; 
        }
    }
};
