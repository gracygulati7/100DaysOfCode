//! GeeksForGeeks Question Arrange Consonants and Vowels [POTD 1-5-2024]

//? link: https://www.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1

#include<bits/stdc++.h>
using namespace std;
struct Node {
    char data;
    struct Node *next;
    Node(char x){
        data = x;
        next = NULL;
    }
};
class Solution {
  public:
    struct Node* arrangeCV(Node* head) {
        Node* curr=head; 
        vector<char> res; // vector to store all characters in the ll
        int count=0; // variable to count all characters in the ll
        while(curr!=NULL){
            // if current char is vowel then push it in the res vector
            if(curr->data=='a' || curr->data=='e' || curr->data=='i' || curr->data=='o' || curr->data=='u'){ 
                res.push_back(curr->data);
            }
            curr=curr->next;
            count++; // increment count variable 
        }
        curr=head; // reset curr to head for next traversal
        while(curr!=NULL){
            // if current char is consonant ie its not a vowel then push it in the res vector
            if(curr->data!='a' && curr->data!='e' && curr->data!='i' && curr->data!='o' && curr->data!='u'){
                res.push_back(curr->data);
            }
            curr=curr->next;
        }
        curr=head; // again reset curr to head
        for(int i=0;i<count;i++){ // iterate till total number of nodes in ll
            curr->data=res[i]; // store res elements in ll ie first vowels then consonants
            curr=curr->next;
        }
        return head; // return head of ll after making all these required changes.
    }
};
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list: a -> b -> c -> d -> e -> NULL
    Node* head = new Node('a');
    head->next = new Node('b');
    head->next->next = new Node('c');
    head->next->next->next = new Node('d');
    head->next->next->next->next = new Node('e');

    Solution sol;
    cout << "Original Linked List: ";
    printLinkedList(head);

    Node* newHead = sol.arrangeCV(head);

    cout << "Modified Linked List: ";
    printLinkedList(newHead);

    return 0;
}