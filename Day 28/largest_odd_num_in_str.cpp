//! leetcode question 1903. Largest Odd Number in String

//? link: https://leetcode.com/problems/largest-odd-number-in-string/description/?envType=daily-question&envId=2024-02-21

#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size(); 
        for (int i=n-1;i>=0;i--){
            if((int)num[i]%2==1){ // Within the loop, it checks if the current character, converted to an integer ((int)num[i]), 
            // is odd (has a remainder of 1 when divided by 2), it breaks out of the loop. This is because the objective is to 
            // find the rightmost odd digit.
                break;
            }
            else num.pop_back(); // If the current character is even, it means it's not part of the rightmost odd digit. 
            // In that case, the last character of the string (num.pop_back()) is removed, effectively moving to the next character on the left.
        }
        return num;
    }
};

//* example 
/*
Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.
now in this case first the loop comes to 7 as its already an odd num so it breaks out of loop and whole number is returned.
*/