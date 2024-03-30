//! leetcode question 992. Subarrays with K Different Integers (PROBLEM OF THE DAY 30-3-2024)

//? link: https://leetcode.com/problems/subarrays-with-k-different-integers/description/?envType=daily-question&envId=2024-03-30

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int atmost(vector<int>& nums, int n,int k){
        int count=0; // Used to keep track of the count of valid subarrays.
        int left=0,right=0;
        unordered_map<int,int> mp; // Declaration of a map will be used to keep track of the frequency of elements in the current subarray.
        while(right<n){
            // This block of code checks if the current element nums[right] is already present in the map mp. 
            // If it's not present, it adds it to the map with a frequency of 1. If it's already present, it increments its frequency.
            if(mp.find(nums[right])==mp.end()){
                mp[nums[right]]=1;
            }
            else mp[nums[right]]++;
            // This inner while loop is used to adjust the left pointer and decrease the size of the window if 
            // the number of distinct elements exceeds k. It removes elements from the left end of the window 
            // until the number of distinct elements becomes less than or equal to k.
            while(mp.size()>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            count+=right-left+1; // This line increments the count by the length of the current valid subarray, which is right - left + 1.
            right++; // Incrementing the right pointer to move to the next element in the array.
        }
    return count; 
    }
    //  It calculates the count of subarrays with exactly k distinct elements by subtracting the count of subarrays with 
    // at most k-1 distinct elements from the count of subarrays with at most k distinct elements.
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return atmost(nums,n,k) - atmost(nums,n,k-1);
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,1,2,3};
    cout<<s.subarraysWithKDistinct(nums,2)<<endl;
    return 0;
}