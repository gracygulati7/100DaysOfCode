<<<<<<< HEAD
//! LeetCode Question 557. Reverse Words in a String III

//? link: https://leetcode.com/problems/reverse-words-in-a-string-iii/?envType=daily-question&envId=2024-02-15

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int start = 0; // start will keep track of the starting index of the current word.
        string result = ""; // result is initially an empty string that will store the reversed words.
        for (int i = 0; i <= n; ++i) {
// This is the start of a for loop that iterates over each character in the string, including the space after the last word (hence, i <= n)
            if (i == n || s[i] == ' ') {
            // This condition checks if the current character is either the end of the string or a space character. 
            // This is used to identify the end of a word.
                string word = s.substr(start, i - start);
                // a substring word is created using s.substr(start, i - start). This extracts the current word from the original string.
                reverse(word.begin(), word.end()); // The std::reverse function is applied to reverse the characters of the extracted word.
                result += word;
                if (i != n) {
                    result += ' ';  // Add space after each word except the last one
                }
                start = i + 1; // The start index is updated to point to the beginning of the next word.
            }
        }
        return result;
    }
};

int main() {
    string s;
    cout << "Enter the input string: ";
    getline(cin, s);
    Solution solution;
    string result = solution.reverseWords(s);
    cout << "Result: " << result << endl;
    return 0;
}


/*
s: This is the input string that contains the entire sentence.
start: This variable represents the starting index of the current word. 
It gets updated during the iteration to point to the beginning of the next word.

i: This is the current index in the iteration. It points to the character after the current word or the end of the string.
The substr function is then used to extract a substring from s, starting from the start index and having a length of (i - start). 
This substring represents the current word being processed in the loop.

Here's an example to illustrate the process:
For the input string "Let's take LeetCode contest":
When processing the word "Let's", start is set to 0, and i is incremented until it reaches the space after "Let's". 
Then, s.substr(start, i - start) extracts the substring "Let's" from the original string.
The word "take" is processed similarly, and so on.
=======
//! LeetCode Question 557. Reverse Words in a String III

//? link: https://leetcode.com/problems/reverse-words-in-a-string-iii/?envType=daily-question&envId=2024-02-15

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int start = 0; // start will keep track of the starting index of the current word.
        string result = ""; // result is initially an empty string that will store the reversed words.
        for (int i = 0; i <= n; ++i) {
// This is the start of a for loop that iterates over each character in the string, including the space after the last word (hence, i <= n)
            if (i == n || s[i] == ' ') {
            // This condition checks if the current character is either the end of the string or a space character. 
            // This is used to identify the end of a word.
                string word = s.substr(start, i - start);
                // a substring word is created using s.substr(start, i - start). This extracts the current word from the original string.
                reverse(word.begin(), word.end()); // The std::reverse function is applied to reverse the characters of the extracted word.
                result += word;
                if (i != n) {
                    result += ' ';  // Add space after each word except the last one
                }
                start = i + 1; // The start index is updated to point to the beginning of the next word.
            }
        }
        return result;
    }
};

int main() {
    string s;
    cout << "Enter the input string: ";
    getline(cin, s);
    Solution solution;
    string result = solution.reverseWords(s);
    cout << "Result: " << result << endl;
    return 0;
}


/*
s: This is the input string that contains the entire sentence.
start: This variable represents the starting index of the current word. 
It gets updated during the iteration to point to the beginning of the next word.

i: This is the current index in the iteration. It points to the character after the current word or the end of the string.
The substr function is then used to extract a substring from s, starting from the start index and having a length of (i - start). 
This substring represents the current word being processed in the loop.

Here's an example to illustrate the process:
For the input string "Let's take LeetCode contest":
When processing the word "Let's", start is set to 0, and i is incremented until it reaches the space after "Let's". 
Then, s.substr(start, i - start) extracts the substring "Let's" from the original string.
The word "take" is processed similarly, and so on.
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
*/