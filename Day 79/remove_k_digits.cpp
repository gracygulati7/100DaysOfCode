//! leetcode question 402. Remove K Digits (PROBLEM OF THE DAY 11-4-2024)

//? link: https://leetcode.com/problems/remove-k-digits/description/?envType=daily-question&envId=2024-04-11

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        
        // This line declares a string variable named res and initializes it as an empty string. 
        string res="";   // This variable will store the result of the operation.

        for(int i=0;i<num.length();i++){

            // This line starts a while loop that continues as long as three conditions are true:
            // The length of the string res is not zero (res.length() != 0).
            // The last character of the string res is greater than the current character of num being processed (res.back() > num[i]).
            // The value of k is not zero (k != 0).
            while(res.length()!=0 && res.back()>num[i] && k!=0){

                res.pop_back();  // Inside the while loop, this line removes the last character from the string res.
                k--; // This line decrements the value of k by 1.
            }

            // This line checks if either of the following conditions is true:
            // The length of the string res is not zero (res.length() != 0).
            // The current character of num being processed is not '0'
            if(res.length()!=0 || num[i]!='0'){ // can't have leading '0'

                res.push_back(num[i]); // If the condition in the if statement is true, 
                // this line adds the current character of num to the end of the string res.
            }
        }

        // This line starts a while loop that continues as long as two conditions are true:
        // The length of the string res is not zero (res.length() != 0).
        // The value of k is greater than zero (k-- decrements and checks if the result is non-zero).
        while(res.length()!=0 && k--){ // make sure remove k digits in total

            res.pop_back(); // Inside the while loop, this line removes the last character from the string res until k=0
        }
        return res.empty()?"0":res; // It returns either the string "0" if res is empty (res.empty() is true), or it returns the string res.
    }
};
int main(){
    Solution s;
    cout<<s.removeKdigits("1432219", 3)<<endl;
    cout<<s.removeKdigits("10200", 1)<<endl;
    cout<<s.removeKdigits("10", 2)<<endl;
    return 0;
}