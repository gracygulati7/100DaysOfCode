//! leetcode question 104. Maximum Depth of Binary Tree

//? link: https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int maxDepth(TreeNode* root) {

        if(root==0) return 0; // Base case - If the subtree is empty ie root is NULL, return depth as 0

        // Initialize the depth of two subtrees
        int maxDepthLeft=maxDepth(root->left);
        int maxDepthRight=maxDepth(root->right);

        return max(maxDepthLeft,maxDepthRight)+1; // return the max depth out of the two left and right subtrees and add 1 to it
        // adding 1 is because of the root node present at the top of the tree.

    }
};

int main(){
    Solution s;
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->left->left=new TreeNode(15);
    root->left->right=new TreeNode(7);
    cout<<s.maxDepth(root)<<endl;
    return 0;
}   