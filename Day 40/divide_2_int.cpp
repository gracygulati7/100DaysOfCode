//! leetcode question 29. Divide Two Integers

//? link: https://leetcode.com/problems/divide-two-integers/description/

#include <iostream>
#include <climits>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        double ans=(double)dividend/divisor;
        if(ans>INT_MAX){
            return INT_MAX;
        }
        else if(ans<INT_MIN){
            return INT_MIN;
        }
        return ans;
    }
};
int main(){
    Solution s;
    cout<<s.divide(10,3)<<endl;
    cout<<s.divide(-2147483648,1)<<endl;
    return 0;
}