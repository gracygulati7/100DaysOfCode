//! GeeksForGeeks question Mirror Tree

//? link: https://www.geeksforgeeks.org/problems/mirror-tree/1

#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node==NULL) return;
        Node* temp; // temp will store the left child of the node

        // Recursively call the mirror function for the left and right child of the node
        mirror(node->left); mirror(node->right);

        // Swap the left and right child of the node
        temp=node->left;
        node->left=node->right;
        node->right=temp;
    }
};
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    Solution obj;
    obj.mirror(root);
    cout<<root->data<<" "<<root->left->data<<" "<<root->right->data<<" "<<root->left->left->data<<" "<<
    root->left->right->data<<" "<<root->right->left->data<<" "<<root->right->right->data<<endl;
    return 0;
}