//! leetcode question 448. Find All Numbers Disappeared in an Array

//? link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size(); sort(nums.begin(),nums.end());
        vector<int>res;
        for(int i=1;i<=n;i++){
            if(!binary_search(nums.begin(),nums.end(),i)){
                res.push_back(i);
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int>nums={4,3,2,7,8,2,3,1};
    vector<int>res=s.findDisappearedNumbers(nums);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}