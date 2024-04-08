//! leetcode question 965. Univalued Binary Tree

//? link: https://leetcode.com/problems/univalued-binary-tree/description/

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
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL) return true;

         // If root has left child and left child value is not equal to root value
        if(root->left!=NULL && root->left->val!=root->val){
            return false;
        }

        // If root has right child and right child value is not equal to root value
        if(root->right!=NULL && root->right->val!=root->val){
            return false;
        }

        // Recursively check for left and right child of root node
        bool left=isUnivalTree(root->left);
        bool right=isUnivalTree(root->right);

        // If both left and right are true means if all values in tree are univalued then return true
        return left && right;
    }
};
int main(){
    Solution s;
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(1);
    root->right=new TreeNode(1);
    cout<<s.isUnivalTree(root)<<endl;
    return 0;
}