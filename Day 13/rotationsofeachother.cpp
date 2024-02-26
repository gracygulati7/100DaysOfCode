#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool areRotations(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        if (s1.size() != s2.size()) {
            return false;
        }
        s1 = s1 + s1;
        if (s1.find(s2) == -1) {
            return false;
        }
        return true;
    }
};
int main() {
    Solution solution;
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;
    bool result = solution.areRotations(str1, str2);
    if (result) {
        cout << "The strings are rotations of each other." << endl;
    } else {
        cout << "The strings are not rotations of each other." << endl;
    }
    return 0;
}

// https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1?page=1&difficulty[]=-1&category[]=Strings&sortBy=submissions