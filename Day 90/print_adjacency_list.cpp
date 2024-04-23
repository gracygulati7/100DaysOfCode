//! GeeksForGeeks Question Print adjacency list

//? link: https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i].first].push_back(edges[i].second); // edges[i].first is the first value of edge of index i and 
            // edges[i].second is the second value of edge of index i.
            adj[edges[i].second].push_back(edges[i].first); // its same as pushing u to v and v to u.
        }
        return adj;
    }
};
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int V,E;
        cin>>V>>E;
        vector<pair<int,int>> edges;
        for(int i=0;i<E;i++){
            int u,v;
            cin>>u>>v;
            edges.push_back({u,v});
        }
        Solution ob;
        vector<vector<int>> adj=ob.printGraph(V,edges);
        for(int i=0;i<V ;i++){
            sort(adj[i].begin(),adj[i].end());
            for(auto it:adj[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}