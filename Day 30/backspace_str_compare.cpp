//! leetcode question 844. Backspace String Compare

//? link: https://leetcode.com/problems/backspace-string-compare/description/?envType=daily-question&envId=2024-02-23

#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.length(), m=t.length();
        vector<int> s1; vector<int> s2;
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                if(s1.size()>0){
                    s1.pop_back();
                }
            }
            else{
                s1.push_back(s[i]);
            }
        }
        for(int i=0;i<m;i++){
            if(t[i]=='#'){
                if(s2.size()>0){
                    s2.pop_back();
                }
            }
            else{
                s2.push_back(t[i]);
            }
        }
        if(s1.size()!=s2.size()) return false;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]) return false;
        }
        return true;
    }
};
int main(){
    Solution s;
    cout<<s.backspaceCompare("ab#c", "ad#c")<<endl;
    cout<<s.backspaceCompare("ab##", "c#d#")<<endl;
    return 0;
}