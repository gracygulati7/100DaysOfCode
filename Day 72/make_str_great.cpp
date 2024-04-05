//! leetcode question 1544. Make The String Great (PROBLEM OF THE DAY 5-4-2024)

//? link: https://leetcode.com/problems/make-the-string-great/description/?envType=daily-question&envId=2024-04-05

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string makeGood(string s) {
        int n=s.length();
        for(int i=0;i<n-1;i++){
            if(abs(s[i]-s[i+1])==32){
                s=s.substr(0,i)+s.substr(i+2,n-i-2);
                i=-1;
                n-=2;
            }
        }
        return s;
    }
};
int main(){
    Solution s;
    cout<<s.makeGood("leEeetcode")<<endl;
    cout<<s.makeGood("abBAcC")<<endl;
    return 0;
}


//* LOGIC:
// lets take an e.g., to better understand, say s = "abBAcC" , and at i=1, we find we have to remove i=1 and i=2th character 
// to make the string great and then we have to again start the loop from i=0, so we make i=(-1) because in next iteration 
// i will be incremented and hence starts from 0, and since the length of the string has been reduced by 2, we decrement n by 2.