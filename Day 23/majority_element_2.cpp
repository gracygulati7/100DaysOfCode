//! LeetCode Question 229. Majority Element II

//? link: https://leetcode.com/problems/majority-element-ii/description/?envType=daily-question&envId=2024-02-16

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> major;
        int count = 1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                count++;
            } else {
                count = 1; // Reset count when a different element is encountered
            }
            if (count > (n / 3) && find(major.begin(), major.end(), nums[i]) == major.end()) {
                major.push_back(nums[i]);
            }
            // count > n / 3: This part checks if the count of the current element (nums[i]) > ⌊ n/3 ⌋. 
            // The condition is checking if the count of the element > one-third of the total number of elements in the array.
            // find(major.begin(), major.end(), nums[i]) == major.end(): This part checks if the current element (nums[i]) is 
            //not already present in the major vector. find is a function that searches for the first occurrence of the given value 
            // in the specified range (major.begin() to major.end()). If the element is not found (== major.end()), 
            // it means the element is not present in the vector.
            // If both conditions are true, it means that the current element appears > one-third of the time in the array (count > n / 3), 
            // and it is not already in the major vector. In this case, the element is added to the major vector using major.push_back(nums[i]).
            // This ensures that the major vector contains unique elements that appear > one-third of the time in the array.
        }
        // Check the last element separately
        if (count > (n / 3) && find(major.begin(), major.end(), nums.back()) == major.end()) {
            major.push_back(nums.back());
        }
        return major;
    }
};

int main() {
    vector<int> nums;
    nums = {3, 2, 3};
    Solution solution1;
    vector<int> result1 = solution1.majorityElement(nums);
    cout << "Output for [3,2,3]: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;
    nums = {1};
    Solution solution2;
    vector<int> result2 = solution2.majorityElement(nums);
    cout << "Output for [1]: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;
    nums = {1, 2};
    Solution solution3;
    vector<int> result3 = solution3.majorityElement(nums);
    cout << "Output for [1,2]: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
