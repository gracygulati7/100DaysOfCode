//! leetcode question 198. House Robber

//? link: https://leetcode.com/problems/house-robber/description/

#include <bits/stdc++.h>
using namespace std;
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    } 
    else if (n == 1) {
        return nums[0];
    }
    int includePrev = nums[0]; // include previous house
    int excludePrev = 0; // exclude previous house
    for (int i = 1; i < n; ++i) {
        int temp = includePrev;
        includePrev = max(includePrev, excludePrev + nums[i]);
        excludePrev = temp;
    }
    return max(includePrev, excludePrev);
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << rob(nums);
    return 0;
}


//* Example:-
/* Consider the input array: nums = [2, 7, 9, 3, 1].
Initialize include and exclude:

include = 2 (amount robbed including the first house)
exclude = 0 (amount robbed excluding the first house)
Iterate through the houses starting from the second house (index 1):

House at index 1 (nums[1] = 7):

temp = include (temporarily store the current value of include): temp = 2
include = max(include, exclude + nums[1]) (update include for the current house): include = max(2, 0 + 7) = 7
exclude = temp (update exclude): exclude = 2
House at index 2 (nums[2] = 9):

temp = include: temp = 7
include = max(include, exclude + nums[2]): include = max(7, 2 + 9) = 11
exclude = temp: exclude = 7
House at index 3 (nums[3] = 3):

temp = include: temp = 11
include = max(include, exclude + nums[3]): include = max(11, 7 + 3) = 11 (No improvement)
exclude = temp: exclude = 11
House at index 4 (nums[4] = 1):

temp = include: temp = 11
include = max(include, exclude + nums[4]): include = max(11, 11 + 1) = 12
exclude = temp: exclude = 11
After iterating through all houses, the final values are:

include = 12 (maximum amount that can be robbed including the last house)
exclude = 11 (maximum amount that can be robbed excluding the last house)
The result is the maximum of include and exclude, which is 12.

Therefore, the maximum amount that can be robbed without alerting the police is 12. 
The optimal strategy is to rob the houses at indices 0, 2, and 4, avoiding adjacent houses on the same night.
*/