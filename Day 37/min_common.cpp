//! leetcode question 2540. Minimum Common Value

//? link: https://leetcode.com/problems/minimum-common-value/description/

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int findCommonMin(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return -1; 
    }
};
int main(){
    Solution s;
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {6,7,8,9,10};
    cout << s.findCommonMin(nums1, nums2) << endl;
    return 0;
}
