//! leetcode question 1448. Count Good Nodes in Binary Tree

//? link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/

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
    int goodNodes(TreeNode* root) {
        return bfs(root,INT_MIN);
    }
    int bfs(TreeNode* root, int maxval){
        if(root==NULL) return 0;
        int goodnodes=0;
        if(root->val>=maxval){  // If the current node value is greater than or equal to the max value then it is a good node
            goodnodes++;
            maxval=root->val; // Updating the max value to the current node value
        }
        goodnodes+=bfs(root->left,maxval);
        goodnodes+=bfs(root->right,maxval);
        return goodnodes;
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
    cout<<s.goodNodes(root)<<endl;
    return 0;
}