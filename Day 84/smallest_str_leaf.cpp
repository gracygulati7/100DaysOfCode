//! leetcode question 988. Smallest String Starting From Leaf (PROBLEM OF THE DAY 17-4-2024)

//? link: https://leetcode.com/problems/smallest-string-starting-from-leaf/description/?envType=daily-question&envId=2024-04-17

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
    string ans="~";  // string ans is declared and initialized with the character "~". 
    // This string will store the lexicographically smallest string found during the traversal of the binary tree.

    void helper(TreeNode *root, string res){
        // It checks if the current node root is a leaf node (i.e., both root->left and root->right are NULL).
        if(root->left==NULL && root->right==NULL){ 

            res.push_back(root->val+'a'); // If it is a leaf node, the character corresponding to the node's value 
            // (converted to a letter from 'a' to 'z') is appended to the res string

            reverse(res.begin(),res.end()); // This is done to reverse the path from the leaf to the root, 
            // as the lexicographically smallest string starts from a leaf and ends at the root.  

            ans=min(ans,res); // Finally, the lexicographically smallest of the current res and ans strings is updated using ans=min(ans,res).
        }
        if(root->left!=NULL){ // This part checks if the current node root has a left child
        
            res.push_back(root->val+'a'); // If it has a left child, the character corresponding to the node's value 
            // (converted to a letter from 'a' to 'z') is appended to the res string using res.push_back(root->val+'a').

            helper(root->left,res); // The helper function is then recursively called for the left child node with the updated res string.

            res.pop_back(); // After the recursive call, the last character is removed from res using res.pop_back() to backtrack.
        }

        // same goes for the right child if root node has a right child
        if(root->right!=NULL){
            res.push_back(root->val+'a');
            helper(root->right,res);
            res.pop_back();
        }
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        string res=""; // res is a string that represents the current path from the root to the node being processed
        helper(root,res);
        return ans; // Finally, it returns the ans string, which contains the lexicographically smallest string found during the traversal.
    }
};
int main(){
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->left->left=new TreeNode(15);
    root->left->right=new TreeNode(7);
    root->right->left=new TreeNode(1);
    root->right->right=new TreeNode(5);
    Solution obj;
    cout<<obj.smallestFromLeaf(root)<<endl;
    cout<<obj.ans<<endl;
    return 0;
}