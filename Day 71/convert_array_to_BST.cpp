//! leetcode question 108. Convert Sorted Array to Binary Search Tree

//? link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return NULL;
        int mid=n/2;

        vector<int> left{}; vector<int> right{}; // {} this is to initialize empty vectors
        // we initialize empty vectors because if not then vector may contain some garbage values 
        // or not enough memory for allocation of more elements in it.

        for(int i=0;i<n;i++){
            if(i<mid){
                left.push_back(nums[i]);
            }
            else if(i>mid){
                right.push_back(nums[i]);
            }
        }
        // we make mid as root of tree because its height balanaced tree and for simplicity just imagine in 3d making array as tree
        TreeNode* root=new TreeNode(nums[mid]);
        
        root->left=sortedArrayToBST(left);
        root->right=sortedArrayToBST(right);
        return root;
    }
};
int main(){
    Solution s;
    vector<int> nums={-10,-3,0,5,9};
    TreeNode* root=s.sortedArrayToBST(nums);
    return 0;
}