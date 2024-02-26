//! median of two sorted arrays
//! leetcode question 4

//? link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/?envType=study-plan-v2&envId=top-interview-150

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median; int m=nums1.size(); int n=nums2.size();
        vector<int> result; 
        int i=0,j=0, totalsize=n+m;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                result.push_back(nums1[i]); i++;
            }
            else{
                result.push_back(nums2[j]); j++;
            }
        }
        while(i<m){
            result.push_back(nums1[i]); i++;
        }
        while(j<n){
            result.push_back(nums2[j]); j++;
        }
        if(totalsize%2!=0){
            return result[(totalsize-1)/2];
        }
        else{
            int mid=totalsize/2;
            return (result[mid-1] + result[mid]) / 2.0;
        }
    }
};