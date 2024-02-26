<<<<<<< HEAD
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                return i;
            } else if (nums[i] < target) {
                if (i + 1 == n || nums[i + 1] > target) {
                    return i + 1;
                }
            }
        }
        return 0;
    }
};
int main() {
    Solution solution;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int target;
    cout << "Enter the target value: ";
    cin >> target;
    int result = solution.searchInsert(nums, target);
    cout << "Index where target would be inserted: " << result << endl;
    return 0;
}


//link for question:
=======
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                return i;
            } else if (nums[i] < target) {
                if (i + 1 == n || nums[i + 1] > target) {
                    return i + 1;
                }
            }
        }
        return 0;
    }
};
int main() {
    Solution solution;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int target;
    cout << "Enter the target value: ";
    cin >> target;
    int result = solution.searchInsert(nums, target);
    cout << "Index where target would be inserted: " << result << endl;
    return 0;
}


//link for question:
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
//https://leetcode.com/problems/search-insert-position/description/