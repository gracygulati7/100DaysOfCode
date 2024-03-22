//! leetcode question 24. Swap Nodes in Pairs

//? link: https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {

        // if head is NULL OR just having a single node, then no need to change anything 
        if(head==NULL || head->next==NULL) return head;

        ListNode* temp=head->next; // store second node of ll which will be the head of new ll in temp 

        head->next=swapPairs(head->next->next); // head->next that points to 2nd node should now point to 3rd node in ll 
        // coz head node will be 2nd node in new ll (recursion handles case after swapping of 1st two nodes)

        temp->next=head; // temp (storing 2nd node), its next (that originally points to 3rd node) should point to 1st node which is head node 
        
        return temp; // then returning temp which is 2nd node and now the head of returned ll after swapping.
    }
};
int main(){
    Solution s;
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head=s.swapPairs(head);
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}


//* For more information refer to swap_nodes.md file