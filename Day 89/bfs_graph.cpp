//! GeeksForGeeks Question BFS of graph

//? link: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {

        queue<int> q; // Queue to store the nodes to be visited

        vector<int> bfs; // vector to store bfs traversal of nodes of graph

        q.push(0); // pushed the starting node from which the bfs traversal will start in the queue

        vector<bool> visited(V,false); // Visited array to keep track of visited nodes and
        //  its initialized as false because no node is visited initially

        visited[0]=true; // since we start traversing graph from starting node so we mark it to be visisted

        while(!q.empty()){ // While there are nodes to be visited

            int front=q.front(); q.pop(); // Get the front node and pop it from the queue
            bfs.push_back(front); // then push the front node to the bfs vector 

            // Visit all the nodes adjacent to the front node
            // adj[front].size() is the number of adjacent nodes to the front node
            // means the number of nodes connected to the front node
            for(int i=0;i<adj[front].size();i++){

                // Get the adjacent node
                // adj[front][i] is the ith adjacent node to the front node
                // Basically, adj[front] is the list of adjacent nodes to the front node 
                // and adj[front][i] is the ith adjacent node to the front node
                int adjnode=adj[front][i];

                if(!visited[adjnode]){ // If the adjacent node is not visited
                    visited[adjnode]=true; // Mark it as visited
                    q.push(adjnode); // and push it the queue
                }
            }
        }
        return bfs; // finally return the bfs traversal of graph nodes stored in bfs vector
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
        vector<int> bfs=ob.bfsOfGraph(V,adj);
        for(int i=0;i<bfs.size();i++){
            cout<<bfs[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}