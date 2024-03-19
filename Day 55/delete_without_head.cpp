//! GEEKSFORGEEKS Question Delete without head pointer

//? link: https://www.geeksforgeeks.org/problems/delete-without-head-pointer/1

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
    data = x;
    next = NULL;
    }
}*head;

class Solution
{
    public:
    void deleteNode(Node *del_node)
    {
       Node* temp=del_node->next;
       del_node->data=temp->data;
       del_node->next=temp->next;
       delete(temp);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        head=new Node(n);
        Node* temp=head;
        for(int i=1;i<n;i++){
            int x;
            cin>>x;
            temp->next=new Node(x);
            temp=temp->next;
        }
        int q;
        cin>>q;
        while(q--){
            int x;
            cin>>x;
            Node* temp=head;
            while(temp->data!=x){
                temp=temp->next;
            }
            Solution ob;
            ob.deleteNode(temp);
        }
    }
    return 0;
}