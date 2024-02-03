#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
int main() {
    cout << "Enter the number of elements in the vector: ";
    int n;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int val;
    cout << "Enter the value to be removed: ";
    cin >> val;
    Solution solution;
    int result = solution.removeElement(nums, val);
    cout << "Modified vector: ";
    for (int i = 0; i < result; i++) {
        cout << nums[i] << " ";
    }
    cout << "\nNew length: " << result << endl;
    return 0;
}

// link for the question:
// https://leetcode.com/problems/remove-element/description/