//! leetcode question 201. Bitwise AND of Numbers Range

//? link: https://leetcode.com/problems/bitwise-and-of-numbers-range/description/

#include <iostream>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=0;
        while(left!=right){
            left=left>>1;
            right=right>>1;
            ans++;
        }
        return left<<ans;
    }
};
int main(){
    Solution s;
    cout<<s.rangeBitwiseAnd(5,7)<<endl;
    return 0;
}