//! Contiguous Array (LeetCode 525) PROBLEM OF THE DAY 16-3-2024

//? Link: https://leetcode.com/problems/contiguous-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(); int maxlen=0,sum=0;
        vector<int> arr(2*nums.size()+1,INT_MIN);
        arr[nums.size()]=-1;
        for(int i=0;i<n;i++){
            sum+= nums[i]==0?-1:1;
            if(arr[sum+nums.size()]>=-1){
                maxlen=max(maxlen,i-arr[sum+nums.size()]);
            }
            else arr[sum+nums.size()]=i;
        }
        return maxlen;
    }
};
int main(){
    Solution obj;
    vector<int> nums={1,0,1,0,1,0,1,1,1,1,0};
    cout<<obj.findMaxLength(nums)<<endl;
    return 0;
}

/*
* LOGIC :
We use a variable sum, which is used to store the relative number of ones and zeros encountered so far.
sum is incremented by one whenever a 1 is encountered and decremented by one whenever a 0 is encountered.
We traverse the array nums from the beginning.
If at any index, sum becomes zero, it means that we've encountered equal number of zeros and ones from the beginning till the current index.
And at any index, we encounter a sum that's already been encountered at some previous index, 
it means that the number of 0's and 1's are equal between the indices corresponding to the equal sum values.
We keep track of the indices that correspond to the same sum with maximum difference between the indices to find 
the maximum length of the subarrays with equal number of 0's & 1's.
Now, sum can range between -n (When all elements are zeros) to +n (When all elements are ones).
Thus, we make use of an array arr of size 2n+1 to keep a track of the all values of sum encountered so far.
We make an entry containing the current element's index in the arrarr for a new sum encountered everytime.
Whenever, we encounter the same sum again, we determine the length of the subarray lying between the indices 
corresponding to the same sum values.
*/