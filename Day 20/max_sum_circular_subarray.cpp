//! leetcode question 918
//! maximum sum circular subarray

//? link: https://leetcode.com/problems/maximum-sum-circular-subarray/?envType=study-plan-v2&envId=top-interview-150

#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
class Solution{
    public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        // Find the maximum subarray sum in a non-circular array
        int maxsum=kadane(nums);
        // Find the minimum subarray sum in a non-circular array
        int totalsum=0; 
        // totalSum represents the sum of all elements in the array, considering all possible subarrays (circular and non-circular).
        int minsum=kadanenegative(nums,totalsum);
        // If totalSum is equal to minSum, it means all elements are negative.
        // In this case, return the maximum subarray sum calculated earlier.
        if(totalsum==minsum){
            return maxsum;
        }
         // Calculate the maximum circular subarray sum
         // If the minimum subarray sum is subtracted from the total sum, the remaining sum represents the maximum subarray sum 
         // that includes circular elements.
        int circularmax=totalsum-minsum; 
        // Return the maximum of non-circular and circular subarray sums
        int result= max(circularmax,maxsum);
        return result; // The final result is the maximum of maximum and minimum subarray sums.
    }
    private:
    int kadane(vector<int>& nums) {
        int n=nums.size();
        int currsum=0;
        int maxsum=INT_MIN;
        for(int i=0;i<n;i++){
            currsum=max(nums[i],currsum+nums[i]);
            maxsum=max(currsum,maxsum);
        }
        return maxsum;
    }
    int kadanenegative(vector<int>& nums,int& totalsum) {
        int n=nums.size();
        int currsum=0;
        int minsum=INT_MAX;
        for(int i=0;i<n;i++){
            currsum=min(nums[i],currsum+nums[i]);
            minsum=min(currsum,minsum);
            totalsum+=nums[i];
        }
        return minsum;
    }
};
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution solution;
    int result = solution.maxSubarraySumCircular(nums);
    cout << "Maximum subarray sum: " << result << endl;
    return 0;
}