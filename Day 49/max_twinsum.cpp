//! leetcode question 2130. Maximum Twin Sum of a Linked List

//? link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/

#include <iostream>
#include <vector>
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
    int pairSum(ListNode* head) {
        vector<int> vec;
        ListNode *curr=head; int n=0; int maxsum=0;
        while(curr!=NULL){
            vec.push_back(curr->val);
            curr=curr->next; n++;
        }
        int begin=0,end=n-1;
        while(begin<end){
            maxsum=max(maxsum,vec[begin]+vec[end]);
            begin++; end--;
        }
        return maxsum;
    }
};