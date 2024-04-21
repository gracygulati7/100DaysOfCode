//! leetcode question 1992. Find All Groups of Farmland (PROBLEM OF THE DAY 20-4-2024)

//? link: https://leetcode.com/problems/find-all-groups-of-farmland/description/?envType=daily-question&envId=2024-04-20

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size(), m=land[0].size();

        vector<vector<int>> res; // res will store the result
        vector<vector<bool>> visited(n,vector<bool> (m,false)); // visited will store the visited cells
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1 && visited[i][j]==false){ // If the cell is not visited and it is a farmland (1)
                    vector<int> temp={i,j}; // create a vector to store the coordinates of the farmland

                    // i is the starting row and j is the starting column
                    temp.push_back(i); 
                    temp.push_back(j);

                    dfs(land,visited,i,j,temp);  // Apply DFS whenever we find a farmland
                    res.push_back(temp); // Push the coordinates of the farmland to the result
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& land,vector<vector<bool>>& visited, int i,int j,vector<int>& temp) {

        // If the cell is out of bounds or it is not a farmland or it has been visited earlier 
        if(i<0 || i>=land.size() || j<0 || j>=land[0].size() || visited[i][j]==true || land[i][j]==0){
            return;
        }
        visited[i][j]=true; // Mark the current cell as visited

        temp[2]=max(temp[2],i); temp[3]=max(temp[3],j); // Update the coordinates of the farmland

        // Apply DFS in all four directions
        dfs(land,visited,i-1,j,temp); dfs(land,visited,i+1,j,temp);
        dfs(land,visited,i,j-1,temp); dfs(land,visited,i,j+1,temp);
    }
};
int main(){
    Solution s;
    vector<vector<int>> land={
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,0,0,0},
        {0,0,0,2,2}
    };
    vector<vector<int>> res=s.findFarmland(land);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}