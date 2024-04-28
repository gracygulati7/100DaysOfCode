//! GeeksForGeeks Question Exit Point in a Matrix

//? link: https://www.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        int i = 0, j = 0; // Start from top-left corner (0, 0)
        char currDir = 'R'; // Start moving right
        vector<int> ans(2); // Vector to store exit point coordinates

        // Loop until we stay within matrix bounds
        while (i < n && j < m && i >= 0 && j >= 0) {
            // Check if the current cell is a wall
            if (matrix[i][j] == 1) {
                matrix[i][j] = 0; // Mark the cell as visited

                // Change direction based on current direction
                switch (currDir) {
                    case 'R': currDir = 'D'; break; // Change direction to down
                    case 'L': currDir = 'U'; break; // Change direction to up
                    case 'D': currDir = 'L'; break; // Change direction to left
                    case 'U': currDir = 'R'; break; // Change direction to right
                }
            }

            ans[0] = i, ans[1] = j; // Update exit point

            // Move to the next cell based on current direction
            if (currDir == 'R') j += 1; // Move right
            else if (currDir == 'L') j -= 1; // Move left
            else if (currDir == 'D') i += 1; // Move down
            else if (currDir == 'U') i -= 1; // Move up
        }

        return ans; // Return the exit point
    }
};
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    Solution obj;
    vector<int> ans = obj.FindExitPoint(n, m, matrix);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}