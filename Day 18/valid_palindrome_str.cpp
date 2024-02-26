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
            if (!isalnum(s[st])) { // if current ele is not alnum then skip it and increase index by 1 towards right
                st++;
                continue;
            }
            if (!isalnum(s[e])) { // if current ele is not alnum then skip it and decrease index by 1 towards left
                e--;
                continue;
            }
            if (tolower(s[st]) != tolower(s[e])) { // if lowercase ele at left and right are not same then string isnt palindrome
                return false;
            } else { // if they are same so icrease left index by 1 and decrease right index by 1 and keep checking if they are equal or not
                st++;
                e--;
            }
        }
        return true; // if all elements to right and left are same means string is palindrome so retrun true 
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
