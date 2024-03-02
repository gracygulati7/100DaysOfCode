//! leetcode quesion 977. Squares of a Sorted Array
//! PROBLEM OF THE DAY 2-3-2024

//? link: https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=daily-question&envId=2024-03-02

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> sq;
        for(int i=0;i<n;i++){
            int s=nums[i]*nums[i];
            sq.push_back(s);
        }
        sort(sq.begin(),sq.end());
        return sq;
    }
};
int main(){
    Solution s;
    vector<int> nums={-4,-1,0,3,10};
    vector<int> ans=s.sortedSquares(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}