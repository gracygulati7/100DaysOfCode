#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    vector<int> nums(size);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    Solution solution;
    int result = solution.removeDuplicates(nums);
    cout << "The array after removing duplicates is:\n";
    for (int i = 0; i < result; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}

// link for question:
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/