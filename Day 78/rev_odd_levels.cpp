//! leetcode question 2415. Reverse Odd Levels of Binary Tree

//? link: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/

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
    void reverse(TreeNode* rootleft, TreeNode* rootright, int level) {
        if(rootleft==NULL && rootright==NULL) return;
        if(level%2==0) swap(rootleft->val,rootright->val);
        reverse(rootleft->left,rootright->right,level+1);
        reverse(rootleft->right,rootright->left,level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        reverse(root->left, root->right, 0);
        return root;
    }
};
int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    s.reverseOddLevels(root);
    return 0;
}