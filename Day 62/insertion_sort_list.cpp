//! leetcode question 147. Insertion Sort List

//? link: https://leetcode.com/problems/insertion-sort-list/

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode(0); // Create a dummy node to serve as the starting point of the sorted list
        dummy->next=head; // Connect dummy node to the original head of the list
        ListNode* prev=dummy, *curr=head;
        while(curr!=NULL){
             // Check if the current node has a next node and its value is greater than the next node's value
            if(curr->next!=NULL && curr->val>curr->next->val){
                // Find the correct position to insert the current node in the sorted portion of the list
                while(prev->next!=NULL && curr->next->val>prev->next->val){
                    prev=prev->next;
                }
                // Perform the insertion by rearranging the pointers
                ListNode* temp=prev->next;
                prev->next=curr->next;
                curr->next=curr->next->next;
                prev->next->next=temp;
                prev=dummy; // Reset prev to the beginning of the list
            }
            else{ // Move to the next node if the current node is already in the correct position
                curr=curr->next;
            }
        }
        return dummy->next; // Return the head of the sorted list, which is the next node of the dummy node
    }
};
int main(){
    Solution s;
    ListNode* head=new ListNode(-1);
    head->next=new ListNode(5);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(0);
    head=s.insertionSortList(head);
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}

//* LOGIC:
/*

Insertion Logic: Inside the loop, it checks if the current node (curr) needs to be inserted into the sorted portion of the list. 
If so, it finds the correct position (prev) to insert the node using another inner loop.

Node Insertion: After finding the correct position, it rearranges the pointers to insert 
the current node (curr) into the sorted portion of the list.

Pointer Update: After insertion, curr pointer moves to the next node, and 
prev pointer is reset to the beginning of the list (dummy node) for the next iteration.

*/