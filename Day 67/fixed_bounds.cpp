//! leetcode question 2444. Count Subarrays With Fixed Bounds (PROBLEM OF THE DAY 31-3-2024)

//? link: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/?envType=daily-question&envId=2024-03-31

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size(); long res=0;
        
        bool mini=false, maxi=false; // These variables are used to keep track of the current state while iterating through the array. 
        // mini and maxi are flags indicating if the minimum and maximum values have been found within the current subarray

        int start=0, minst=0, maxst=0; // start, minst, and maxst are indices used to mark the starting point and the indices 
        // where the minimum and maximum values were found within the current subarray.

        for(int i=0;i<n;i++){
            int curr=nums[i];
            // If the current element curr < minK or > maxK, it means that the current subarray cannot satisfy the conditions. 
            // So, mini and maxi are set to false, indicating that the minimum and maximum values haven't been found within current subarray. 
            // start is updated to i + 1, marking the start of a new potential subarray.
            if(curr<minK || curr>maxK){
                mini=false;
                maxi=false;
                start=i+1;
            }
            // If the current element curr is equal to minK, it means that the minimum value condition is satisfied within current subarray. 
            // So, mini is set to true, and minst is updated to the index i where the minimum value was found.
            if(curr==minK){
                mini=true;
                minst=i;
            }
            // Similarly, if the current element curr = maxK, it means that the maximum value condition is satisfied within current subarray. 
            // So, maxi is set to true, and maxst is updated to the index i where the maximum value was found.
            if(curr==maxK){
                maxi=true;
                maxst=i;
            }
            // If both mini and maxi are true, it means that the current subarray satisfies both the minimum and maximum value conditions. 
            // So, count of such subarrays is incremented by (min(minst, maxst) - start + 1), which represents length of current valid subarray.
            if(mini && maxi){
                res+=min(minst,maxst)-start+1;
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,3,5,2,7,5};
    cout<<s.countSubarrays(nums,1,5)<<endl;
    return 0;
}