//! find index of first occurence in a string
//! leetcode question 28

//? link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    cout << "Enter the haystack string: ";
    string haystack;
    getline(cin, haystack);
    cout << "Enter the needle string: ";
    string needle;
    getline(cin, needle);
    int result = solution.strStr(haystack, needle);
    if (result != -1) {
        cout << "The first occurrence of needle in haystack is at index: " << result << endl;
    } else {
        cout << "Needle is not part of haystack." << endl;
    }
    return 0;
}
