//! excel column sheet title
//* leetcode question 168:
//? link: https://leetcode.com/problems/excel-sheet-column-title/description/

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            columnNumber--;  
            char ch = 'A' + columnNumber % 26;
            result = ch + result;
            columnNumber /= 26;
        }
        return result;
    }
};
int main() {
    int columnNumber;
    cout << "Enter the column number: ";
    cin >> columnNumber;
    Solution solution;
    string columnTitle = solution.convertToTitle(columnNumber);
    cout << "The corresponding column title is: " << columnTitle << endl;
    return 0;
}
