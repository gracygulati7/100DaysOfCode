//! leetcode question 347. Top K Frequent Elements

//? link: https://leetcode.com/problems/top-k-frequent-elements/description/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> freq;
        int curr=nums[0], def=1;
        for(int i=1;i<n;i++){
            if(nums[i]==curr){
                def++;
            }
            else{
                freq.push_back(make_pair(def,curr));
                curr=nums[i];
                def=1;
            }
        }
        freq.push_back(make_pair(def,curr));
        sort(freq.rbegin(),freq.rend());
        int i=0; vector<int>res;
        while(i<k){
            res.push_back(freq[i].second);
            i++;
        }
        return res;
    }
};