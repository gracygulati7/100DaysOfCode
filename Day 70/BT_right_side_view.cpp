//! leetcode question 199. Binary Tree Right Side View

//? link: https://leetcode.com/problems/binary-tree-right-side-view/description/

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
/*
DFS:
1. Dfs traversal is done in a preorder manner.
*/
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        if (root == NULL)
        {
            return result;
        }
        int level = 0;
        dfs(root, result, level);
        return result;
    }

    void dfs(TreeNode *root, vector<int> &result, int level)
    {
        if (root == NULL)
        {
            return;
        }

        // level == result.size() means that the current node is the rightmost node at the current level so we add it to the result vector.
        if (level == result.size())
        {
            result.push_back(root->val);
        }

        // level+1 because we are going to the next level from left and right child of the current node.
        dfs(root->right, result, level + 1); // Traverse the right subtree first coz of right side view
        dfs(root->left, result, level + 1); // then Traverse the left subtree
    }
};
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Solution obj;
    vector<int> result = obj.rightSideView(root);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}