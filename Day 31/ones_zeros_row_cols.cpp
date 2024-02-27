//! leetcode question 2482. Difference Between Ones and Zeros in Row and Column

//? link: https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/?envType=daily-question&envId=2024-02-21

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size(); 
        int m=grid[0].size();
        vector<int> onesrow(n, 0);
        vector<int> zerosrow(n, 0);
        vector<int> onescol(m, 0);
        vector<int> zeroscol(m, 0);
        for(int i=0;i<n;i++){ // Calculate ones and zeros for rows
            onesrow[i]=count(grid[i].begin(),grid[i].end(),1);
            zerosrow[i]=count(grid[i].begin(),grid[i].end(),0);
        }
        // Calculate ones and zeros for columns
        for(int j=0;j<m;j++){ // This loop iterates over each column (j) in the grid.
            for(int i=0;i<n;i++){ // It iterates over each row (i) in the current column (j). 
            // It goes from the top (row 0) to the bottom (row n-1) of the current column.
            onescol[j]+=grid[i][j]; // This line adds the value at position (i, j) in the grid to the onesCol[j]. 
            // It accumulates the count of ones in the current column (j).
            zeroscol[j]+=(1-grid[i][j]); // This line adds the complement of the value at position (i, j) in the grid to the zerosCol[j]. 
            // Since the grid contains binary values (0 or 1), (1 - grid[i][j]) gives the complement (1 for 0 (1-0=0), 0 for 1 (1-1=0)), 
            // and it accumulates the count of zeros in the current column (j).
            }
        }
        vector<vector<int>> diff(n,vector<int>(m,0)); 
        // The use of vector<int>(m, 0) ensures that each row is a vector of m integers initialized to 0.
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                diff[i][j]=onesrow[i]+onescol[j]-zerosrow[i]-zeroscol[j];
            }
        }
        return diff;
    }
};
int main(){
    Solution s;
    vector<vector<int>> grid={{1,1,1},{1,0,1},{1,1,1}};
    s.onesMinusZeros(grid);
    return 0;
}