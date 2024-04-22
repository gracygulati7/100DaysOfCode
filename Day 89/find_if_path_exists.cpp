//! leetcode question 1971. Find if Path Exists in Graph (PROBLEM OF THE DAY 21-4-2024)

//? link: https://leetcode.com/problems/find-if-path-exists-in-graph/?envType=daily-question&envId=2024-04-21

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        // we create a map 'graph' where the keys are integers (node numbers) and the values are vectors of integers (adjacent nodes)
        unordered_map<int,vector<int>> graph;

        // This loop iterates over each edge in the edges vector. For each edge represented as a vector [u, v], 
        // it adds v to the adjacency list of u and vice versa in the graph map. This step effectively constructs 
        // an undirected graph based on the given edges.
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            graph[u].push_back(v); graph[v].push_back(u);
        }

        vector<bool> visited(n,false); // This vector keeps track of whether a node has been visited during the BFS traversal.
        queue<int> q; q.push(source);  // we create a queue 'q' and push the start node onto it
        visited[source]=true; // we mark the start node as visited in the visited vector.

        // This is the main BFS (Breadth-First Search) traversal loop. As long as the queue is not empty, 
        // we dequeue a node (front) from the front of the queue. If front is equal to the end node,
        //  we've found a path from start to end, so we return true.
        while(!q.empty()){
            int front=q.front(); q.pop();
            if(front==destination){
                return true;
            }
            
            // Otherwise, we iterate over the adjacent nodes of front using the adjacency list stored in graph[front]. 
            // For each adjacent node adj, if it hasn't been visited (!visited[adj]), we mark it as visited and 
            // enqueue it into the queue for further exploration.
            for(int j=0;j<graph[front].size();j++){
                int adj=graph[front][j];
                while(!visited[adj]){
                    visited[adj]=true;
                    q.push(adj);
                }
            }
        }
        return false; // If we finish the BFS traversal without finding a path from start to end, 
        // we return false, indicating that no valid path exists.
    }
};
int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};
    int source = 0;
    int destination = 3;
    bool result = sol.validPath(n, edges, source, destination);
    cout << (result ? "Path exists" : "No path exists") << endl;
    return 0;
}