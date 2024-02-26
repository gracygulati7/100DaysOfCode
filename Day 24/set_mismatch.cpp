<<<<<<< HEAD
//! leetcode question 645. Set Mismatch

//? link: https://leetcode.com/problems/set-mismatch/description/?envType=daily-question&envId=2024-02-17

#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                // Found the duplicate
                res.push_back(nums[i]);
                // Find the missing number
                for (int j = 1; j <= n; j++) {
                    if (std::find(nums.begin(), nums.end(), j) == nums.end()) {
                        res.push_back(j);
                        break;
                    }
                }
                return res;
            }
        }
        // If no duplicate is found, something unexpected happened
        return res;
    }
};
=======
//! leetcode question 645. Set Mismatch

//? link: https://leetcode.com/problems/set-mismatch/description/?envType=daily-question&envId=2024-02-17

#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                // Found the duplicate
                res.push_back(nums[i]);
                // Find the missing number
                for (int j = 1; j <= n; j++) {
                    if (std::find(nums.begin(), nums.end(), j) == nums.end()) {
                        res.push_back(j);
                        break;
                    }
                }
                return res;
            }
        }
        // If no duplicate is found, something unexpected happened
        return res;
    }
};
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
