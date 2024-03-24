//! GEEKSFORGEEKS Question Count nodes of linked list

//? link: https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; 
class Solution
{
    public:
    int getCount(struct Node* head){
        if(head==NULL) return 0;
        Node* temp=head; int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
};

int main(){
    struct Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    Solution ob;
    cout<<ob.getCount(head);
    return 0;
}