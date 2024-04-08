//! leetcode question 07. Binary Tree Level Order Traversal II

//? link: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

//* LOGIC: 
// code is same as simple level order traversal of tree we just reverse the order of nodes 
// to obtain the order of nodes from leaf to root ie bottom to up as required by the question

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        vector<vector<int>> result;
        q.push(root); q.push(NULL);
        while(q.size()>1){
            vector<int> node;
            while(q.front()!=NULL){
                TreeNode* front=q.front();
                q.pop();
                node.push_back(front->val);
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
            result.push_back(node);
            q.pop();
            q.push(NULL);
        }   

        // reverse is used to reverse the result vector to get the bottom-up level we are not using sort with rbegin and rend
        // because it will sort the levels in descending order and we dont need to sort the values of nodes instead we need to
        // reverse the nodes to get the desired output of order of nodes from bottom to top.
        reverse(result.begin(),result.end());
        return result;
    }
};
int main(){
    Solution s;
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->left->left=new TreeNode(15);
    root->left->right=new TreeNode(7);
    vector<vector<int>> result=s.levelOrderBottom(root);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}