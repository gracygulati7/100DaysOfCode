//! leetcode question 92. Reverse Linked List II

//? link: https://leetcode.com/problems/reverse-linked-list-ii/description/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL) return NULL;
        ListNode* curr=head;
        vector<int> ans;
        while(curr!=NULL){
            ans.push_back(curr->val);
            curr=curr->next;
        }
        curr=head;
        for(int i=0;i<left-1;i++){ // list will remain same till left-1 values
            curr=curr->next;
        }
        for(int i=right;i>=left;i--){ // reverse the list within left and right values
            curr->val=ans[i-1]; 
            curr=curr->next;
        }
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
    head=s.reverseBetween(head, 2, 4);
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}