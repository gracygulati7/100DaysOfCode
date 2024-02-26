<<<<<<< HEAD
//! leetcode question 2108:
//! find the first palindromic string in array
//* leetcode problem of the day 13-02-2024

//? link: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/?envType=daily-question&envId=2024-02-13

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string palindromic;
        for(int i=0; i<words.size(); i++){
            palindromic = words[i];
            reverse(palindromic.begin(), palindromic.end());
            if(words[i] == palindromic){
                return palindromic;
            }
        }
        return "";
    }
};

int main() {
    int n;
    cout << "Enter the number of words: ";
    cin >> n;
    vector<string> words(n);
    cout << "Enter the words:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    Solution solution;
    string result = solution.firstPalindrome(words);
    if (result.empty()) {
        cout << "No palindrome found." << endl;
    } else {
        cout << "First palindrome: " << result << endl;
    }
    return 0;
}
=======
//! leetcode question 2108:
//! find the first palindromic string in array
//* leetcode problem of the day 13-02-2024

//? link: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/?envType=daily-question&envId=2024-02-13

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string palindromic;
        for(int i=0; i<words.size(); i++){
            palindromic = words[i];
            reverse(palindromic.begin(), palindromic.end());
            if(words[i] == palindromic){
                return palindromic;
            }
        }
        return "";
    }
};

int main() {
    int n;
    cout << "Enter the number of words: ";
    cin >> n;
    vector<string> words(n);
    cout << "Enter the words:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    Solution solution;
    string result = solution.firstPalindrome(words);
    if (result.empty()) {
        cout << "No palindrome found." << endl;
    } else {
        cout << "First palindrome: " << result << endl;
    }
    return 0;
}
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
