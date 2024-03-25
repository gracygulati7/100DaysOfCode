//! leetcode question 142. Linked List Cycle II

//? link: https://leetcode.com/problems/linked-list-cycle-ii/description/

#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head,*fast=head;

        // The first while loop finds the intersection point. It runs until either fast becomes NULL (indicating no cycle) or 
        // fast meets slow (indicating a cycle). At each iteration, slow moves one step ahead, while fast moves two steps ahead.
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }

        // If fast becomes NULL or fast->next becomes NULL (i.e., fast reaches the end of the list), there's no cycle, so it returns NULL.
        // If the loop breaks because slow and fast meet (indicating a cycle), it proceeds to find the starting point of the cycle.
        if(fast==NULL || fast->next==NULL) return NULL;

        // The second while loop finds the starting point of the cycle. It resets one of the pointers (head in this case) to the head of list 
        // and advances both pointers (head and slow) one step at a time until they meet again. The meeting point is the start of the cycle.
        while(head!=slow){
            head=head->next;
            slow=slow->next;
        }
        
        return head; // Finally, it returns the node where the cycle begins.
    }
};
ListNode* createLinkedList(int arr[], int n, int pos) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ListNode* cycleNode = nullptr;

    for (int i = 0; i < n; ++i) {
        ListNode* newNode = new ListNode(arr[i]);
        if (i == pos) cycleNode = newNode; // Keep track of the cycle node

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Create cycle if pos is valid
    if (pos >= 0 && pos < n)
        tail->next = cycleNode;

    return head;
}

int main() {
    Solution solution;

    // Test case 1
    {
        int arr[] = {3, 2, 0, -4};
        int pos = 1;
        ListNode* head = createLinkedList(arr, 4, pos);
        ListNode* cycleStart = solution.detectCycle(head);
        if (cycleStart)
            cout << "Cycle starts at node index: " << cycleStart->val << endl;
        else
            cout << "No cycle" << endl;
    }

    // Test case 2
    {
        int arr[] = {1, 2};
        int pos = 0;
        ListNode* head = createLinkedList(arr, 2, pos);
        ListNode* cycleStart = solution.detectCycle(head);
        if (cycleStart)
            cout << "Cycle starts at node index: " << cycleStart->val << endl;
        else
            cout << "No cycle" << endl;
    }

    // Test case 3
    {
        int arr[] = {1};
        int pos = -1;
        ListNode* head = createLinkedList(arr, 1, pos);
        ListNode* cycleStart = solution.detectCycle(head);
        if (cycleStart)
            cout << "Cycle starts at node index: " << cycleStart->val << endl;
        else
            cout << "No cycle" << endl;
    }
    return 0;
}


//* LOGIC:
/*
The algorithm advances slow one step at a time and fast two steps at a time. If there's no cycle, fast will reach the end of the list (NULL). 
If there's a cycle, eventually fast will equal slow, indicating the presence of a cycle.
After finding the intersection point, we need to find the node where the cycle begins. We reset one of the pointers to the head of the list 
and keep the other pointer at the intersection point. Then, we advance both pointers at the same pace (one step at a time). The point where 
these two pointers meet again is the start of the cycle.
*/