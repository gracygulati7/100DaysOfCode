//! leetcode question 1846. Maximum Element After Decreasing and Rearranging

//? link: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/description/?envType=daily-question&envId=2024-04-01

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        arr[0]=1; // Ensure the first element is 1

        // Iterate through the array to satisfy the condition
        for(int i=1;i<n;i++){
            // Ensure the absolute difference between adjacent elements is at most 1
            arr[i]=min(arr[i],arr[i-1]+1);
        }
        return arr[n-1]; // The maximum possible value of an element in arr will be its last element as array is sorted.
    }
};
int main(){
    Solution s;
    vector<int> arr={3,6,9,1};
    cout<<s.maximumElementAfterDecrementingAndRearranging(arr)<<endl;
    return 0;
}