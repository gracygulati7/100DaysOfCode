//! Leetcode Question 2221. Find Triangular Sum of an Array

//? link: https://leetcode.com/problems/find-triangular-sum-of-an-array/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        // Termination condition: if there's only one element, return its value
        if (n == 1) {
            return nums[0];
        }
        vector<int> sum;
        for (int i = 0; i < n - 1; i++) {
            sum.push_back((nums[i] + nums[i + 1]) % 10);
        }
        
        // Recursive call to triangularSum with the updated array sum
        return triangularSum(sum);
    }
};
int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    Solution s;
    cout << s.triangularSum(nums) << endl;
    return 0;
}

//* LOGIC for `sum.push_back((nums[i] + nums[i + 1]) % 10);` :
/*
nums[i] + nums[i + 1]: This expression calculates the sum of two adjacent elements in the input array nums.

(nums[i] + nums[i + 1]) % 10: 
The modulo operator % calculates the remainder when the sum of the two adjacent elements is divided by 10. 
Since each element in nums is a digit between 0 and 9 (inclusive), taking the remainder when divided by 10 
ensures that the resulting value is between 0 and 9.

For example:
If nums[i] + nums[i + 1] is 12, then (12 % 10) will be 2.
If nums[i] + nums[i + 1] is 17, then (17 % 10) will be 7.
If nums[i] + nums[i + 1] is 9, then (9 % 10) will be 9.

By taking the remainder modulo 10, we ensure that the resulting value remains within the range of a single digit, 
which aligns with the constraints of the problem where each element in nums is a digit between 0 and 9 (inclusive).

*/