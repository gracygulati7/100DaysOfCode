//! leetcode question 114. Flatten Binary Tree to Linked List

//? link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/?envType=study-plan-v2&envId=top-interview-150

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root!=NULL) preorder(root);   
    }
    TreeNode* head=NULL; // Global variable to keep track of the flattened tree's head.

    void preorder(TreeNode* node){ // Perform a post-order traversal (right, left, node) to rearrange the tree.

        // Recursively flatten the right subtree first.
        if(node->right!=NULL) preorder(node->right);

        // Then flatten the left subtree recursively.
        if(node->left!=NULL) preorder(node->left);

        // After both subtrees are flattened, update the current node's pointers.
        // Set the left pointer of the current node to NULL.
        node->left=NULL;
        
        node->right=head; // Set the right pointer of the current node to the previously flattened part.
        
        head=node; // Update the head pointer to the current node, as it becomes the new head.
    }
};
int main(){
    Solution s;
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    s.flatten(root);
    while(root!=NULL){
        cout<<root->val<<" ";
        root=root->right;
    }
    cout<<endl;
    return 0;
}