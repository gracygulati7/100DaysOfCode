//! leetcode question 1464. Maximum Product of Two Elements in an Array

//? link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/?envType=daily-question&envId=2024-02-20

#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = INT_MIN;
        for (int i = 0; i < n; i++) {
            int maxI = nums[i] - 1;
            for (int j = i + 1; j < n; j++) {
                int maxJ = nums[j] - 1;
                int product = maxI * maxJ;
                if (product > maxProduct) {
                    maxProduct = product;
                }
            }
        }
        return maxProduct;
    }
};
