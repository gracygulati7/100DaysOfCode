//! leetcode question 102. Binary Tree Level Order Traversal

//? link: https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        } 
        vector<vector<int>> result;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL); // Push a NULL to mark the end of the first level
        
        while (q.size() > 1) { // Continue until the queue has only the NULL left
            vector<int> levelNodes; // levelnodes will stores the nodes of curent level

            // q.front() will be nullptr if the current level has been traversed completely 
            // Continue until the current level has been traversed completely

            while (q.front() != NULL) { // Process all nodes in the current level
                TreeNode *front = q.front();

                // remove the front node from queue as it has been visited now and push its children
                q.pop();

                // push the value of current nodes to levelnodes vector
                levelNodes.push_back(front->val);
                if (front->left != NULL) {
                    q.push(front->left);
                } 
                if (front->right != NULL) {
                    q.push(front->right);
                }
            }
            result.push_back(levelNodes); // Push the nodes of the current level to the result
            
            // after the current level has been traversed completely Remove the NULL marking the end of the current level
            q.pop(); 
            q.push(NULL); // Push a NULL to mark the end of the next level
        }
        return result;
    }
};
int main(){
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(15);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(18);
    root->right->right = new TreeNode(22);
    vector<vector<int>> result = s.levelOrder(root);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}