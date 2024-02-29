//! leetcode question 917. Reverse Only Letters

//? link: https://leetcode.com/problems/reverse-only-letters/description/

#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n=s.length();
        int start=0,end=n-1;
        while(start<end){
            while(start<end && !isalpha(s[start])){
                start++;
            }
            while(start<end && !isalpha(s[end])){
                end--;
            }
            swap(s[start],s[end]);
            start++; end--;
        }
        return s;
    }
};
int main(){
    Solution s;
    cout<<s.reverseOnlyLetters("ab-cd")<<endl;
    return 0;
}