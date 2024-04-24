//! LeetCode Question 310. Minimum Height Trees (PROBLEM OF THE DAY 23-4-2024)

//? link: https://leetcode.com/problems/minimum-height-trees/?envType=daily-question&envId=2024-04-23

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0}; // Base case: only one node in tree
        
        // graph : adjacency list of nodes
        vector<vector<int>>graph(n);
        // degree count of nodes
        vector<int>degree(n,0);
        
        // populate graph adjacency list and degree count of nodes
        for(int i=0;i<edges.size();i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        
        queue<int>Q;
        // push degree 1 nodes (leaf nodes) in to queue 
        for(int i=0;i<n;i++) {
            if(degree[i]==1)Q.push(i);
        }
        // MHT root nodes
        vector<int>res;
        
        // run BFS until queue is empty 
        while(!Q.empty()) {
            int n = Q.size();
            // clear root nodes 
            res.clear();
            // perform level order traversal
            while(n--) {
                int node = Q.front();
                Q.pop();
                // add current node in to root node vector
                res.push_back(node);
                
                // process neighbour nodes
                for(int i=0;i<graph[node].size();i++) {
                    // decrease degree of neighbour nodes
                    degree[graph[node][i]]--;
                    // push leaf nodes in to queue
                    if(degree[graph[node][i]]==1) {
                        Q.push(graph[node][i]);
                    }
                }
            }
        }
        // root nodes of MHT
        return res;
    }
};
int main(){
    Solution s;
    vector<vector<int>>edges = {{1,0},{1,2},{1,3}};
    vector<int>res = s.findMinHeightTrees(4,edges);
    for(int i=0;i<res.size();i++) {
        cout<<res[i]<<" ";
    }
    return 0;
}