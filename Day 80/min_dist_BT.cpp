//! leetcode question 783. Minimum Distance Between BST Nodes

//? link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

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
    int minDiffInBST(TreeNode* root) {
        int res=INT_MAX;

        // We need to keep track of the previous node and usko NULL isliye kiya hai
        // kyunki agar hume koi node nahi mila toh hume kuch compare nahi karna hai
        TreeNode* prev=NULL;
        inorder(root,prev,res); // We will do inorder traversal but we can also do preorder or postorder as well
        return res;
    }
    void inorder(TreeNode* root, TreeNode* &prev,int &res){
        if(root==NULL) return; // Base case
        inorder(root->left,prev,res);
        if(prev!=NULL){ // If prev is not NULL then we will compare the difference between the previous node and current node in BT
            res=min(res,root->val-prev->val);
        }
        prev=root; // prev ki value ko update kr ke hum current node ko prev mei store karayenge
        inorder(root->right,prev,res); // Now we will move to the right subtree of the current node
    }
};
int main(){
    Solution s;
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(6);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->right->left=new TreeNode(5);
    root->right->right=new TreeNode(7);
    cout<<s.minDiffInBST(root)<<endl;
    return 0;
}