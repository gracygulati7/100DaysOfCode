#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int ss = s.size(), tt = t.size();
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < ss; i++) {
            if (t[i] != s[i]) {
                return t[i];
            }
        }
        return t[ss];
    }
};
int main() {
    Solution solution;
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;
    char addedLetter = solution.findTheDifference(s, t);
    cout << "Added Letter: " << addedLetter << endl;
    return 0;
}

// https://leetcode.com/problems/find-the-difference/description/