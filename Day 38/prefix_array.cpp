//! leetcode question 1961. Check If String Is a Prefix of Array

//? link: https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/description/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n=words.size(); string res="";
        for(int i=0;i<n;i++){
            res+=words[i];
            if(res==s){
                return true;
            }
            if(res.length()>s.length()){
                return false;
            }
        }
        return false;
    }
};