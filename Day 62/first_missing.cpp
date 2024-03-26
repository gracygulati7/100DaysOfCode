//! leetcode question 41. First Missing Positive (PROBLEM OF THE DAY 26-3-2024)

//? link: https://leetcode.com/problems/first-missing-positive/description/?envType=daily-question&envId=2024-03-26

//*NOTE: we did not use sorting as it requires time complexity of O(n log n) and we need to solve 
//* this question in O(1) auxiliary space and O(n) time complexity

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        // Perform cyclic sort to place each number at its correct position
        for(int i=0;i<n;i++){
            while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        // Find the smallest positive integer that is not present in the array
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        // If all positive integers from 1 to n are present, return n + 1
        return n+1;
    }
};
int main(){
    Solution s;
    vector<int> nums={3,4,-1,1};
    cout<<s.firstMissingPositive(nums)<<endl;
    return 0;
}


//* LOGIC:
/*
Let's delve into why this swapping logic is used:
The aim of the cyclic sort algorithm, in this case, is to rearrange the numbers in the array such that 
each positive integer i (where 1 <= i <= n) appears at index i - 1 in the array nums. This means that 
if the array contains all positive integers from 1 to n, after the cyclic sort, nums[i - 1] should ideally be equal to i.
meaning after sorting element at index i-1 should be equal to ith index value.
for eg in sorted array [1,2,3,4,5] if we take 0 based indexing then indexes of array are [0,1,2,3,4] so consider i=1
so nums[i-1] should be equal to i means if i is 1 in this case then nums[i-1] -> nums[1-1] -> nums[0] should be equal to i which is 1 means
element at index 0 (i-1) should be 1 if i=1.


Now, let's analyze nums[nums[i] - 1] != nums[i]. 
This condition checks whether the current number nums[i] is already at its correct position in the array. 

Here's why:
nums[i]: Represents the current number we are considering during the iteration.
nums[i] - 1: Represents the index where nums[i] should ideally be placed if the array was sorted.
nums[nums[i] - 1]: Retrieves the value/element at the index where nums[i] should ideally be placed.
If nums[nums[i] - 1] != nums[i], it implies that nums[i] is not at its correct position, 
and we need to swap it with the element at the index nums[i] - 1 to place it at the correct position.

*/