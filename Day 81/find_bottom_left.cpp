//! leetcode question 513. Find Bottom Left Tree Value

//? link: https://leetcode.com/problems/find-bottom-left-tree-value/description/

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
    int findBottomLeftValue(TreeNode *root) {
        if (root == NULL)
            return 0;
        int res = 0; // Initialize the leftmost value
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            res = q.front()->val; // Update leftmost value for each level
            for (int i = 0; i < size; i++) {
                TreeNode *front = q.front();
                q.pop();
                if (front->left != NULL)
                    q.push(front->left);
                if (front->right != NULL)
                    q.push(front->right);
            }
        }
        return res; // Return the leftmost value of the last level
    }
};
int main() {
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(15);
    root->left->right = new TreeNode(7);
    cout << s.findBottomLeftValue(root) << endl;
    return 0;
}