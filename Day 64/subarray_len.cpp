//! leetcode question 2958. Length of Longest Subarray With at Most K Frequency (PROBLEM OF THE DAY 28-3-2024)

//? link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2024-03-28

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size(); 
        unordered_map<int,int> freq; // Using an unordered_map to store the frequency of elements
        int st=0,end=0,ans=0; // Initializing variables for start index, end index, and the maximum length of the good subarray
        for(int i=0;i<n;i++){
            freq[nums[i]]++; // Incrementing the frequency of the current number in the unordered_map
            while(st<i && freq[nums[i]]>k){
                freq[nums[st]]--; // Decrementing the frequency of the number at start index st when freq of element is > k
                if(freq[nums[st]]==0){
                    freq.erase(nums[st]); // Removing the number from the unordered_map if its frequency becomes zero
                }
                st++; // Incrementing the start index to shrink the window
            }
            ans=max(ans,i-st+1); // Updating the maximum length of the good subarray
        }
    return ans; // Returning the maximum length of the good subarray
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3,1,2,3,1,2};
    int k=3;
    cout<<s.maxSubarrayLength(nums,k)<<endl;
    return 0;
}
