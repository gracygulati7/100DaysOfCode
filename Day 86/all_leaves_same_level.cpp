//! geeksforgeeks question Check if all leaves are at same level

//? link: https://www.geeksforgeeks.org/problems/leaf-at-same-level/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
class Solution{
  public:
    bool check(Node *root) {
        if(root==NULL) return true;
        queue<Node*>q;
        q.push(root); q.push(NULL);
        int level=0, leaflevel=0; // level means current level and leaflevel means the level of leaf node
        while(!q.empty()){
            Node* front=q.front();
            q.pop();
            if(front!=NULL){
                // if it is a leaf node means both left and right child are NULL
                if(front->left==NULL && front->right==NULL){
                    // check if leaflevel == 0 means it is the first leaf node
                    // if leaflevel != 0 means it is not the first leaf node
                    if(leaflevel==0){
                        leaflevel=level;  // store the level of leaf node in leaflevel
                    }
                    else{
                        // if level != leaflevel means current leaf node is not at the same level as previous leaf node
                        if(level!=leaflevel) {
                            return false;
                        }
                    }
                }
                if(front->left!=NULL) {
                    q.push(front->left);
                }
                if(front->right!=NULL) {
                    q.push(front->right);
                }
            }
            else{
                if(!q.empty()){
                    q.push(NULL);
                    level++;
                }
            }
        }
        return true;  // if all leaf nodes are at the same level return true
    }
};
int main(){
    Node* root=new Node();
    root->data=1;
    root->left=new Node();
    root->left->data=2;
    root->right=new Node();
    root->right->data=3;
    root->left->left=new Node();
    root->left->left->data=4;
    root->left->right=new Node();
    root->left->right->data=5;
    root->right->left=new Node();
    root->right->left->data=6;
    root->right->right=new Node();
    root->right->right->data=7;
    cout<<Solution().check(root)<<endl;
    return 0;
}