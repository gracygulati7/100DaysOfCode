//! find last index of 1 
//* geeksforgeeks question:
//? link: https://practice.geeksforgeeks.org/problems/last-index-of-15847/1?page=1&difficulty[]=-1&category[]=Searching&sortBy=submissions

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int lastIndex(string s) {
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                return i;
            }
        }
        return -1;
    }
};
int main() {
    Solution solution;
    cout << "Enter a binary string: ";
    string binaryString;
    cin >> binaryString;
    int result = solution.lastIndex(binaryString);
    cout << "Last index of '1' in the binary string: " << result << endl;
    return 0;
}