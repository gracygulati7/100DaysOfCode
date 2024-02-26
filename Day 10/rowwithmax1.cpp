<<<<<<< HEAD
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxonesrow = -1;  // initialized the row that has max ones with -1 incase there isnt any row  containing 1
        int onescount = 0;  // initialized no. of 1's in the row containing max 1's with 0 at initial stage
        int n = mat.size(); 
        int m = mat[0].size();
        for (int i = 0; i < n; i++) {
            int count = 0;  // initialized a variable for calculating no. of 1's in each row
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    count++;
                }
            }
            if (count > onescount || (count == onescount && (maxonesrow == -1 || i < maxonesrow))) {
// count > onescount: This part checks if the current row has more ones than the row with the previously maximum count of ones.
// count == onescount: This part handles the case when the current row has the same number of ones as the row with the maximum count of ones.
// (meaning two rows has exact same no. of ones that are also the max no. of ones in any row.)
// (maxonesrow == -1 || i < maxonesrow): This part handles the situation where the current maximum row index (maxonesrow) is not set (= -1)
// or when the current row index i is smaller than the existing maximum row index. If either of these conditions is true, 
// it updates the maximum row index to the current row.
                onescount = count;
                maxonesrow = i;
            }
        }
// In simpler terms:
//If the count of ones in the current row is greater than the previously known maximum count of ones, it updates the maximum row index and count.
//If the counts are equal, it compares the row indices and selects the row with the smaller index.
//This ensures that the final result represents the row with the maximum count of ones and, in case of a tie, the row with the smallest row number.
        return {maxonesrow, onescount};
    }
};
int main() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    cout << "Enter the matrix elements (0 or 1):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    Solution solution;
    vector<int> result = solution.rowAndMaximumOnes(mat);
    cout << "Row index with the maximum count of ones: " << result[0] << endl;
    cout << "Number of ones in that row: " << result[1] << endl;
    return 0;
}


//link for ques:
=======
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxonesrow = -1;  // initialized the row that has max ones with -1 incase there isnt any row  containing 1
        int onescount = 0;  // initialized no. of 1's in the row containing max 1's with 0 at initial stage
        int n = mat.size(); 
        int m = mat[0].size();
        for (int i = 0; i < n; i++) {
            int count = 0;  // initialized a variable for calculating no. of 1's in each row
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    count++;
                }
            }
            if (count > onescount || (count == onescount && (maxonesrow == -1 || i < maxonesrow))) {
// count > onescount: This part checks if the current row has more ones than the row with the previously maximum count of ones.
// count == onescount: This part handles the case when the current row has the same number of ones as the row with the maximum count of ones.
// (meaning two rows has exact same no. of ones that are also the max no. of ones in any row.)
// (maxonesrow == -1 || i < maxonesrow): This part handles the situation where the current maximum row index (maxonesrow) is not set (= -1)
// or when the current row index i is smaller than the existing maximum row index. If either of these conditions is true, 
// it updates the maximum row index to the current row.
                onescount = count;
                maxonesrow = i;
            }
        }
// In simpler terms:
//If the count of ones in the current row is greater than the previously known maximum count of ones, it updates the maximum row index and count.
//If the counts are equal, it compares the row indices and selects the row with the smaller index.
//This ensures that the final result represents the row with the maximum count of ones and, in case of a tie, the row with the smallest row number.
        return {maxonesrow, onescount};
    }
};
int main() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    cout << "Enter the matrix elements (0 or 1):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    Solution solution;
    vector<int> result = solution.rowAndMaximumOnes(mat);
    cout << "Row index with the maximum count of ones: " << result[0] << endl;
    cout << "Number of ones in that row: " << result[1] << endl;
    return 0;
}


//link for ques:
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
//https://leetcode.com/problems/row-with-maximum-ones/description/