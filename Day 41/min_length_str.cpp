//! leetcode question 1750. Minimum Length of String After Deleting Similar Ends
//* PROBLEM OF THE DAY 5-3-2024

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int left=0,right=n-1;
        while(left<right && s[left]==s[right]){
            char ch=s[left];
                while(left<=right && s[left]==ch){
                   left++;
                }
                while(right>=left && s[right]==ch){
                   right--;
                }
        }
        return right-left+1; // this will give length of the string that remains after removing similar ends.
        // we add 1 to it coz we take 0 indexed string but answer should be returned as number of char left in string which would start from 1.
    }
};
int main(){
    Solution s;
    cout<<s.minimumLength("abcd")<<endl;
    return 0;
}