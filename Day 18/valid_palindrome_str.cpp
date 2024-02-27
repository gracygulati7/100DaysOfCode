//! Valid Palindrome
//! leetcode question 125

//? link: https://leetcode.com/problems/valid-palindrome/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <cctype>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0, e = s.size() - 1;
        while (st <= e) {
            if (!isalnum(s[st])) {
                st++;
                continue;
            }
            if (!isalnum(s[e])) {
                e--;
                continue;
            }
            if (tolower(s[st]) != tolower(s[e])) {
                return false;
            } else {
                st++;
                e--;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << "Enter a string: ";
    string input;
    getline(cin, input);
    bool result = solution.isPalindrome(input);
    if (result) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}