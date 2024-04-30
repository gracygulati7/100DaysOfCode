//! LeetCode Question 654. Maximum Binary Tree

//? link: https://leetcode.com/problems/maximum-binary-tree/

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty())  // Base case
            return NULL;
        int maxi = INT_MIN;
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) { // Find the maximum Index in nums
            if (nums[i] > maxi) {
                maxi = nums[i];
                idx = i;
            }
        }
        TreeNode* root = new TreeNode(maxi); // Create a new TreeNode with the maximum value
        if (idx > 0) {
             // vector<int> left(size of vector till idx, value to fill ie till idx is reached)
            vector<int> left(nums.begin(), nums.begin() + idx);
            root->left = constructMaximumBinaryTree(left);
        }
        if (idx < nums.size() - 1) {
            // vector<int> right(size of vector from idx + 1 to last, value to fill ie from idx + 1 till last of nums array)
            vector<int> right(nums.begin() + idx + 1, nums.end());
            root->right = constructMaximumBinaryTree(right);
        }
        return root;
    }
};
int main(){
    Solution s;
    vector<int> nums = {3,2,1,6,0,5};
    TreeNode* root = s.constructMaximumBinaryTree(nums);
    return 0;
}