//! geeksforgeeks Check for Children Sum Property in a Binary Tree

//? link: https://www.geeksforgeeks.org/problems/children-sum-parent/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution{
    public:
    int isSumProperty(Node *root){
     if(root==NULL) return 1;
     if(root->left==NULL && root->right==NULL) return 1;
     int sum=0;
     if(root->left) sum+=root->left->data;
     if(root->right) sum+=root->right->data;
     return root->data==sum && isSumProperty(root->left) && isSumProperty(root->right);
    }
};