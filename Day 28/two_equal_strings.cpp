//! leetcode question 1662. Check If Two String Arrays are Equivalent

//? link: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/?envType=daily-question&envId=2024-02-21

#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n=word1.size(), m=word2.size(); string word1res="", word2res="";
        for(int i=0;i<n;i++){
            for(int j=0;j<word1[i].size();j++){
                word1res+=word1[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<word2[i].size();j++){
                word2res+=word2[i][j];
            }
        }
        if(word1res==word2res){
            return true;
        }
        return false;
    }
};