//! find minimum in rotated sorted array
//! leetcode question 153

//? link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(nums[i], mini);
        }
        return mini;
    }
};

int main() {
    Solution solution;
    int size;
    cout << "Enter the size of the vector: ";
    cin >> size;
    vector<int> nums(size);
    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    int result = solution.findMin(nums);
    cout << "The minimum element in the vector is: " << result << endl;
    return 0;
}
