//! leetcode question 1624. Largest Substring Between Two Equal Characters

//? link: https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/?envType=daily-question&envId=2024-02-20


#include<iostream>
#include<string>
#include<climits>
using namespace std;
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.size(); int maxchar=-1;
        for(int i=0;i<n-1;i++){
            int count=1;
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    maxchar=max(maxchar,j-i-1);  // j-i will give distance btw two same occuring char but we need to exclude the 
                    // reoccuring char hence we also include -1 to have only the in-btw chars btw reoccuring character
                }
            }
        }
        return maxchar;
    }
};