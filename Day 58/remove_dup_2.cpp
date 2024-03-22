//! leetcode question 82. Remove Duplicates from Sorted List II

//? link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head; // dummy points to head of list
        ListNode* curr=dummy; // curr element starts from dummy not from head as head can also have duplicate elements
        int val; // this will store the duplicate element

        // while curr->next(head) and curr->next->next(2nd node) are not null check if they have same values
        // if yes, then store that value in val and increment curr->next to curr->next->next that is the next unique element
        while(curr->next!=NULL && curr->next->next!=NULL){ 
            if(curr->next->val==curr->next->next->val){
                val=curr->next->val;
                while(curr->next!=NULL && curr->next->val==val){
                    curr->next=curr->next->next;
                }
            }
            else{ // if curr->next(head) and curr->next->next(2nd node) do not have same value then normally traverse the ll
                curr=curr->next;
            }
        }
        return dummy->next; // returns dummy->next ie head of ll 
        // we do not directly return head as it can be duplicated and may be removed from ll
    }
};
int main(){
    Solution s;
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(3);
    head->next->next->next->next=new ListNode(4);
    head->next->next->next->next->next=new ListNode(4);
    head->next->next->next->next->next->next=new ListNode(5);
    head=s.deleteDuplicates(head);
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}