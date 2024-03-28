//! leetcode question 105. Construct Binary Tree from Preorder and Inorder Traversal

//? link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
    int search(vector<int>& inorder, int start,int end,int curr){
        for(int i=start;i<=end;i++){
            if(inorder[i]==curr){
                return i;
            }
        }
        return -1;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        return createTree(preorder,inorder,0,inorder.size()-1,idx);
    }
    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder,int start,int end,int& idx) {
        if(start>end) return NULL;
        // preorder mein index position pe jo element hai usse curr mein store krdia coz its our root element
        int curr=preorder[idx];
        idx++;
        TreeNode* node=new TreeNode(curr);
        if(start==end) return node; // ek hi element hai so usse return krdia
        int pos=search(inorder,start,end,curr);
        node->left=createTree(preorder,inorder,start,pos-1,idx); // build left subtree
        node->right=createTree(preorder,inorder,pos+1,end,idx); // build right subtree
        return node;
    }
};

void printInorder(TreeNode* node) {
    if (node == nullptr) return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

int main(){
    vector<int> inorder={3,9,20,15,7};
    vector<int> preorder={9,3,15,20,7};
    Solution solution;
    TreeNode* root = solution.buildTree(preorder, inorder);
    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;
    return 0;
}