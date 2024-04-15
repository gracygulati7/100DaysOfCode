//! leetcode question 230. Kth Smallest Element in a BST

//? link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/?envType=study-plan-v2&envId=top-interview-150

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
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return 0;
        vector<int> arr;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front!=NULL){
                arr.push_back(front->val);
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
            else{
                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }
        sort(arr.begin(),arr.end());
        int n=arr.size();
        return arr[k-1];
    }
};
int main(){
    Solution s;
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(1);
    root->right=new TreeNode(4);
    root->left->left=new TreeNode(0);
    root->left->right=new TreeNode(2);
    root->right->left=new TreeNode(5);
    root->right->right=new TreeNode(6);
    cout<<s.kthSmallest(root,2)<<endl;
    return 0;
}