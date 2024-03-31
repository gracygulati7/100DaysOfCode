//! leetcode question 112. Path Sum

//? link: https://leetcode.com/problems/path-sum/description/

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        // if there are no right and left nodes in tree then 
        // return true if targetsum=root->val else returns false
        if(root->left==NULL && root->right==NULL){ 
            return targetSum==root->val;
        }
        // this checks until target-root becomes 0 means targetsum is available by sum of root with either left or right nodes
        bool leftsum=hasPathSum(root->left,targetSum-root->val); 
        bool rightsum=hasPathSum(root->right,targetSum-root->val);
        return leftsum || rightsum;
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
    cout<<s.hasPathSum(root,22)<<endl;
    cout<<s.hasPathSum(root,8)<<endl;
    cout<<s.hasPathSum(root,11)<<endl;
    return 0;
}