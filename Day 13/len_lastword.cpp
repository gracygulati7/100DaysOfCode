<<<<<<< HEAD
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int length = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != ' ') {
                // Increment length if the character is not a space
                ++length;
            } else if (length > 0) {
                // If we encounter a space and we've found some characters before,
                // we've reached the end of the last word.
                break;
            }
        }
        return length;
    }
};
int main() {
    Solution solution;
    string input;
    cout << "Enter the string: ";
    getline(cin, input);
    int result = solution.lengthOfLastWord(input);
    cout << "Length of the last word: " << result << endl;
    return 0;
}


=======
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int length = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != ' ') {
                // Increment length if the character is not a space
                ++length;
            } else if (length > 0) {
                // If we encounter a space and we've found some characters before,
                // we've reached the end of the last word.
                break;
            }
        }
        return length;
    }
};
int main() {
    Solution solution;
    string input;
    cout << "Enter the string: ";
    getline(cin, input);
    int result = solution.lengthOfLastWord(input);
    cout << "Length of the last word: " << result << endl;
    return 0;
}


>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://leetcode.com/problems/length-of-last-word/description/