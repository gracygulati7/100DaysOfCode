#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for (int i = 0; i <= n; i++) {
            result ^= i;
        }
        for (int i = 0; i < n; i++) {
            result ^= nums[i];
        }
        return result;
    }
};
int main() {
    Solution solution;
    int size;
    cout << "Enter the size of the vector: ";
    cin >> size;
    vector<int> nums(size);
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    int missingNumber = solution.missingNumber(nums);
    cout << "Missing Number: " << missingNumber << endl;
    return 0;
}


// link for question:
// https://leetcode.com/problems/missing-number/description/