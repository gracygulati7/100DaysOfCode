//! GeeksForGeeks question Linked List that is Sorted Alternatingly

//? link: https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int x){
	    data =x;
	    next = NULL;
	}
};
class Solution
{
    public:
    void sort(Node **head)
    {
        Node* temp=*head;
        vector<int> res;
        while(temp!=NULL){
            res.push_back(temp->data);
            temp=temp->next;
        }
        int n=res.size();
        std::sort(res.begin(),res.end());
        temp=*head;
        for(int i=0;i<n;i++){
            temp->data=res[i];
            temp=temp->next;
        }
    }
};
int main(){
    Node* head=new Node(1);
    head->next=new Node(10);
    head->next->next=new Node(2);
    head->next->next->next=new Node(9);
    head->next->next->next->next=new Node(3);
    head->next->next->next->next->next=new Node(8);
    head->next->next->next->next->next->next=new Node(4);
    head->next->next->next->next->next->next->next=new Node(7);
    head->next->next->next->next->next->next->next->next=new Node(5);
    head->next->next->next->next->next->next->next->next->next=new Node(6);
    Solution obj;
    obj.sort(&head);
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}