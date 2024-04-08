//! leetcode question 993. Cousins in Binary Tree

//? link: https://leetcode.com/problems/cousins-in-binary-tree/description/

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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL)
            return false;
        queue<TreeNode*> q;
        
        // x_found and y_found are used to check if x and y are present in the same level or not or are they even present in tree or not
        bool x_found = false, y_found = false;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front != NULL) {
                
                 // if x and y are found then mark them as true
                if (front->val == x) {
                    x_found = true;
                }
                if (front->val == y) {
                    y_found = true;
                }
                if (front->left != NULL) {
                    q.push(front->left);
                }
                if (front->right != NULL) {
                    q.push(front->right);
                }

                 // if x and y are children of the same parent then return false
                if (front->left != NULL && front->right != NULL) {

                    // front->left->val == x means x is the left child of front and
                    // front->right->val == y means y is the right child of front
                    // so it means that they are not cousins but real siblings
                    if (front->left->val == x && front->right->val == y ||
                        front->left->val == y && front->right->val == x) {
                        return false;
                    }
                }
            } else {

                // if x and y are found in the same level with different parents then return true
                if (x_found && y_found) {
                    return true;
                }

                // if NULL is encountered at the front of queue then push NULL to mark the end of a level
                if (!q.empty()) {
                    q.push(NULL);
                }

                // reset x_found and y_found for the next level
                x_found = false;
                y_found = false;
            }
        }
        return false;
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
    cout << s.isCousins(root, 5, 6) << endl;
    cout << s.isCousins(root, 5, 7) << endl;
    cout << s.isCousins(root, 4, 5) << endl;
    cout << s.isCousins(root, 4, 6) << endl;
    return 0;
}