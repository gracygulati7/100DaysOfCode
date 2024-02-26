#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        std::rotate(nums.begin(), nums.begin() + n - k, nums.end());
    }
};
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    Solution obj;
    obj.rotate(nums, k);
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    return 0;
}


// link for question:
// https://leetcode.com/problems/rotate-array/description/