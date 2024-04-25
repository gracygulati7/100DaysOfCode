//! GeeksForGeeks Question Maximum sum of hour glass (POTD 25-4-2024)

//? link: https://www.geeksforgeeks.org/problems/maximum-sum-of-hour-glass3842/1

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        // if either n or m < than 3, means that the matrix doesn't have enough rows or columns to form an hourglass shape.
        if(n<3 || m<3) return -1;
        int maxsum=INT_MIN; // it stores the maximum sum found among all hourglasses.

        // we traverse i and j loop till n-2 and m-2 because to form a complete hour glass we need atleast 3 rows and 3 cols.
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                // we consider i and j to be at the top left corner of the matrix.
                // so For each position (i, j) in the matrix, we add the values of the elements that form the hourglass shape.
                int sum=mat[i][j]+mat[i][j+1]+mat[i][j+2]+mat[i+1][j+1]+
                mat[i+2][j]+mat[i+2][j+1]+mat[i+2][j+2];
                // we update maxsum to store the maximum of its current value and the sum of the current hourglass. 
                maxsum=max(maxsum,sum); // This ensures that maxsum always holds the maximum sum found among all hourglasses processed so far.
            }
        }
        return maxsum;
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    Solution ob;
    cout<<ob.findMaxSum(n,m,mat)<<endl;
    return 0;
}