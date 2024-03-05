//! leetcode question 78. Subsets

//? link: https://leetcode.com/problems/subsets/description/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size(); vector<vector<int>> ans;
        for(int i=0;i<(1<<n);i++){
            vector<int> subsets;
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    subsets.push_back(nums[j]);
                }
            }
            ans.push_back(subsets);
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3};
    vector<vector<int>> ans=s.subsets(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}