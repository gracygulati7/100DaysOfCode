//! leetcode question 450. Delete Node in a BST

//? link: https://leetcode.com/problems/delete-node-in-a-bst/description/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;

        // BST left subtree condition
        if(key < root->val){
            root->left=deleteNode(root->left,key);
        }

        // BST right subtree condition
        else if(key > root->val){
            root->right=deleteNode(root->right,key);
        }

        // if key is neither in left subtree nor in right subtree means root=key
        else{
            // CASE 1: if root just has a single child 
            // in this case root just has right child so we store right child value in temp then delete root and return temp as the new root
            if(root->left==NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            // in this case root just has left child so we store left child value in temp then delete root and return temp as the new root
            else if(root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            // CASE 2: if root has both left and right children and they further also have their children
            // here we store either of root's left or right child in temp
            // in this case we store left child
            TreeNode* temp=root->left;

            // then we store the rightmost child of the left child in temp which further dosent have any right child
            // we can also take left child its your choice
            while(temp->right!=NULL){
                temp=temp->right;
            }

            // then we replace root's value with the value of rightmost child of the left child of root 
            root->val=temp->val;

            // and then delete that rightmost child of left child as it took the place of root because root is key so it needs to be deleted
            root->left=deleteNode(root->left,temp->val);
        }
        return root; // and then return the new root ie the rightmost child of left child of original root
    }
};
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    Solution s;
    s.deleteNode(root,3);
    cout<<root->val<<" "<<root->left->val<<" "<<root->right->val<<endl;
    return 0;
}


//* LOGIC:
/*
firstly we check where the key lies in the tree whether its in right subtree or left subtree of tree
if, key does not exist in any of the subtrees means root is the key

then we now know that root is th key so it needs to be deleted and any of its child or grandchild needs to take its place
so we firstly check whether root has single child or both left and right child

if root has single child then we store that child value in temp then delete root and return temp as new root

if root has both left and right child then we store either of root's left or right child in temp
then we traverse temp to its right or left until temp->left || temp->right is not equal to NULL meaning we reached at end of the tree

then we replace root's value with the value of temp->val ie we make that last child as the new root of the tree 
and then delete that child's original node as it took the place of root and original root is key so it needs to be deleted

and then return the new root ie the last descendant of original root.
*/