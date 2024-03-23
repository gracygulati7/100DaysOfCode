//! leetcode question 143. Reorder List

//? link: https://leetcode.com/problems/reorder-list/description/?envType=daily-question&envId=2024-03-23

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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return;
        }
        ListNode* curr=head;

        // Begins a while loop that continues until the second-to-last node in the list (curr->next->next) is not NULL. 
        // This loop is used to find the last node of the list.
        while(curr->next->next!=NULL){
            curr=curr->next;
        }

        // Once the loop exits, it means curr is pointing to the second-to-last node of the original list. 
        // This line makes the next node of curr point to the second node of the original list (head->next)
        curr->next->next=head->next; 

        // Changes the next pointer of the head node to point to the last node of the original list (curr->next).
        head->next=curr->next;

        // Sets the next pointer of the second-to-last node to NULL, effectively breaking the original list at that point, 
        // as the reordered list will be connected after this point.
        curr->next=NULL;
        
        // Recursively calls reorderList with the node that comes after the new head of the reordered list.
        reorderList(head->next->next);
    }
};
int main(){
    Solution s;
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    s.reorderList(head);
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}