//! Leetcode Question 2441. Largest Positive Integer That Exists With Its Negative (POTD 2-5-2024)

//? link: https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/?envType=daily-question&envId=2024-05-02

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<int> ans; // Create an empty vector to store the valid values of k

        for(int i=0;i<nums.size();i++){ // Loop through each element in the nums array
            int temp=nums[i]; // Store the current element in temp

            for(int j=i+1;j<nums.size();j++){ // Loop through the elements after the current element

                if(temp==-nums[j]){ // If the negative of the current element exists later in the array
                    ans.push_back(abs(temp)); // then Add the absolute value of the current element to ans
                    break; // Break the inner loop once we find a match
                }
            }
        }
        if(ans.empty()) return -1; // If no valid k was found

        int maxi=ans[0];  // Initialize maxi with the first element of ans
        
        for(int i=1;i<ans.size();i++){ // Loop through the elements of ans starting from the second element
            if(ans[i]>maxi){ // If the current element is greater than maxi
                maxi=ans[i]; // then Update maxi with the current element
            }
        }
        return maxi; // Return the maximum valid value of k
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3,4,5};
    cout<<s.findMaxK(nums)<<endl;
    return 0;
}