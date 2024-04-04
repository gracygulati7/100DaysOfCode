//! leetcode question 2236. Root Equals Sum of Children

//? link: https://leetcode.com/problems/root-equals-sum-of-children/

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
    bool checkTree(TreeNode* root) {
        int rootsum=root->val;
        int sum= root->left->val+root->right->val;
        return (rootsum==sum);
    }
};
int main(){
    Solution s;
    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    cout<<s.checkTree(root)<<endl;
    return 0;
}