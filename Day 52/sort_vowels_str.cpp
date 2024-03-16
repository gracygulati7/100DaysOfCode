//! leetcode question 2785. Sort Vowels in a String

//? link: https://leetcode.com/problems/sort-vowels-in-a-string/description/?envType=daily-question&envId=2024-03-16

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowel; vector<int> pos;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e'|| s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E'|| s[i]=='I' || s[i]=='O' || s[i]=='U'){
                vowel.push_back(s[i]);
                pos.push_back(i);
            }
        }
        sort(vowel.begin(),vowel.end());
        string res=s;
        for(int i=0;i<pos.size();i++){
            res[pos[i]]=vowel[i];
        }
        return res;
    }
};
int main(){
    Solution s;
    cout<<s.sortVowels("aeiou")<<endl;
    return 0;
}