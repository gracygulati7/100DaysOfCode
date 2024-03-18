//! leetcode question 1019. Next Greater Node In Linked List

//? link: https://leetcode.com/problems/next-greater-node-in-linked-list/description/

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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* curr=head;
        vector<int> res;
        while(curr!=NULL){
            res.push_back(curr->val);
            curr=curr->next;
        }
        int n=res.size();
        vector<int> answer(n,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(res[j]>res[i]){
                    answer[i]=res[j];
                    break;
                }
            }
        }
        return answer;
    }
};
int main(){
    ListNode *head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(3);
    Solution solution;
    vector<int> result = solution.nextLargerNodes(head);
    cout << "Next greater nodes: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    // Freeing memory
    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}