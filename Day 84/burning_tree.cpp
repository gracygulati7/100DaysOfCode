//! Geeksforgeeks question Burning Tree

//? link: https://www.geeksforgeeks.org/problems/burning-tree/1?page=1&category=BFS&sortBy=submissions

#include <bits/stdc++.h>
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
class Solution {
public:
    int ans = 0; // This initializes an integer variable ans=0. it's used to store the minimum time required to burn the tree.
    int find(Node *root, int target, int distance) {

        if (root == NULL) { // This condition checks if the current node root is NULL (if we have reached a leaf node or a non-existent node). 
        // If so, it updates the ans variable with the maximum distance encountered so far.
            ans = max(ans, distance - 1);
            return 0; // This line returns 0, indicating that the target node has not been found in this subtree
        }
        if (root->data == target || distance > 0) { // This condition checks if the current node's data matches the target node's value target,
        // or if the distance from the root is greater than 0 (indicating that the target node has been found in a previous recursive call). 
        // If so, it recursively calls find on the left and right children with an incremented distance.
        
            find(root->left, target, distance + 1);
            find(root->right, target, distance + 1);
            return distance - 1; // this line returns the distance from the root to the current node minus 1 
        }
        else { // This block executes when the current node is not the target node, and its distance from the root is 0.
            int left = find(root->left, target, distance); // This line recursively calls find on the left child of the current node.
            int right = find(root->right, target, distance); // This line recursively calls find on the right child of the current node.

            if (left < 0) { // This condition checks if the distance returned from the left child is negative 
            // (which indicates that the target node is found in the left subtree). If so, it updates ans with 
            // the absolute value of left and performs a new recursive call to handle the right subtree with adjusted distance (1 - left).
                ans = max(ans, -left);
                find(root->right, target, 1 - left);
                return left - 1;
            }
            if (right < 0) { // This condition checks if the distance returned from the right child is negative 
            // (indicating that the target node is found in the right subtree). If true, it updates ans and 
            // performs a new recursive call to handle the left subtree.
                ans = max(ans, -right);
                find(root->left, target, 1 - right);
                return right - 1;
            }
        }
        return 0; // This statement is reached when the current node is not the target node, 
        // and neither its left nor right child contains the target node. It returns 0 to indicate that 
        // the target node has not been found in the current subtree.
    }
    int minTime(Node *root, int target) { // This function is the entry point for calculating the minimum time to burn the tree. 
    // It calls the find function with the initial distance as 0 and returns the final result stored in ans.
        find(root, target, 0);
        return ans;
    }
};