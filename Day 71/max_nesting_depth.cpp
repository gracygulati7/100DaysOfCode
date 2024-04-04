//! leetcode question 1614. Maximum Nesting Depth of the Parentheses (PROBLEM OF THE DAY 4-4-2024)

//? link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/?envType=daily-question&envId=2024-04-04

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDepth(string s) { 

        // maxi stores the maximum nesting depth encountered so far.
        // curr stores the current nesting depth as we iterate through the string.
        // Current depth = parenthesis pair depth
        int n=s.length(), maxi=0, curr=0;

        for(int i=0;i<n;i++){
            // Jab bhi '(' milta hai toh curr badhao because '(' ke baad ')' hi aayega
            // so curr will be the depth of the parenthesis () pair
            if(s[i]=='('){
                curr++;
                maxi=max(maxi,curr); // We also update maxi to keep track of the maximum nesting depth encountered so far.
            }

            // Jab bhi ')' milta hai toh curr ko kam karo because ')' ke baad
            // curr will be done as a pair of parentheses is finished
            if(s[i]==')'){
                curr--;
            }
        }
        return maxi; // After iterating through the entire string, we return the maximum nesting depth (maxi) calculated during the process.
    }
};
int main() {
    Solution s;
    cout<<s.maxDepth("(1+(2*3)+((8)/4))+1")<<endl;
    cout<<s.maxDepth("(1)+((2))+(((3)))")<<endl;
    return 0;
}