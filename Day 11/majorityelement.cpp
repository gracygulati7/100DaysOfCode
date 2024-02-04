#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n / 2];
    }
};
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution solution;
    int result = solution.majorityElement(nums);
    cout << "The majority element is: " << result << endl;
    return 0;
}

// link for question:
// https://leetcode.com/problems/majority-element/description/