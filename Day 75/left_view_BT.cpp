//! GeeksForGeeeks question Left View of Binary Tree

//? link: https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void dfs(Node* root, vector<int>& res, int level,int& maxlevel){
    if(root==NULL) return;
    if(level>maxlevel){
        res.push_back(root->data);
        maxlevel=level;
    }
    dfs(root->left,res,level+1,maxlevel);
    dfs(root->right,res,level+1,maxlevel);
}
vector<int> leftView(Node *root)
{
   vector<int> res;
   if(root==NULL) return res;
   int level=0;
   int maxlevel=-1;
   dfs(root,res,level,maxlevel);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> res = leftView(root);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}


//* LOGIC:
/*
void dfs(Node* root, vector<int>& res, int level, int& maxLevel): 
This is a depth-first search (DFS) function that traverses the binary tree recursively. It takes the following parameters:

root: The current node being processed.
res: A reference to the result vector where we store the left view elements.
level: The current level of the node in the tree (root is at level 0, its children are at level 1, and so on).
maxLevel: A reference to an integer representing the maximum level reached so far during the traversal.
if(root == nullptr) return;: This is the base case for the DFS recursion. 
If the current node is nullptr (i.e., the end of a branch), we simply return without doing anything.

if(level > maxLevel): This condition checks if the current level is greater than the maxLevel. If it is, it means we've encountered 
a node at a new level that has not been visited yet (since we're processing nodes in a left-to-right manner). In this case:

We add the current node's data to the res vector because it represents the leftmost node at this level (for the left view).
We update maxLevel to the current level, marking that we've processed a node at this level.


dfs(root->left, res, level + 1, maxLevel); : Recursively call the DFS function for the left child of the current node, 
incrementing the level by 1.

dfs(root->right, res, level + 1, maxLevel); : Recursively call the DFS function for the right child of the current node, 
incrementing the level by 1.

vector<int> leftView(Node *root): This is the main function to compute the left view of the binary tree. 
It takes root as input and returns a vector containing the left view elements.

It initializes an empty res vector to store the left view elements.
Checks if the root is nullptr, in which case it returns an empty vector (since there's no left view for an empty tree).
Initializes maxLevel to -1, which is a value less than any possible level in the tree.
Calls the dfs function with the root, passing res, starting level 0, and the reference to maxLevel.
Finally, returns the res vector containing the left view elements.

*/