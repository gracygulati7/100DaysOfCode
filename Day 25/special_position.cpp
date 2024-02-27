//! leetcode question 1582. Special Positions in a Binary Matrix

//? link: https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/?envType=daily-question&envId=2024-02-18

#include <vector>
using namespace std;
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(); 
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    bool isSpecial = true;
                    // Checking the entire row for non-zero elements
                    for (int k = 0; k < m; k++) {
                        if (k != j && mat[i][k] == 1) {
                            isSpecial = false;
                            break;
                        }
                    }
                    // Checking the entire column for non-zero elements
                    for (int k = 0; k < n; k++) {
                        if (k != i && mat[k][j] == 1) {
                            isSpecial = false;
                            break;
                        }
                    }
                    if (isSpecial) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};