//! leetcode question 349. Intersection of Two Arrays (PROBLEM OF THE DAY 10-3-2024)

//? link: https://leetcode.com/problems/intersection-of-two-arrays/description/?envType=daily-question&envId=2024-03-10

#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> res;
        int n=nums1.size(), m=nums2.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    res.insert(nums1[i]);
                }
            }
        }
        vector<int> v(res.begin(),res.end());
        return v;
    }
};
int main(){
    Solution s;
    vector<int> v1={1,2,2,1};
    vector<int> v2={2,2};
    vector<int> res=s.intersection(v1,v2);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}