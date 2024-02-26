//! leetcode question 463. Island Perimeter

//? link: https://leetcode.com/problems/island-perimeter/description/

//* for better understanding refer to examples of this question on leetcode

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0; // number of lands in the grid
        int surround=0; // number of surroundings to the current land that are also land in the grid
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    count++; // if current cell==1 means its land so count++                    if(i!=0 && grid[i-1][j]==1) surround++; // if cell above current cell is also 1 means its also land so surround++
                    if(j!=0 && grid[i][j-1]==1) surround++; // if cell left of current cell is also 1 means its also land so surround++
                    if(i<grid.size()-1 && grid[i+1][j]==1) surround++; // if cell below current cell is also 1 means its also land so surround++
                    if(j<grid[i].size()-1 && grid[i][j+1]==1) surround++; // if cell right of current cell is also 1 means its also land so surround++
                }
            }
        }
        return 4*count-surround; // so 4*count indicates perimeter of the island and surround indicates the number of surroundings to the island
        // so we subtract the number of surroundings to the island from 4*count to get perimeter of total island space.
    }
};
int main(){
    Solution s;
    vector<vector<int>> grid={
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };
    cout<<s.islandPerimeter(grid)<<endl;
    return 0;
}