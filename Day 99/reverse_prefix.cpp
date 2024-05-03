//! LeetCode Question 2000. Reverse Prefix of Word [POTD 1-5-2024]

//? link: https://leetcode.com/problems/reverse-prefix-of-word/description/?envType=daily-question&envId=2024-05-01

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n=word.length(); 
        string res=""; // string to store the prefix before first occurence of char ch in string word
        for(int i=0;i<n;i++){
            res+=word[i]; // adding characters of word to res before first occurence of char ch
            // if current character = ch then reverse the string res and break out of loop coz we dont want to further do any operation
            if(word[i]==ch){ 
                reverse(res.begin(),res.end());
                break;
            }
        }
        // store the reversed string back in string word
        for(int i=0;i<res.length();i++){
            word[i]=res[i];
        }
        return word; 
    }
};
int main(){
    Solution s;
    cout<<s.reversePrefix("abcdefd",'d')<<endl;
    return 0;
}