//! leetcode question 1342. Number of Steps to Reduce a Number to Zero

//? link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/description/

#include <iostream>
using namespace std;
class Solution {
public:
    int numberOfSteps(int num) {
        int step=0;
        if(num==0){
            return 0;
        }
        while(num!=0){
            if(num%2==0){
                num/=2;
                step++;
            }
            if(num%2!=0){
                num--;
                step++;
            }
        }
        return step;
    }
};
int main(){
    Solution s;
    cout<<s.numberOfSteps(14)<<endl;
    cout<<s.numberOfSteps(15)<<endl;
    cout<<s.numberOfSteps(4)<<endl;
    return 0;
}