//! GeeksForGeeks Question DFS of Graph

//? link: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(int start, vector<int> adj[], vector<bool>& visited, vector<int>& ans){

        visited[start]=true; // Mark the starting node as visited
        ans.push_back(start); // push the starting node to ans vector

        // Visit all the nodes adjacent to the starting node
        // adj[start].size() is the number of adjacent nodes to the starting node 
        // means the number of nodes connected to the starting node
        for(int i=0;i<adj[start].size();i++){

            // Get the adjacent node
            // adj[start][i] is the ith adjacent node to the starting node
            // Basically, adj[start] is the list of adjacent nodes to the starting node 
            // and adj[start][i] is the ith adjacent node to the starting node
            int node=adj[start][i];
            if(!visited[node]){ // If the adjacent node is not visited
                dfs(node,adj,visited,ans); // Visit the adjacent node
            }
        }
    }

    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {

        vector<bool> visited(V,false); // Visited array to keep track of visited nodes
        // its initialized to false because initially all nodes are unvisited

        int start=0; // Starting node
        vector<int> ans; // this will store the dfs traversal of the graph
        dfs(start,adj,visited,ans);
        return ans;
    }
};
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int V,E;
        cin>>V>>E;
        vector<int> adj[V];
        for(int i=0;i<E;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution ob;
        vector<int> ans=ob.dfsOfGraph(V,adj);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}