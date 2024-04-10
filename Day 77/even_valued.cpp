//! leetcode question 1315. Sum of Nodes with Even-Valued Grandparent

//? link: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/description/

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
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        if (root == NULL)
            return 0;

        // Check if the current node is even.
        if (root->val % 2 == 0) {
            if (root->left != NULL) {

                // Check if it has a left child and if the left child has a left and right child.
                if (root->left->left != NULL) {
                    sum += root->left->left->val;
                }
                if (root->left->right != NULL) {
                    sum += root->left->right->val;
                }
            }

            //  Check if it has a right child and if the right child has a left and right child.
            if (root->right != NULL) {
                if (root->right->left != NULL) {
                    sum += root->right->left->val;
                }
                if (root->right->right != NULL) {
                    sum += root->right->right->val;
                }
            }
        }

        // Recursive function on left and right children. Add the sum of the left and right subtrees.
        sum += sumEvenGrandparent(root->left);
        sum += sumEvenGrandparent(root->right);
        return sum;
    }
};
int main(){
    Solution s;
    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(3);
    cout << s.sumEvenGrandparent(root) << endl;
    return 0;
}