//! leetcode question 226. Invert Binary Tree

//? link: https://leetcode.com/problems/invert-binary-tree/description/

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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        return root;
    }
};
int main(){
    Solution s;
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    s.invertTree(root);
    cout<<root->val<<" "<<root->left->val<<" "<<root->right->val<<endl;
    cout<<root->left->left->val<<" "<<root->left->right->val<<" "<<root->right->left->val<<" "<<root->right->right->val<<endl;
    return 0;
}