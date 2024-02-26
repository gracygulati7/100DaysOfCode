//! leetcode question 283. Move Zeroes

//? link: https://leetcode.com/problems/move-zeroes/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                for(int j=i+1;j<n;j++){
                    if(nums[j]!=0){
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
            }
        }
    }
};
int main(){
    Solution s;
    vector<int> nums={0,1,0,3,12};
    s.moveZeroes(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}