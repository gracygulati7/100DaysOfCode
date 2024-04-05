//! leetcode question 106. Construct Binary Tree from Inorder and Postorder Traversal

//? link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int idx=n-1;
        return createTree(inorder,postorder,0,n-1,idx);
    }
    TreeNode* createTree(vector<int>& inorder, vector<int>& postorder,int start,int end,int& idx){
        if(start>end){
            return NULL;
        }
        int curr=postorder[idx];
        idx--;
        TreeNode* root=new TreeNode(curr);
        if(start==end){
            return root;
        }
        int pos;
        for(int i=start;i<=end;i++){
            if(curr==inorder[i]){
                pos=i;
                break;
            }
        }
        root->right=createTree(inorder,postorder,pos+1,end,idx);
        root->left=createTree(inorder,postorder,start,pos-1,idx);
        return root;
    }
};
int main(){
    Solution s;
    vector<int> inorder={9,3,15,20,7};
    vector<int> postorder={9,15,7,20,3};
    TreeNode* root=s.buildTree(inorder,postorder);
    return 0;
}