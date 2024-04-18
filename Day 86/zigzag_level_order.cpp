//! leetcode question 103. Binary Tree Zigzag Level Order Traversal

//? link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<vector<int>> zigzagcountOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        while (!q.empty()) {
            int n = q.size();
            vector<int> level; // level vector to store the elements of the current level
            for (int i = 0; i < n; ++i) {
                TreeNode* front = q.front();
                q.pop();
                level.push_back(front->val); // Push the value of the current node into level
                if (front->left != NULL) {
                    q.push(front->left);
                }
                if (front->right != NULL) {
                    q.push(front->right);
                }
            }
            // If the count is even, reverse the level vector so that the elements
            // will be from right to left
            if (count % 2 == 0) {
                reverse(level.begin(), level.end());
            }
            res.push_back(level); // Push the elements of the current level into the result vector
            count++; // Increment the count for next level
        }
        return res; // Return the result vector
    }
};
int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<vector<int>> res = s.zigzagcountOrder(root);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}