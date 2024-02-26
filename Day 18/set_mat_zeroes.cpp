//! set matrix zeroes
//! leetcode question 73

//? link: https://leetcode.com/problems/set-matrix-zeroes/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rows(n, 0);
        vector<int> cols(m, 0);
        cout << "Enter the matrix (" << n << "x" << m << "):" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // if any element in matrix=0 then we for instance take that row[i] and col[j] = 1 to which i & j that 0 ele cell is present
                if (matrix[i][j] == 0) { 
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) { 
                // now iterating over the rows[i] & cols[j] that were marked as 1 we put matrix[i][j]=0 for all values of row[i] & cols[j] 
                if (rows[i] == 1 || cols[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
        cout << "Modified matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Solution solution;
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    solution.setZeroes(matrix);
    return 0;
}