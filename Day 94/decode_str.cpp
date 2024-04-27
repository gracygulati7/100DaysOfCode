//! Leetcode Question 394. Decode String

//? link: https://leetcode.com/problems/decode-string/description/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decode(string& s, int& i) {
        string res; // string variable res to store the decoded result.

        // Enters a while loop that continues until either the end of the string s is reached or a closing bracket ] is encountered.
        // This loop iterates through the characters of the string.
        while (i < s.length() && s[i] != ']') {

            if (!isdigit(s[i])) { // Checks if the current character is not a digit.

                // If the current character is not a digit, it is appended to the result string res, and then the index i is incremented.
                res += s[i];
                i++; 
            } 

            /* If the current character is a digit, it indicates a repetition factor for a substring
            The code parses the number by iterating through consecutive digits.
            After parsing the number, it expects a '[' character.
            Then, it recursively calls the decode function to decode the substring inside the brackets.
            After the recursive call, it expects a ']' character.
            Finally, it appends the decoded substring t to the result string res n times. */
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i])) {
                    n = n * 10 + s[i] - '0';
                    i++;
                }
                i++; // '['
                string t = decode(s, i);
                i++; // ']'
                while (n-- > 0)
                    res += t;
            }
        }
        return res; // After the while loop ends (either due to reaching the end of the string or encountering ']'), 
        /// the function returns the decoded result string.
    }
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
};
int main(){
    Solution s;
    cout<<s.decodeString("3[a]2[bc]")<<endl;
    return 0;
}


//* LOGIC for n = n * 10 + s[i++] - '0';
/*
This line updates the value of n.

n * 10: Multiplies the current value of n by 10 to shift digits to the left 
(e.g., when parsing "123", n will be 0 initially, then 1, then 12, then 123).'

s[i++] - '0': Converts the character at index i to its corresponding integer value by subtracting the ASCII value of '0'.
This is a common technique to convert characters representing digits to their integer values. 
For example, if s[i] is '5', subtracting '0' gives the integer 5.


s[i++]: After extracting the digit at index i, i is incremented to move to the next character.
*/