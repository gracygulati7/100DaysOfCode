//! leetcode question 2864. Maximum Odd Binary Number

//? link: https://leetcode.com/problems/maximum-odd-binary-number/description/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.length();
        sort(s.rbegin(),s.rend());
        for(int i=n;i>=0;i--){
            if(s[i]=='1'){
                swap(s[i],s[n-1]);
            }
        }
        return s;
    }
};
int main(){
    Solution s;
    cout<<s.maximumOddBinaryNumber("010");
    return 0;
}

//* LOGIC:
/*            s = "0101"
lets sort it in a way that all 1's will be in front and 0's at last.
            s = "1100"
Since we have to return greatest odd number, there should be 
atleast one 1 at the end, so lets just swap only one 1 at the last.
But the catch is which 1 should we actually swap.
Lets find it out:
Lets swap with the first positioned 1 in the string.
            s = "1100"  =>  s = "0101"
Lets just try once more to swap it with the last positioned 
1 we have.
            s = "1100" =>  s = "1001"
Here we goooo, 
if we swapped with the last positioned 1 we are getting 
the greatest odd number.
Even if we had only one 1, this logic will still give desired output.
*/