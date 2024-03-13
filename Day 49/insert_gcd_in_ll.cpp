//! leetcode question 2807. Insert Greatest Common Divisors in Linked List

//? link: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/

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
    int findgcd(int a,int b){
        return b==0?a:findgcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *curr=head; 
        while(curr!=NULL && curr->next!=NULL){
            int gcd_val=findgcd(curr->val,curr->next->val);
            ListNode* gcd=new ListNode(gcd_val);
            gcd->next=curr->next;
            curr->next=gcd;
            curr=gcd->next;
        }
        
        return head;
    }
};