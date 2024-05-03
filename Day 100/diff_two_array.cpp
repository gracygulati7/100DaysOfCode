//! Leetcode Question 2215. Find the Difference of Two Arrays

//? link: https://leetcode.com/problems/find-the-difference-of-two-arrays/?envType=study-plan-v2&envId=leetcode-75

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer(2); vector<int> res; vector<int> ans;
        for(int i=0;i<nums1.size();i++){ // Loop through nums1 to find elements not present in nums2
            bool found=false;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    found=true; break;     
                }
            }
            // Only add the element to res if it's not found and not already in res
            if (!found && find(res.begin(), res.end(), nums1[i]) == res.end()) { 
                res.push_back(nums1[i]);
            }
        }
        for(int i=0;i<nums2.size();i++){ // Loop through nums2 to find elements not present in nums1
            bool found=false;
            for(int j=0;j<nums1.size();j++){
                if(nums2[i]==nums1[j]){
                    found=true; break;     
                }
            }
            // Only add the element to ans if it's not found and not already in ans
            if (!found && find(ans.begin(), ans.end(), nums2[i]) == ans.end()) {
                ans.push_back(nums2[i]);
            }
        }     
        answer[0]=res, answer[1]=ans;
        return answer;
    }
};
int main(){
    Solution s;
    vector<int> nums1={1,2,3,3};
    vector<int> nums2={1,1,2,2};
    vector<vector<int>> answer=s.findDifference(nums1,nums2);
    for(int i=0;i<answer.size();i++){
        for(int j=0;j<answer[i].size();j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}