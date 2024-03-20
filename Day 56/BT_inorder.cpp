//! leetcode question 94. Binary Tree Inorder Traversal

//? link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/

#include <bits/stdc++.h>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        vector<int> left=inorderTraversal(root->left);
        res.insert(res.end(),left.begin(),left.end());
        res.push_back(root->val);
        vector<int>right=inorderTraversal(root->right);
        res.insert(res.end(),right.begin(),right.end());
        return res;
    }
};
int main(){
    Solution s;
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    vector<int> res=s.inorderTraversal(root);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}