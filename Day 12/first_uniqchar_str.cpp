<<<<<<< HEAD
//! find the first unique character in a string

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            bool isUnique = true;
            for (int j = 0; j < n; j++) {
                if (i != j && s[i] == s[j]) {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) {
                return i;
            }
        }
        return -1;
    }
};
int main() {
    Solution solution;
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    int result = solution.firstUniqChar(input);
    if (result != -1) {
        cout << "The first non-repeating character is at index: " << result << endl;
    } else {
        cout << "No unique character found in the string." << endl;
    }
    return 0;
}

=======
//! find the first unique character in a string

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            bool isUnique = true;
            for (int j = 0; j < n; j++) {
                if (i != j && s[i] == s[j]) {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) {
                return i;
            }
        }
        return -1;
    }
};
int main() {
    Solution solution;
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    int result = solution.firstUniqChar(input);
    if (result != -1) {
        cout << "The first non-repeating character is at index: " << result << endl;
    } else {
        cout << "No unique character found in the string." << endl;
    }
    return 0;
}

>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05