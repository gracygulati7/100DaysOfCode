//! leetcode question 129. Sum Root to Leaf Numbers (PROBLEM OF THE DAY 15-4-2024)

//? link: https://leetcode.com/problems/sum-root-to-leaf-numbers/description/?envType=daily-question&envId=2024-04-15

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
    int sumNumbers(TreeNode *root){
        return bfs(root, 0);
    }
    int bfs(TreeNode *root, int sum) {
        if (root == NULL)
            return 0;
/*
       1
     /  \
    2   3

    sum = 0
    sum for root = 0*10 + 1 = 1
    sum for left = 1*10 + 2 = 12
    sum for right = 1*10 + 3 = 13
    sum = 12 + 13 = 25

*/
        // sum starts as 0, and each time we visit a node in the tree, we add its
        // value to sum after shifting sum to the left to make space for the new digit.
        // Basically, we are building the number from the root to the leaf node then
        // return the sum of all the numbers.
        sum = sum * 10 + root->val;
        if (root->right == NULL && root->left == NULL)
            return sum;
        return bfs(root->left, sum) + bfs(root->right, sum);
    }
};
int main()
{
    Solution s;
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    cout << s.sumNumbers(root) << endl;
    return 0;
}

//* LOGIC:
/*

sum = sum * 10 + root->val;

1. Multiplying sum by 10:

When a node is processed in the traversal, the sum variable is multiplied by 10. This step is essential because
it helps in constructing the correct numerical value for the path from the root to the current node.
Multiplying by 10 shifts the digits of the existing sum to the left, creating space for the new digit to be added.

2. Adding root->val:

After multiplying sum by 10, the value of the current node (root->val) is added to sum.
This addition is what incorporates the value of the current node into the number representing the path from the root to this node.

For example, suppose sum was 25 before this line, and the current node's value (root->val) is 3.
After this line executes, sum becomes 253, representing the path from the root to the current node (25 followed by 3).

*/