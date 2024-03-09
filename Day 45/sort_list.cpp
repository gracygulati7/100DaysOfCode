//! leetcode question 148. Sort List

//? link: https://leetcode.com/problems/sort-list/description/

#include <iostream>
#include <vector>
#include <algorithm>
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
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode *curr=head;
        while(curr!=NULL){
            arr.push_back(curr->val);
            curr=curr->next;
        }
        sort(arr.begin(),arr.end());
        ListNode *temp=head;
        for(int i=0;i<arr.size();i++){
            temp->val=arr[i];
            temp=temp->next;
        }
        return head;
    }
};