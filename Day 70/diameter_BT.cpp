//! leetcode question 543. Diameter of Binary Tree

//? link: https://leetcode.com/problems/diameter-of-binary-tree/description/?envType=daily-question&envId=2024-04-02

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
    int result=0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxHeight(root);
        return result;
    }
    int maxHeight(TreeNode* root){
        if(root==NULL) return 0;
        int left=maxHeight(root->left);
        int right=maxHeight(root->right);
        result=max(left+right,result);
        return max(left,right)+1;
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
    cout<<s.diameterOfBinaryTree(root)<<endl;
    return 0;
}