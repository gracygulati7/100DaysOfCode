//! Merge Sorted Arrays
//! Leetcode Question 88

//? link: https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int j=0, i=m; j<n; j++, i++) {
            nums1[i]=nums2[j];
        }
        sort(nums1.begin(), nums1.end());
    }
};

int main() {
    Solution solution;
    int m, n;
    cout << "Enter the size of nums1: ";
    cin >> m;
    cout << "Enter the size of nums2: ";
    cin >> n;
    vector<int> nums1(m + n);
    vector<int> nums2(n);
    cout << "Enter elements for nums1 (sorted): ";
    for (int i = 0; i < m; ++i) {
        cin >> nums1[i];
    }
    cout << "Enter elements for nums2 (sorted): ";
    for (int i = 0; i < n; ++i) {
        cin >> nums2[i];
    }
    solution.merge(nums1, m, nums2, n);
    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
