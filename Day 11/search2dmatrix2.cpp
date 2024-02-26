<<<<<<< HEAD
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};
int main() {
    Solution solution;
    cout << "Enter the number of rows and columns of the matrix: ";
    int rows, columns;
    cin >> rows >> columns;
    vector<vector<int>> matrix(rows, vector<int>(columns));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> matrix[i][j];
        }
    }
    int target;
    cout << "Enter the target value: ";
    cin >> target;
    bool result = solution.searchMatrix(matrix, target);
    cout << std::boolalpha << "Output: " << result << endl;
    return 0;
}

// link for question:
=======
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};
int main() {
    Solution solution;
    cout << "Enter the number of rows and columns of the matrix: ";
    int rows, columns;
    cin >> rows >> columns;
    vector<vector<int>> matrix(rows, vector<int>(columns));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> matrix[i][j];
        }
    }
    int target;
    cout << "Enter the target value: ";
    cin >> target;
    bool result = solution.searchMatrix(matrix, target);
    cout << std::boolalpha << "Output: " << result << endl;
    return 0;
}

// link for question:
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://leetcode.com/problems/search-a-2d-matrix-ii/description/