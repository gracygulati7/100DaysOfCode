//! leetcode question 46. Permutations

//? link: https://leetcode.com/problems/permutations/description/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
// The per function is the core of the permutation generation. It takes the vector nums, the current position start, and the result vector.
        vector<vector<int>> result;
        per(nums,0,result);
        return result;
    }
private:
    void per(vector<int>& nums,int start,vector<vector<int>>& result){
//  it checks if the start index is at the last index of the array (nums.size() - 1). If so, it means we have reached the end of a permutation, 
//  so it adds the current permutation to the result vector.
        if(start==nums.size()-1){
            result.push_back(nums);
            return;
        }
// If start is not at the last index, it enters a loop that iterates over the elements to the right of the current position (start). 
// It swaps the current element with each element to its right, effectively trying out different elements at the current position.
// After swapping, it makes a recursive call to per to generate permutations for the next position (start + 1).
// After the recursive call, it backtracks by swapping the elements back to their original positions. This is crucial for exploring 
// all possible permutations and not missing any.
        for(int i=start;i<nums.size();i++){
            swap(nums[start],nums[i]);
            per(nums,start+1,result);
            swap(nums[start],nums[i]); // The backtracking ensures that the original order is restored after each recursive call.
        }
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3};
    vector<vector<int>> result=s.permute(nums);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}