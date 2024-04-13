//! leetcode question 1161. Maximum Level Sum of a Binary Tree

//? link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL) return 0;
        int maxi=INT_MIN;
        int maxlevel=0; int level=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            int sum=0;
            level++;
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                sum+=front->val;
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
            if(sum>maxi){
                maxi=sum;
                maxlevel=level;
            }
        }
        return maxlevel;
    }
};
int main(){
    Solution s;
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->left->left=new TreeNode(15);
    root->left->right=new TreeNode(7);
    cout<<s.maxLevelSum(root)<<endl;
    return 0;
}