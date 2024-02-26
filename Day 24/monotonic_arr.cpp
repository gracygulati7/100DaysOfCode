<<<<<<< HEAD
//! leetcode question 896. Monotonic Array

//? link: https://leetcode.com/problems/monotonic-array/?envType=daily-question&envId=2024-02-17

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int inc = 0, dec = 0, n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] <= nums[i + 1]) inc++;
        }
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] >= nums[i + 1]) dec++;
        }
        return (inc == n - 1 || dec == n - 1);
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of elements in the vector: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    bool result = solution.isMonotonic(nums);
    if (result) {
        cout << "The vector is monotonic." << endl;
    } else {
        cout << "The vector is not monotonic." << endl;
    }
    return 0;
=======
//! leetcode question 896. Monotonic Array

//? link: https://leetcode.com/problems/monotonic-array/?envType=daily-question&envId=2024-02-17

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int inc = 0, dec = 0, n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] <= nums[i + 1]) inc++;
        }
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] >= nums[i + 1]) dec++;
        }
        return (inc == n - 1 || dec == n - 1);
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of elements in the vector: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    bool result = solution.isMonotonic(nums);
    if (result) {
        cout << "The vector is monotonic." << endl;
    } else {
        cout << "The vector is not monotonic." << endl;
    }
    return 0;
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
}