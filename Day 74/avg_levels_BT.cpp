//! leetcode question 637. Average of Levels in Binary Tree

//? link: https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avgs;  // avgs mein store karenge average of all levels

        double count=0; // sum mein store karenge sum of all nodes of a level
        double sum=0; // count mein store karenge number of nodes of a level

        if(root==NULL) return {};
        queue<TreeNode*>q;
        q.push(root); q.push(NULL);
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front!=NULL){
                sum+=front->val;
                count++; // count the number of nodes in a level
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
            else{
                 // calculate the average of a level before moving to the next level as NULL is encountered
                avgs.push_back(sum/count);
                sum=0;
                count=0;
                if(!q.empty()){  // if queue is not empty then push NULL to mark the end of a level
                    q.push(NULL);
                }
            }
        }
        return avgs;
    }
};
int main(){
    Solution s;
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->left->left=new TreeNode(15);
    root->left->right=new TreeNode(7);
    vector<double> ans=s.averageOfLevels(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}