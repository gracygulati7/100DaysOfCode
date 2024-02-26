<<<<<<< HEAD
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
int main() {
    int n, target;
    cout << "Enter the size of the vector: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the vector elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter the target sum: ";
    cin >> target;
    Solution solution;
    vector<int> result = solution.twoSum(nums, target);
    if(result.size() == 2) {
        cout << "Indices of the two numbers: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
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
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
int main() {
    int n, target;
    cout << "Enter the size of the vector: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the vector elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter the target sum: ";
    cin >> target;
    Solution solution;
    vector<int> result = solution.twoSum(nums, target);
    if(result.size() == 2) {
        cout << "Indices of the two numbers: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }
    return 0;
}

// link for the question:
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://leetcode.com/problems/two-sum/description/