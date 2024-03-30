//! leetcode question 617. Merge Two Binary Trees

//? link: https://leetcode.com/problems/merge-two-binary-trees/description/

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1!=NULL && root2!=NULL){
            root1->val+=root2->val;
            root1->left=mergeTrees(root1->left,root2->left);
            root1->right=mergeTrees(root1->right,root2->right);
        }
        else{
            return root1!=NULL? root1:root2;
        }
        return root1;
    }
};
int main(){
    Solution s;
    TreeNode *root1=new TreeNode(1);
    root1->left=new TreeNode(3);
    root1->right=new TreeNode(2);
    TreeNode *root2=new TreeNode(2);
    root2->left=new TreeNode(1);
    root2->right=new TreeNode(3);
    s.mergeTrees(root1,root2);
    return 0;
}