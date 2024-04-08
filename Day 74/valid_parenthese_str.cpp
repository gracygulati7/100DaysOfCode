//! leetcode question 678. Valid Parenthesis String (PROBLEM OF THE DAY 7-4-2024)

//? link: https://leetcode.com/problems/valid-parenthesis-string/description/?envType=daily-question&envId=2024-04-07

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        // The variables maxi and mini are initialized to zero. These variables will be used to keep track of the 
        // maximum and minimum possible counts of open brackets '(' , taking into account wildcard characters ('*').
        int maxi=0, mini=0;

        for(char c:s){
            // This line increments maxi by 1 if the current character c is either an open bracket ('(') or a wildcard ('*'), 
            // and decrements maxi by 1 otherwise. This is done to keep track of the maximum number of open brackets that can 
            // be balanced by the end of the string.
            maxi+=(c=='(' || c=='*')?1:-1;

            // If c is either ')' (a closing bracket) or '*' (a wildcard), then -1 is added to mini. This indicates that encountering a 
            // closing bracket or a wildcard reduces the minimum number of open brackets needed to balance the string.
            /// If c is any other character (such as '(' which is an open bracket), then 1 is added to mini. This indicates that encountering
            // an open bracket increases the minimum number of open brackets needed to balance the string.
            mini+=(c==')' || c=='*')?-1:1;

            // This line checks if maxi becomes negative at any point during the loop. If it does, 
            // it means that there are more closing brackets ')' or wildcards '*' encountered so far than open brackets '('. 
            // In this case, the function returns false, indicating that the string is not valid.
            if(maxi<0) return false;

            // This line ensures that mini is always non-negative. If mini becomes negative at any point during the loop, 
            // it is set to zero. This is because the minimum count of open brackets needed to balance the string cannot be negative.
            mini=max(0,mini);
        }

        // This line checks if mini is equal to zero after processing all characters in the string. If mini is zero, it means that the 
        // minimum count of open brackets needed to balance the string is also zero, which implies that the string is valid. In this case, 
        // the function returns true; otherwise, it returns false.
        return mini==0;
    }
};
int main(){
    Solution s;
    cout<<s.checkValidString("()")<<endl;
    cout<<s.checkValidString("(*)")<<endl;
    cout<<s.checkValidString("(*))")<<endl;
    return 0;
}