//! GeeksForGeeks Question Remove every kth node [POTD 29-04-2024]

//? link: https://www.geeksforgeeks.org/problems/remove-every-kth-node/1

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
class Solution {
public:
    Node* deleteK(Node *head, int K) {
        // Initialize a count variable to keep track of the position of the current node
        int count = 1;

        // Initialize pointers to traverse the list
        Node* curr = head; // Pointer to the current node
        Node* prev = nullptr; // Pointer to the previous node

        // Traverse the list until the end is reached
        while (curr != nullptr) {
            // Check if the current node is a kth node
            if (count % K == 0) {
                // If it is a kth node, remove it from the list
                if (prev == nullptr) {
                    // If the previous node is nullptr, it means we are deleting the head
                    head = curr->next; // Update the head to the next node
                } else {
                    // If the previous node is not nullptr, update its next pointer to skip the current node
                    prev->next = curr->next;
                }
                // Delete the current node
                Node* temp = curr; // Temporary pointer to hold the current node to be deleted
                curr = curr->next; // Move to the next node before deletion
                delete temp; // Delete the current node
            }
            else {
                // If the current node is not a kth node, simply move to the next node
                prev = curr; // Update the prev pointer
                curr = curr->next; // Move to the next node
            }
            // Increment the count to move to the next position
            count++;
        }

        // Return the head of the modified linked list
        return head;
    }
};
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    Solution obj;
    head = obj.deleteK(head,3);
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return 0;
}