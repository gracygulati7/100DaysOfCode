//! leetcode question 1793. Maximum Score of a Good Subarray (HARD-LEVEL)

//? link: https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/?envType=daily-question&envId=2024-03-14

//* WHAT DOES THE QUES DEMAND?
/*
In this problem, you are given an array of integers nums and an integer k. 
You need to find a subarray of nums where the index k is positioned, and calculate the score of that subarray. 
The score of a subarray is defined as the minimum value in the subarray multiplied by the length of the subarray.

Example:
Input: nums = [1,4,3,7,4,5], k = 3
In this example, the given array is [1,4,3,7,4,5] and k = 3. We need to find a subarray where the index k = 3 is positioned.
To calculate the score of a subarray, we take the minimum value in that subarray and multiply it by the length of the subarray.
For the given array, a subarray with k = 3 could be [3,7,4]. The minimum value in this subarray is 3, 
and the length of the subarray is 3 - 1 + 1 = 3. So, the score of this subarray is 3 * 3 = 9.
However, there might be a better subarray. Let's consider the subarray [4,3,7,4,5]. The minimum value in this subarray is 3,
and the length of the subarray is 5 - 0 + 1 = 6. So, the score of this subarray is 3 * 6 = 18.
Similarly, we can consider other subarrays and find the one with the maximum score.
So, in this example, the maximum possible score of a good subarray (where k = 3) is 18.
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int i=k,j=k; // This initializes two integer variables i and j to the value of k, which is the given index.
        int ans=nums[k],mini=nums[k]; // This initializes two integer variables ans and mini to the value of the element at index k in array
        // These variables will be used to store the maximum score and the minimum value encountered during the process.
        while(i>0 || j<n-1){ // This loop iterates towards both ends of the array.
            if(i==0) j++; // If i is at the left boundary (0), then j is incremented.
            else if(j==n-1) i--; // If j is at the right boundary (n - 1), then i is decremented.
            else if(nums[i-1]<nums[j+1]){
                j++; // Otherwise, if the element to the left of i is less than the element to the right of j, j is incremented.
            }
            else i--; // Otherwise, i is decremented
            mini=min(mini,min(nums[i],nums[j]));
            // This updates the variable mini to the minimum value between its current value and the minimum value between nums[i] and nums[j].
            ans=max(ans,mini*(j-i+1));
            // This updates the maximum score (ans) to the maximum value between its current value and 
            // the product of mini and the length of the current subarray (j - i + 1).
        }
        return ans; // this represents the maximum possible score of a good subarray with the given condition.
    }
};
int main(){
    Solution s;
    vector<int> nums={1,4,3,7,4,5};
    cout<<s.maximumScore(nums,3)<<endl;
    return 0;
}