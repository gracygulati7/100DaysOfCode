//! is subsequence
//! leetcode question 392

//? link: https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for (int i = 0; i < t.size() && j < s.size(); i++) {
            if (s[j] == t[i]) {
                j++;
            }
        }
        return (j == s.length());
    }
};

int main() {
    Solution solution;
    string s, t;
    cout << "Enter the first string (s): ";
    cin >> s;
    cout << "Enter the second string (t): ";
    cin >> t;
    bool result = solution.isSubsequence(s, t);
    if (result) {
        cout << "Yes, " << s << " is a subsequence of " << t << endl;
    } else {
        cout << "No, " << s << " is not a subsequence of " << t << endl;
    }
    return 0;
}
