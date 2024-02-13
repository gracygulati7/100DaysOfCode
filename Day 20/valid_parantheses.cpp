//! leetcode question 20
//! Valid Parentheses

//? link: https://leetcode.com/problems/valid-parentheses/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> result;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                result.push(s[i]);
            } else {
                if (!result.empty()) {
                    if (s[i] == ')' && result.top() == '(') {
                        result.pop();
                    } else if (s[i] == ']' && result.top() == '[') {
                        result.pop();
                    } else if (s[i] == '}' && result.top() == '{') {
                        result.pop();
                    } else {
                        return false;  // Mismatched opening and closing brackets
                    }
                } else {
                    return false;  // Unmatched closing parenthesis
                }
            }
        }
        // Check if there are unmatched opening parentheses
        return result.empty();
    }
};
