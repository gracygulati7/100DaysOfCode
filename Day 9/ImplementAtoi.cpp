<<<<<<< HEAD
//! PROBLEM OF THE DAY OF GEEKSFORGEEKS

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int atoi(string s) {
        int n = s.size();
        int sign = +1;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '-' && i == 0) { // to check if - is the first char at 0th index
                sign = -1;
            } else if (s[i] >= '0' && s[i] <= '9') { // if char of strings are between 0-9
                result = result * 10 + (s[i] - '0');
                // s[i]-'0' means subtracting the ASCII value of 0 from ASCII value of s[i] 
                // giving the digit in int form.
                // adding the digit to result*10 resulting in the digits making the number as a whole 
                // like 123 means one hundred twenty-three & not one two three
            } else { // if string contains any other char that's not numeric
                return -1;
            }
        }
        result = result * sign; 
        // if the num is -ve we should multiply it with sign or else we'll always get a positive num
        return result;
    }
};
int main() {
    Solution solution;
    string userInput;
    cout << "Enter a numeric string: ";
    cin >> userInput;
    int result = solution.atoi(userInput);
    if (result != -1) {
        cout << "Converted integer: " << result << endl;
    } else {
        cout << "Conversion not feasible." << endl;
    }
    return 0;
}


// link for question:
=======
//! PROBLEM OF THE DAY OF GEEKSFORGEEKS

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int atoi(string s) {
        int n = s.size();
        int sign = +1;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '-' && i == 0) { // to check if - is the first char at 0th index
                sign = -1;
            } else if (s[i] >= '0' && s[i] <= '9') { // if char of strings are between 0-9
                result = result * 10 + (s[i] - '0');
                // s[i]-'0' means subtracting the ASCII value of 0 from ASCII value of s[i] 
                // giving the digit in int form.
                // adding the digit to result*10 resulting in the digits making the number as a whole 
                // like 123 means one hundred twenty-three & not one two three
            } else { // if string contains any other char that's not numeric
                return -1;
            }
        }
        result = result * sign; 
        // if the num is -ve we should multiply it with sign or else we'll always get a positive num
        return result;
    }
};
int main() {
    Solution solution;
    string userInput;
    cout << "Enter a numeric string: ";
    cin >> userInput;
    int result = solution.atoi(userInput);
    if (result != -1) {
        cout << "Converted integer: " << result << endl;
    } else {
        cout << "Conversion not feasible." << endl;
    }
    return 0;
}


// link for question:
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://www.geeksforgeeks.org/problems/implement-atoi/1