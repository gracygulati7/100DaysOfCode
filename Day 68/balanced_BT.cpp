//! leetcode question 110. Balanced Binary Tree

//? link: https://leetcode.com/problems/balanced-binary-tree/description/

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
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true; // If the tree is empty, we can say it’s balanced

        if(height(root)==-1) return false; // Height Function will return -1, when it’s an unbalanced tree

        return true;
    }

    // Create a function to return the “height” of a current subtree using recursion
    int height(TreeNode* root){
        if(root==NULL) return 0; // Base case

        int left=height(root->left); // Height of left subtree
        int right=height(root->right); // Height of right subtree

        // In case left subtree or right subtree is unbalanced, return -1
        if(left==-1 || right==-1) return -1;

        // If their heights differ by more than ‘1’, return -1
        if(abs(left-right)>1) return -1;
        
        // Otherwise, return the height of this subtree as max(left,right) + 1
        return max(left,right)+1;
    }
};
int main(){
    Solution s;
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->left->left=new TreeNode(15);
    root->left->right=new TreeNode(7);
    root->right->left=new TreeNode(18);
    root->right->right=new TreeNode(22);
    cout<<s.isBalanced(root)<<endl;
    return 0;
}