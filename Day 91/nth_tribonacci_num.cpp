//! LeetCode Question 1137. N-th Tribonacci Number (PROBLEM OF THE DAY 24-4-2024)

//? link: https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=daily-question&envId=2024-04-24

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int tribonacci(int n) {
        int a=0,b=1,c=1;
        if(n==0) return 0;
        if(n<3) return 1;
        for(int i=3;i<=n;i++){
            int d=a+b+c;
            a=b; b=c; c=d;
        }
        return c;
    }
};
int main(){
    Solution s;
    cout<<s.tribonacci(4)<<endl;
    cout<<s.tribonacci(25)<<endl;
    return 0;
}