//! geeksforgeeks question Leaf under budget

//? link: https://www.geeksforgeeks.org/problems/leaf-under-budget/1

#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
class Solution {
public:
    int getCount(Node *root, int k) {
        queue<Node*>q;
        q.push(root);
        int count=0,level=1;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* front=q.front();
                q.pop();

                // if its a leaf node & if budget is still greater than or equal to the level then 
                // subtract the leaf node's level from budget and increment the count as this leaf node 
                // can be visited within the given budget else return the current count of visited leaf nodes 
                // if budget is less than the current level.
                if(front->left==NULL && front->right==NULL){  
                    if(k>=level){
                        k-=level;
                    }
                    else return count;
                    count++;
                }

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            level++;
        }
        return count; // return count of visited leaf nodes in given budget.
    }
};
int main(){
    Node* root=new Node(10);
    root->left=new Node(8);
    root->right=new Node(2);
    root->left->left=new Node(3);
    root->right->left=new Node(3);
    root->right->right=new Node(6);
    root->right->left->right=new Node(4);
    Solution obj;
    cout<<obj.getCount(root,8)<<endl;
    return 0;
}