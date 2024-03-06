//! leetcode question 141. Linked List Cycle (PROBLEM OF THE DAY 6-3-2024)

//? link: https://leetcode.com/problems/linked-list-cycle/description/?envType=daily-question&envId=2024-03-06

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // making two pointers fast and slow and assignning them to head
        ListNode* fast=head;
        ListNode* slow=head;
        // till fast and fast-> next not reaches NULL
		// we will increment fast by 2 step and slow by 1 step
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        // At the point if fast and slow are at same address
		// this means linked list has a cycle in it.
            if(fast==slow) return true;
        }
        // if traversal reaches to NULL this means no cycle.
        return false;
    }
};

/*
Suppose there are two people running on a track one with a speed x and another with a speed 2x (twice of first) 
now it's clear that person 2 is faster.
Now assume the track to be circular and now since peson 2 will have faster speed so it is very sure that 
person two will meet person 1 or he will overtake him.
Now the above scenario is similar to our problem statement where given linkedlist is the track and 
if the linked list would have a cycle it would be same as the circular track and the above conditon will definitely meet, 
i.e person 2 will overtake or meet person one.
person 1 is slow pointer here and moving by 1 node at a time and person 2 is fast pointer here moving with 2 nodes at a time. 
So they will meet definitely at some point if the linkedlist contains a cycle that is our fast and slow pointer reference 
will become equal or they point at same memory location.
*/