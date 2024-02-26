<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int x = nums[n - k];
        return x;
    }
};
int main() {
    int n, k;
    cout << "Enter the size of the vector: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the vector:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;
    Solution obj;
    int result = obj.findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << result << endl;
    return 0;
}


// link for question:
=======
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int x = nums[n - k];
        return x;
    }
};
int main() {
    int n, k;
    cout << "Enter the size of the vector: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the vector:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;
    Solution obj;
    int result = obj.findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << result << endl;
    return 0;
}


// link for question:
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/