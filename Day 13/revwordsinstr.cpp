<<<<<<< HEAD
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseWords(string S) {
        string words = "";
        string ans = "";
        for (int i = 0; i < S.length(); i++) {
            if (S[i] != '.') {
                words += S[i];
            }
            if (S[i] == '.') {
                words = S[i] + words;
                ans = words + ans;
                words = "";
            }
            if (i == S.length() - 1) {
                ans = words + ans;
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;
    string input;
    cout << "Enter a string with words separated by dots: ";
    getline(cin, input);
    string result = sol.reverseWords(input);
    cout << "Reversed string: " << result << endl;
    return 0;
}

=======
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseWords(string S) {
        string words = "";
        string ans = "";
        for (int i = 0; i < S.length(); i++) {
            if (S[i] != '.') {
                words += S[i];
            }
            if (S[i] == '.') {
                words = S[i] + words;
                ans = words + ans;
                words = "";
            }
            if (i == S.length() - 1) {
                ans = words + ans;
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;
    string input;
    cout << "Enter a string with words separated by dots: ";
    getline(cin, input);
    string result = sol.reverseWords(input);
    cout << "Reversed string: " << result << endl;
    return 0;
}

>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1?page=1&difficulty[]=0&category[]=Strings&sortBy=submissions