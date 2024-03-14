//! leeetcode question 930. Binary Subarrays With Sum (PROBLEM OF THE DAY 14-3-2024)

//? link: https://leetcode.com/problems/binary-subarrays-with-sum/description/?envType=daily-question&envId=2024-03-14

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size(); int count=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==goal) count++;
                else if(sum>goal) break;
            }
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int> nums={1,0,1,0,1};
    int goal=2;
    cout<<s.numSubarraysWithSum(nums,goal)<<endl;
    return 0;
}