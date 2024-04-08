//! leetcode question 2583. Kth Largest Sum in a Binary Tree

//? link: https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (root == NULL) return -1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<long long> levelsums; // levelSums will store the sum of each level of the tree
        long long sum = 0;
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front != NULL) {
                sum += front->val;
                if (front->left != NULL) {
                    q.push(front->left);
                }
                if (front->right != NULL) {
                    q.push(front->right);
                }
            } else { // If the last level has been traversed completely, push the sum of the lastlevel to levelsums
                levelsums.push_back(sum);
                sum = 0; // reset sum to 0 for calculation of sum of nodes of next level
                
                if (!q.empty()) { // If the current level has been traversed completely, push a nullptr to mark the end of the level
                    q.push(NULL);
                }
            }
        }
        sort(levelsums.begin(), levelsums.end());
        int n = levelsums.size();
        if (k > n) // If k is greater than the number of levels, return -1
            return -1;
        return levelsums[n - k];
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
    cout << s.kthLargestLevelSum(root, 3) << endl;
    cout << s.kthLargestLevelSum(root, 4) << endl;
    return 0;
}