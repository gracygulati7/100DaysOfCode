#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n - 1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[s] <= nums[mid]) {
                if (nums[s] <= target && target <= nums[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
};
int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array in rotated sorted order: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int target;
    cout << "Enter the target element to search: ";
    cin >> target;
    Solution solution;
    int result = solution.search(nums, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}

// link for question:
// https://leetcode.com/problems/search-in-rotated-sorted-array/