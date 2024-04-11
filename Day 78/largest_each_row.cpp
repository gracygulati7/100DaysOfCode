//! leetcode question 515. Find Largest Value in Each Tree Row

//? link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>q;
        vector<int> maxi;
        int maximum=INT_MIN;
        q.push(root); q.push(NULL);
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front!=NULL){
                maximum=max(maximum,front->val);
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
            else{
                maxi.push_back(maximum);
                if(!q.empty()){
                    q.push(NULL);
                }
                maximum = INT_MIN;
            }
        }
        return maxi;
    }
};
int main(){
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(15);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(18);
    root->right->right = new TreeNode(22);
    vector<int> ans = s.largestValues(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}