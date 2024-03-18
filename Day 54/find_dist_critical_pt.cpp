//! leetcode question 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

//? link: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/

#include<iostream>
#include<vector>
#include<climits>
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head; head=head->next; int idx=1;
        vector<int> critical; // initialized to store the indices of critical points
        while (head->next!=NULL) {
            // If the current node is a critical point (i.e., it's either a local maxima or a local minima), 
            // its index value (idx) is pushed into the critical vector.
            if ((prev->val < head->val && head->val > head->next->val) ||
                (prev->val > head->val && head->val < head->next->val)) {
                critical.push_back(idx);
            }
            prev=head;
            head=head->next;
            idx++;
        }
        int n=critical.size();
        // If the number of critical points < 2, the function returns {-1, -1} to indicate that it's not possible to calculate distances.
        if(n<2){
            return {-1,-1};
        }
        int mindist=INT_MAX;
        for(int i=0;i<n-1;i++){
            mindist=min(critical[i+1]-critical[i],mindist);
        }
        return {mindist,critical.back()-critical[0]}; 
        // returns a vector containing min. distance and max. distance (the distance between the first and last critical points)
    }
};
int main() {
    // Create the linked list: 5 -> 3 -> 1 -> 2 -> 5 -> 1 -> 2
    ListNode *head = new ListNode(5);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(2);
    Solution solution;
    vector<int> result = solution.nodesBetweenCriticalPoints(head);
    cout << "minDistance: " << result[0] << ", maxDistance: " << result[1] << endl;

    // Free memory
    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}