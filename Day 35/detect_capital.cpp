//! leetcode question 520. Detect Capital

//? link: https://leetcode.com/problems/detect-capital/description/

#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.length(); int count=0;
        if(n==1){
            return true;
        }
        for(int i=0;i<n;i++){
            if(isupper(word[i])){
                count++;
            }
        }
        if(count==1 && isupper(word[0])){
            return true;
        }
        if(count==0 || count==n){
            return true;
        }
        else return false;
    }
};
int main(){
    Solution s;
    cout<<s.detectCapitalUse("USA")<<endl;
    cout<<s.detectCapitalUse("FlaG")<<endl;
    return 0;
}