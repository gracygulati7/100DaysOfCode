#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n && j - i <= k; ++j) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};
int main() {
    Solution solution;
    cout << "Enter the elements of the array separated by spaces: ";
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
    }
    cout << "Enter the value of k: ";
    int k;
    cin >> k;
    bool result = solution.containsNearbyDuplicate(nums, k);
    cout << boolalpha << "Output: " << result << endl;
    return 0;
}

// link for question:
// https://leetcode.com/problems/contains-duplicate-ii/description/