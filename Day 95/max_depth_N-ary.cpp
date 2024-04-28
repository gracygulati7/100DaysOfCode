//! LeetCode Question 559. Maximum Depth of N-ary Tree

//? link: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/

#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL) return 0;
        int max_depth=1;
        for(int i=0;i<root->children.size();i++){
            max_depth=max(max_depth,1+maxDepth(root->children[i]));
        }
        return max_depth;
    }
};