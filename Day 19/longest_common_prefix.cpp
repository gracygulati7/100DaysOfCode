<<<<<<< HEAD
//! longest common prefix
//! leetcode question 14

//? link: https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        // Initialize an empty string to store the common prefix
        string ans = "";
        // Get the number of strings in the vector
        int n = strs.size();
        // Get the first and last strings after sorting
        string first = strs[0], last = strs[n - 1];
        // Iterate through characters of the first and last strings
        for (int i = 0; i < min(first.size(), last.size()); i++) {
            // If the characters are not equal, return the current common prefix
            if (first[i] != last[i]) {
                return ans;
            }
            // Otherwise, append the current character to the common prefix
            ans += first[i];
        }
        // Return the final common prefix
        return ans;
    }
};

int main() {
    Solution solution;
    cout << "Enter the number of strings: ";
    int numStrings;
    cin >> numStrings;
    vector<string> strs(numStrings);
    cout << "Enter the strings:" << endl;
    for (int i = 0; i < numStrings; i++) {
        cin >> strs[i];
    }
    string result = solution.longestCommonPrefix(strs);
    cout << "Longest common prefix: " << result << endl;
    return 0;
=======
//! longest common prefix
//! leetcode question 14

//? link: https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        // Initialize an empty string to store the common prefix
        string ans = "";
        // Get the number of strings in the vector
        int n = strs.size();
        // Get the first and last strings after sorting
        string first = strs[0], last = strs[n - 1];
        // Iterate through characters of the first and last strings
        for (int i = 0; i < min(first.size(), last.size()); i++) {
            // If the characters are not equal, return the current common prefix
            if (first[i] != last[i]) {
                return ans;
            }
            // Otherwise, append the current character to the common prefix
            ans += first[i];
        }
        // Return the final common prefix
        return ans;
    }
};

int main() {
    Solution solution;
    cout << "Enter the number of strings: ";
    int numStrings;
    cin >> numStrings;
    vector<string> strs(numStrings);
    cout << "Enter the strings:" << endl;
    for (int i = 0; i < numStrings; i++) {
        cin >> strs[i];
    }
    string result = solution.longestCommonPrefix(strs);
    cout << "Longest common prefix: " << result << endl;
    return 0;
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
}