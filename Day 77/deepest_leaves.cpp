//! leetcode question 1302. Deepest Leaves Sum

//? link: https://leetcode.com/problems/deepest-leaves-sum/description/

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

    // Get the level/depth of the tree.
    int depth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left=0, right=0;
        if (root->left != NULL) {
            left = depth(root->left);
        }
        if (root->right) {
            right = depth(root->right);
        }

        // Max of left and right +1 for root level.
        return max(left, right) + 1;
    }

    // Get the sum of all the last level nodes.
    int lastlevelsum(TreeNode* root, int height){
        if(root==NULL) return 0;
        int sum=0;

        // height is the level of the current node. We decrement it by 1 because
        // we are traversing the tree from top to bottom.
        height-=1;

        // If we reach the last level, return the value of the node.
        if(height==0){
            return root->val;
        }

         // Recursive function on root->left
        if(root->left!=NULL){
            sum+=lastlevelsum(root->left,height);
        }
        
         // Recursive function on root->left
        if(root->right!=NULL){
            sum+=lastlevelsum(root->right,height);
        }
        return sum;
    }

    int deepestLeavesSum(TreeNode* root) {
        int target = depth(root); // Get the deepest level/depth.
        return lastlevelsum(root, target);
    }
};
int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout << s.deepestLeavesSum(root) << endl;
    return 0;
}