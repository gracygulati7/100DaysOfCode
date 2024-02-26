#include<iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = INT_MIN;  
        int currsum = 0;      
        for (int i = 0; i < n; i++) {
            currsum = max(nums[i], currsum + nums[i]);
            maxsum = max(currsum, maxsum);
        }
        return maxsum; 
    }
};
int main() {
    cout << "Enter the elements of the array separated by spaces: ";
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
    }
    Solution solution;
    int result = solution.maxSubArray(nums);
    cout << "Maximum Subarray Sum: " << result << endl;
    return 0;
}

// link for the question:
// https://leetcode.com/problems/maximum-subarray/description/