//! leetcode question 1572. Matrix Diagonal Sum

//? link: https://leetcode.com/problems/matrix-diagonal-sum/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += mat[i][i]; // we need to add diag elements like (0,0) , (1,1) , (2,2) & so on.. so mat[i][i]
            sum += mat[i][n - 1 - i]; // we also need to add other diag elements like (0,3) , (1,2) , (2,1) , (3,0) & so on for a 4*4 mat means
            // mat[i][n-1-i] 
        }
        if (n % 2 != 0) {
            sum -= mat[n / 2][n / 2]; 
        }
// also if its an odd matrix so middle element of both diags will be same which only needs to be added one time to sum 
// hence we need to subtract it from sum 
        return sum;
    }
};

int main() {
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n, 0));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    Solution solution;
    int result = solution.diagonalSum(mat);

    cout << "Diagonal sum: " << result << endl;

    return 0;
}