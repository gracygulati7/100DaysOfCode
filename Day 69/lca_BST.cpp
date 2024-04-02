//! leetcode question 235. Lowest Common Ancestor of a Binary Search Tree

//? link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }

        // Property1 of BST: The left subtree of a node contains only nodes with keys
        // less than the node's key.
        if (root->val > p->val && root->val > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }

        // Property2 of BST: The right subtree of a node contains only nodes with keys
        // greater than the node's key.
        if (root->val < p->val && root->val < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        // If the above conditions are not met then the root is the lowest common
        // ancestor because the root is the node that is common to both the nodes p
        // and q.
        return root;
    }
};
int main()
{
    Solution s;
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    TreeNode *p = new TreeNode(2);
    TreeNode *q = new TreeNode(7);
    cout << s.lowestCommonAncestor(root, p, q)->val << endl;
    return 0;
}