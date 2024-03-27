//! leetcode question 144. Binary Tree Preorder Traversal

//? link: https://leetcode.com/problems/binary-tree-preorder-traversal/description/

//* PREORDER- ROOT->LEFT->RIGHT

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        res.push_back(root->val);
        vector<int> left=preorderTraversal(root->left);
        res.insert(res.end(),left.begin(),left.end());
        vector<int> right=preorderTraversal(root->right);
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
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    vector<int> res=s.preorderTraversal(root);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}