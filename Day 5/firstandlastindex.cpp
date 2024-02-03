#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int n = nums.size();
        int s = 0, e = n - 1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] == target) {
                result[0] = mid;
                e = mid - 1;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        s = 0, e = n - 1;
        for (int i = n; i >= 0; i--) {
            while (s <= e) {
                int mid = (s + e) / 2;
                if (nums[mid] == target) {
                    result[1] = mid;
                    s = mid + 1;
                } else if (nums[mid] < target) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        return result;
    }
};
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int target;
    cout << "Enter the target element to search: ";
    cin >> target;
    Solution sol;
    vector<int> result = sol.searchRange(nums, target);
    cout << "Result: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}


// link for question:
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/