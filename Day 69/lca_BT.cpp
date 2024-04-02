//! leetcode question 236. Lowest Common Ancestor of a Binary Tree

//? link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // If the root node is NULL, it means the tree is empty, so it returns NULL, indicating that there's no common ancestor
        if(root==NULL) return NULL;

        // If the current node root is either p or q, it means that one of the nodes being searched for is found at the current root. 
        // Hence, it returns root.
        if(root==p || root==q) return root;

        // Recursively, it calls the lowestCommonAncestor function on the left and right subtrees. It stores the results in left and right.
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        // If both left and right are not NULL, it means that p and q are found in different subtrees of the current root. 
        // Hence, the current root is the lowest common ancestor, so it returns root.
        if(left!=NULL && right!=NULL) return root;

        // If only one of left or right is NULL, it means both p and q are in the same subtree. 
        // So, it returns the non-NULL subtree as the common ancestor.
        if(left==NULL) return right;
        return left;
    }
};
int main(){
    Solution s;
    TreeNode* root=new TreeNode(6);
    root->left=new TreeNode(2);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(0);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(7);
    root->right->right=new TreeNode(9);
    TreeNode* p=new TreeNode(2);
    TreeNode* q=new TreeNode(7);
    cout<<s.lowestCommonAncestor(root,p,q)->val<<endl;
    return 0;
}