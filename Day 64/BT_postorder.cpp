//! leetcode question 145. Binary Tree Postorder Traversal

//? link: https://leetcode.com/problems/binary-tree-postorder-traversal/description/

//* POSTORDER- LEFT->RIGHT->ROOT

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        vector<int> left=postorderTraversal(root->left);
        res.insert(res.end(),left.begin(),left.end());
        vector<int> right=postorderTraversal(root->right);
        res.insert(res.end(),right.begin(),right.end());
        res.push_back(root->val);
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
    vector<int> res=s.postorderTraversal(root);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}