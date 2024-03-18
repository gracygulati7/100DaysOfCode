//! leetcode question 2095. Delete the Middle Node of a Linked List

//? link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

#include<iostream>
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
    ListNode* deleteMiddle(ListNode* head) {
        //  If head->next is NULL, it means there's only one node in the list, so the function returns NULL, 
        // indicating that there's nothing to delete.
        if(head->next==NULL){
            return NULL;
        }
        // slow is initially set to head, representing the slow pointer that moves one step at a time.
        // fast is initially set to head->next->next, representing the fast pointer that moves two steps at a time.
        ListNode* slow=head, *fast=head->next->next;
        while(fast!=NULL && fast->next!=NULL){ 
        // (fast->next is NULL). This ensures that slow reaches the middle node when fast reaches the end of the list.
            fast=fast->next->next;
            slow=slow->next;
        }
        // Once the loop exits, slow points to the node just before the middle node. To delete the middle node, 
        // the function updates the next pointer of slow to skip over the middle node (slow->next = slow->next->next). 
        // This effectively removes the middle node from the list.
        slow->next=slow->next->next;
        return head;
    }
};

int main(){
    Solution s;
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    head=s.deleteMiddle(head);
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}