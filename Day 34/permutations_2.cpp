//! leetcode question 47. Permutations II

//? link: https://leetcode.com/problems/permutations-ii/description/

#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
        set<int> s; // a set is created to keep track of unique elements encountered so far. 
// The loop iterates over the elements to the right of the current position (start). If an element has already been seen (present in the set s),
// it skips the current iteration to avoid duplicates.
// If the element is not in the set, it is added to the set, and the current element is swapped with the element at the current position (start)
// This is done to try out different elements at the current position.
// After swapping, a recursive call to per is made to generate permutations for the next position (start + 1).
// After the recursive call, the elements are swapped back to their original positions to backtrack and explore other possibilities.
        for(int i=start;i<nums.size();i++){
            if(s.count(nums[i])==1){
                continue;
            }
            s.insert(nums[i]);
            swap(nums[start],nums[i]);
            per(nums,start+1,result);
            swap(nums[start],nums[i]); // The backtracking ensures that the original order is restored after each recursive call.
        }
    }
};
int main(){
    Solution s;
    vector<int> nums={1,1,2};
    vector<vector<int>> result=s.permuteUnique(nums);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}