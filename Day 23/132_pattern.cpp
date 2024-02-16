//! LeetCode Question 456. 132 Pattern

//?link: https://leetcode.com/problems/132-pattern/description/?envType=daily-question&envId=2024-02-16

#include <bits/stdc++.h>
using namespace std;
bool find132pattern(vector<int> &nums) {
    int n = nums.size();
    if (n < 3) {
        return false; // the pattern requires at least three elements.
    } 
    int i = nums[0]; // initialize i to first element of nums array
    for (int j = 1; j < n - 1; j++) { // start j loop from next index to second last index of array
        if (nums[j] > i) { // check if current element j>i
            int k = j + 1; // if yes, initialize k to next index after k
            // now while k<n (its in range of array) and i>=nums[k] so increment k coz we need to find that nums[k] which is > value of i.
            while (k < n && i >= nums[k]) { 
                k++;
            }
            // now if k!=n and if nums[k]>i, then we also need to check uf nums[k]<nums[j]
            if (k != n && nums[k] < nums[j]){
                return true;
            }
            // if we found that case means we found a 132 pattern in array
        }
    i = min(nums[j], i); // Update the value of i to be the minimum of the current element (nums[j]) and the current value of i (nums[0]). 
                         // This ensures that i always represents the smallest value encountered so far.
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    cout << find132pattern(nums);
    return 0;
}