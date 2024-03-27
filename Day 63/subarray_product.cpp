//! leetcode question 713. Subarray Product Less Than K (PROBLEM OF THE DAY 27-3-2024)

//? link: https://leetcode.com/problems/subarray-product-less-than-k/description/?envType=daily-question&envId=2024-03-27

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size(), count=0;
        for(int i=0;i<n;i++){
            int product=1;
            for(int j=i;j<n;j++){
                product*=nums[j];
                if(product<k){
                    count++;
                }
                else break;
            }
        }
        return count;
    }
};
int main(){
    Solution s;
    vector<int> nums={10,5,2,6};
    cout<<s.numSubarrayProductLessThanK(nums, 100)<<endl;
    return 0;
}