//! leetcode question 1979. Find Greatest Common Divisor of Array

//? link: https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size(); int mini=INT_MAX; int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        int gcd=0; int maxgcd=INT_MIN;
        for(int i=1;i<=maxi && i<=mini;i++){
            if(mini%i==0 && maxi%i==0){
                gcd=i;
                maxgcd=max(maxgcd,gcd);
            }
        }
        return maxgcd;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3,4,5};
    cout<<s.findGCD(nums)<<endl;
    return 0;
}