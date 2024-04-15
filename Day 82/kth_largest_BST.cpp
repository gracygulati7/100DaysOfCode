//! Geeksforgeeks question Kth largest element in BST

//? link: https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1?page=2&category=Tree,Binary%20Search%20Tree&sortBy=submissions

#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
    public:
    int kthLargest(Node *root, int K)
    {
        if(root==NULL) return 0;
        vector<int> arr;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* front=q.front();
            q.pop();
            if(front!=NULL){
                arr.push_back(front->data);
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
        return arr[n-K];
    }
};
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    Solution obj;
    cout<<obj.kthLargest(root,3)<<endl;
    return 0;
}