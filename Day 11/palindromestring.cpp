#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isPalindrome(string S) {
        string rev = S; 
        reverse(rev.begin(), rev.end());
        return rev == S;
    }
};
int main() {
    Solution solution;
    string inputString;
    cout << "Enter a string: ";
    cin >> inputString;
    if (solution.isPalindrome(inputString)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}

// link for question:
// https://practice.geeksforgeeks.org/problems/palindrome-string0817/1?page=1&difficulty[]=0&category[]=Strings&sortBy=submissions