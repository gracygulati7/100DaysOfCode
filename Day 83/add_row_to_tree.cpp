//! leetcode question 623. Add One Row to Tree (PROBLEM OF THE DAY 16-4-2024)

//? link: https://leetcode.com/problems/add-one-row-to-tree/description/?envType=daily-question&envId=2024-04-16

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) // if depth is 1, then we have to simply add root
        {
            TreeNode* newNode = new TreeNode(val);
            newNode -> left = root;
            return newNode; // now this acts as new root
        }
        
        queue<TreeNode*> q; // defining queue
        q.push(root); // push queue
        int count = 0; // variable to count level
        
        // start bfs
        while(!q.empty()) 
        {
            // since we have to add values on all of the nodes
            // present at that level, so take out the size
            int n = q.size(); 
            
            count++; // increase size
            while(n--)
            {
                TreeNode* curr = q.front(); // take out current node
                q.pop(); // pop it from queue
                
                // if we've not reached our required level
                // so we have to do nothing, simply push into queue
                if(count != depth - 1) 
                {
                    if(curr -> left) q.push(curr -> left);
                    if(curr -> right) q.push(curr -> right);
                }
                else // if we reach our required level
                {
                    // make a new node to add
                    TreeNode* newNode = new TreeNode(val);
                    // first put left of curr to left of newNode
                    newNode -> left = curr -> left;
                    // now left of curr becomes newNode
                    curr -> left = newNode;
                    
                    // make another new node to add
                    TreeNode* newNode2 = new TreeNode(val);
                    // now put right of curr to right of newNode
                    newNode2 -> right = curr -> right;
                     // now right of curr becomes newNode
                    curr -> right = newNode2;
                }
            }
        }

        return root; // finally return root
    }
};