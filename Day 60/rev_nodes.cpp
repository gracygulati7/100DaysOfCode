//! leetcode question 2074. Reverse Nodes in Even Length Groups

//? link: https://leetcode.com/problems/reverse-nodes-in-even-length-groups/description/

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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* curr=head,*temp;

        // They are used to keep track of the group number and the length of the current group being processed.
        int group=1,group_len=0; 

        vector<int> list; // It will be used to store the values of nodes in each group temporarily while processing.

        while(curr!=NULL){
            temp=curr; // It's done to retain the starting position of the current group.

            // This starts another while loop which continues until group_len becomes equal to group or curr becomes nullptr.
            while(group_len<group && curr!=NULL){

                // Within this loop, it adds the value of the current node pointed by curr to the list, 
                // advances curr to the next node, and increments group_len.
                list.push_back(curr->val);
                curr=curr->next;
                group_len++;
            }
            if(group_len%2==0){ // This condition checks if the length of the current group is even.
            
            // If the length of the group is even, it iterates through the list in reverse order and 
            // assigns the values to the nodes starting from temp
                for(int i=list.size()-1;i>=0;i--){
                    temp->val=list[i];
                    temp=temp->next;
                }
            }
            // After processing the current group, it resets group_len to 0, increments group to move to the next group, 
            // and clears the list to prepare it for the next group.
            group_len=0;
            group++;
            list.clear();
        }
        return head;   
    }
};
int main() {
    // Example linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    Solution solution;
    ListNode* reversedHead = solution.reverseEvenLengthGroups(head);

    // Print the reversed linked list
    ListNode* temp = reversedHead;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Clean up: Delete the linked list to avoid memory leaks
    while (reversedHead != nullptr) {
        ListNode* nextNode = reversedHead->next;
        delete reversedHead;
        reversedHead = nextNode;
    }
    return 0;
}

