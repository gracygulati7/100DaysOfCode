//! leetcode question 1920. Build Array from Permutation

//? link: https://leetcode.com/problems/build-array-from-permutation/description/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=nums[nums[i]];
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3};
    vector<int> ans=s.buildArray(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
