<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};
int main() {
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    cout << "Enter the elements separated by spaces: ";
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution solution;
    bool result = solution.containsDuplicate(nums);
    if (result) {
        cout << "The array contains duplicate elements." << endl;
    } else {
        cout << "The array does not contain duplicate elements." << endl;
    }
    return 0;
}

//link for question: 
=======
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};
int main() {
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    cout << "Enter the elements separated by spaces: ";
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution solution;
    bool result = solution.containsDuplicate(nums);
    if (result) {
        cout << "The array contains duplicate elements." << endl;
    } else {
        cout << "The array does not contain duplicate elements." << endl;
    }
    return 0;
}

//link for question: 
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://leetcode.com/problems/contains-duplicate/description/