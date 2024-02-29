//! leetcode question 345. Reverse Vowels of a String

//? link: https://leetcode.com/problems/reverse-vowels-of-a-string/description/

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.length()-1;
        while(i<j){
            bool flag1=false,flag2=false;
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                flag1=true;
            }
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='A'||s[j]=='E'||s[j]=='I'||s[j]=='O'||s[j]=='U'){
                flag2=true;
            }
            if(flag1 && flag2){
                swap(s[i],s[j]);
                i++;j--;
            }
            if(!flag1){
                i++;
            }
            if(!flag2){
                j--;
            }
        }
        return s;
    }
};
int main(){
    Solution s;
    cout<<s.reverseVowels("hello")<<endl;
    return 0;
}