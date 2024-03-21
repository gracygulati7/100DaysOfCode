//! leetcode question 23. Merge k Sorted Lists (HARD-LEVEL)

//? link: https://leetcode.com/problems/merge-k-sorted-lists/description/

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
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.empty()) return NULL; // base case for the recursion

        while(lists.size()>1){ // this line starts a while loop that continues as long as there are more than one list in the vector lists. 
        // The goal is to merge all the lists into one.

            lists.push_back(mergeTwoLists(lists[0],lists[1])); // this line merges the first two lists (lists[0] and lists[1]) using the 
            // mergeTwoLists function, and pushes the result to the end of the vector lists.

            lists.erase(lists.begin()); // After merging the first two lists, this line removes the first list from the vector lists.

            lists.erase(lists.begin()); // This line removes the second list from the vector lists. 
            // After these two lines, only the merged list remains in lists.
        }
        return lists.front(); // After merging all the lists into one, it returns a pointer to the first element of the resulting merged list.
    }
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        if(l1==NULL) return l2; // This line checks if the first list l1 is empty. If it is, it returns l2, 
        // because there's nothing to merge with an empty list.

        if(l2==NULL) return l1; // same as above if l2 is empty

        if(l1->val<=l2->val){ // This line checks if the value of the first node in l1 <= the value of the first node in l2. 
        // If it is, it means the first node of l1 should be the head of the merged list.

            l1->next=mergeTwoLists(l1->next,l2); // this line then passes the next element of first list and first element of 2nd list 
            // to check which is less than the other to be placed in the merged list

            return l1; // This line returns l1, which is the head of the merged list.
        }
        else{ // this is same as above if l2's head value is less than l1's head value

            l2->next=mergeTwoLists(l2->next,l1);
            return l2;
        }
    }
};

int main() {
    
    // 1 4 5
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    // 1 3 4
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // 2 6
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};

    Solution sol;
    ListNode* mergedList = sol.mergeKLists(lists);

    cout << "Merged List: ";
    while (mergedList != NULL) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}