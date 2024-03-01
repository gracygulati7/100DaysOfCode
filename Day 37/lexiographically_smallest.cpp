//! leetcode question 2697. Lexicographically Smallest Palindrome

//? link: https://leetcode.com/problems/lexicographically-smallest-palindrome/description/

#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                s[i]=s[j]=min(s[i],s[j]);
            }
            i++; j--;
        }
        return s;
    }
};
int main(){
    Solution s;
    cout<<s.makeSmallestPalindrome("egcfe")<<endl;
    return 0;
}