//! leetcode question 530. Minimum Absolute Difference in BST

//? link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

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
    int getMinimumDifference(TreeNode* root) {
        int res=INT_MAX;
        TreeNode* prev=NULL;
        inorder(root,prev,res);
        return res;
    }
    void inorder(TreeNode* root, TreeNode* &prev,int &res){
        if(root==NULL) return;
        inorder(root->left,prev,res);
        if(prev!=NULL){
            res=min(res,root->val-prev->val);
        }
        prev=root;
        inorder(root->right,prev,res);
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
    cout<<s.getMinimumDifference(root)<<endl;
    return 0;
}