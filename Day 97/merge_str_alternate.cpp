//! LeetCode question 1768. Merge Strings Alternately

//? link: https://leetcode.com/problems/merge-strings-alternately/description/?envType=study-plan-v2&envId=leetcode-75

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        string res = "";
        int i = 0, j = 0;
        while (i < n && j < m) {
            res += word1[i];
            res += word2[j];
            i++;
            j++;
        }
        while (i < n) {
            res += word1[i];
            i++;
        }
        while (j < m) {
            res += word2[j];
            j++;
        }
        return res;
    }
};
int main(){
    Solution s;
    string word1 = "abc", word2 = "pqr";
    cout << s.mergeAlternately(word1, word2) << endl;
    return 0;
}