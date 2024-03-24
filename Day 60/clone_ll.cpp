//! GEEKSFORGEEKS Question Clone a linked list with next and random pointer

//? link: https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *arb;

    Node(int x){
        data = x;
        next = NULL;
        arb = NULL;
    }
};
class Solution{
    private:
    void insertattail(Node* &head,Node* &tail,int data){
        Node* temp=new Node(data);
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    public:
    Node *copyList(Node *head)
    {
         // STEP 1 : CREATE A CLONE LIST
        Node* clonehead=NULL, *clonetail=NULL, *temp=head;
        while(temp!=NULL){
            insertattail(clonehead,clonetail,temp->data);
            temp=temp->next;
        }
        // STEP 2 : CREATE A MAP
        unordered_map<Node*,Node*> oldtonew;
        Node* original=head, *clonenode=clonehead;
        while(original!=NULL && clonenode!=NULL){
            oldtonew[original]=clonenode;
            original=original->next;
            clonenode=clonenode->next;
        }
        original=head,clonenode=clonehead;
        while(original!=NULL){
            clonenode->arb=oldtonew[original->arb];
            original=original->next;
            clonenode=clonenode->next;
        }
        return clonehead;
    }
};
int main() {
    // original linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Set arbitrary pointers
    head->arb = head->next->next;  // 1's arb points to 3
    head->next->arb = head;         // 2's arb points to 1
    head->next->next->arb = head->next->next->next->next; // 3's arb points to 5
    head->next->next->next->arb = head->next; // 4's arb points to 2
    head->next->next->next->next->arb = head->next->next->next; // 5's arb points to 4

    Solution solution;

    // Copy the linked list
    Node* copiedHead = solution.copyList(head);

    // Print the copied linked list
    cout << "Copied Linked List:" << endl;
    Node* temp = copiedHead;
    while (temp != NULL) {
        cout << "Node " << temp->data;
        if (temp->arb != NULL)
            cout << ", Arb points to " << temp->arb->data;
        else
            cout << ", Arb points to NULL";
        cout << endl;
        temp = temp->next;
    }
    return 0;
}
