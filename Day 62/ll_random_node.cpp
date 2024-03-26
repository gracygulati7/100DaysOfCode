//! leetcode question 382. Linked List Random Node

//? link: https://leetcode.com/problems/linked-list-random-node/description/

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
    map<int,ListNode*>mp; // This map is used to store the indices of the linked list nodes along with their next pointers.
    Solution(ListNode* head) {
        ListNode* temp=head; 
        int i=0; // it will be used as the index for mapping nodes to their positions in the linked list.
        while(temp!=NULL){
            // we add the current node temp to the map mp with the index i, and then increment i and move temp to the next node.
            mp[i++]=temp;
            temp=temp->next;
        }
    } 
    int getRandom() {
        int n=mp.size(); // We calculate the size of the map mp and store it in variable n.

        return mp[rand()%n]->val; // We generate a random index between 0 and n-1 using rand() % n, and then use it 
        // to access a random node from the map and return the value of the randomly selected node.
    }
};

/**
Your Solution object will be instantiated and called as such:
Solution* obj = new Solution(head);
int param_1 = obj->getRandom();
*/

int main() {
    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution* obj = new Solution(head);

    // Generating a random element from the linked list
    srand(time(NULL)); // Seed the random number generator with current time
    int randomElement = obj->getRandom();
    
    // Output the randomly selected element
    cout << "Randomly selected element from the linked list: " << randomElement << endl;

    // Freeing dynamically allocated memory
    delete obj;
    
    // Freeing memory allocated for linked list nodes
    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}

