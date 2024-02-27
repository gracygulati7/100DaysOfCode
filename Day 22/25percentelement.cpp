//! Leetcode Question 1287. Element Appearing More Than 25% In Sorted Array

//? link: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/?envType=daily-question&envId=2024-02-15

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int percent25 = n / 4; // Calculate 25% of the size of 'arr'.
        for (int i = 0; i < n; ++i) {
            if (arr[i] == arr[i + percent25]) {
                return arr[i];
            }
        }
        return 0;
    }
};

// since the array is sorted means if a number >= 25% in array then that number will be consecutively placed in the array 
// hence this line checks if the current number is present that many times in the array after its current position. 
// Let's break it down with an example:
// If n (the size of the vector) is 12, then percent25 would be 3 (25% of 12).
// In the loop, when i is 0, it checks if arr[0] is equal to arr[0 + 3], which means it checks if the 
// current element = the element located 25% ahead in the vector till 3rd index or even after that.
// if yes, then that particular element is the element that occurs >= 25% times in the array.

int main() {
    Solution solution;
    vector<int> arr;
    arr = {1, 2, 3, 3};
    cout << "Output: " << solution.findSpecialInteger(arr) << endl;
    return 0;
}