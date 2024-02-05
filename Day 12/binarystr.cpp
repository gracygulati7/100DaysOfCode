#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    // Function to count the number of substrings that start and end with 1.
    long long binarySubstring(int n, string a) {
        long long count = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == '1') {
                count++;
            }
        }
        return (count * (count - 1)) / 2;  // Formula for counting combinations of 2 elements from count
    }
};
int main() {
    Solution solution;
    cout << "Enter the length of the binary string: ";
    int length;
    cin >> length;
    cout << "Enter the binary string: ";
    string binaryString;
    cin >> binaryString;
    long long result = solution.binarySubstring(length, binaryString);
    cout << "Number of substrings that start and end with 1: " << result << endl;
    return 0;
}


// https://practice.geeksforgeeks.org/problems/binary-string-1587115620/1?page=1&difficulty[]=-1&category[]=Strings&sortBy=submissions