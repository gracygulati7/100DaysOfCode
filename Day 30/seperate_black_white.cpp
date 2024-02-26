//! leetcode question 2938. Separate Black and White Balls

//? link: https://leetcode.com/problems/separate-black-and-white-balls/description/

#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    long long minimumSteps(string s) {
        long long n=s.length(); long long ans=0;
        long long left=0,right=n-1;
        while(left<=right){
            if(s[left]=='1' && s[right]=='0'){
                ans=ans+right-left; // this is the distance between left and right elements so this will represent the 
                // number of swaps required for black and white balls to come to its right place.
                left++; right--;
            }
            else if(s[left]=='0' && s[right]=='1'){
                left++; right--;
            }
            else if(s[right]=='1') right--;
            else if(s[left]=='0') left++;
        }
        return ans;
    }
};
int main(){
    Solution s;
    cout<<s.minimumSteps("101010101010101010")<<endl;
    return 0;
}