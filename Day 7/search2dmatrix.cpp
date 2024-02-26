#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};
int main() {
    int n, m, target;
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "Enter the target value to search: ";
    cin >> target;
    Solution solution;
    if (solution.searchMatrix(matrix, target)) {
        cout << "Target found in the matrix.\n";
    } else {
        cout << "Target not found in the matrix.\n";
    }
    return 0;
}


// link for question:
// https://leetcode.com/problems/search-a-2d-matrix/description/