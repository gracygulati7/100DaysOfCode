//! leetcode question 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree

//? link: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description/

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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==NULL) return NULL;
        if(original==target) return cloned;
        TreeNode* left=getTargetCopy(original->left,cloned->left,target);
        TreeNode* right=getTargetCopy(original->right,cloned->right,target);
        return (left!=NULL)? left:right;
    }
};
int main(){
    TreeNode* original=new TreeNode(1);
    original->left = new TreeNode(2);
    original->right = new TreeNode(3);
    original->left->left = new TreeNode(4);
    original->left->right = new TreeNode(5);
    original->right->left = new TreeNode(6);
    original->right->right = new TreeNode(7);
    TreeNode* cloned=new TreeNode(1);
    cloned->left = new TreeNode(2);
    cloned->right = new TreeNode(3);
    cloned->left->left = new TreeNode(4);
    cloned->left->right = new TreeNode(5);
    cloned->right->left = new TreeNode(6);
    cloned->right->right = new TreeNode(7);
    TreeNode* target=new TreeNode(3);
    Solution s;
    cout<<s.getTargetCopy(original,cloned,target)<<endl;
    return 0;
}