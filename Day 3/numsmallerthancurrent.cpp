<<<<<<< HEAD
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && nums[i] > nums[j]) {
                    result[i]++;
                }
            }
        }
        return result;
    }
};
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    vector<int> nums(size);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    Solution solution;
    vector<int> result = solution.smallerNumbersThanCurrent(nums);
    cout << "Resulting vector: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}

// link for the question:
=======
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && nums[i] > nums[j]) {
                    result[i]++;
                }
            }
        }
        return result;
    }
};
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    vector<int> nums(size);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    Solution solution;
    vector<int> result = solution.smallerNumbersThanCurrent(nums);
    cout << "Resulting vector: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}

// link for the question:
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/