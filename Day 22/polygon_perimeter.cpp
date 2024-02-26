//! Leetcode Question 2971. Find Polygon With the Largest Perimeter
//! Problem of the Day 15-02-2024

//? link: https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/?envType=daily-question&envId=2024-02-15

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 3) { // no closed polygon can be formed with less than 3 sides
            return -1;
        }
        long long peri = 0 , sum = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < sum) { // if sum of all sides > longest side , only then can a closed polygon be formed
                peri = nums[i] + sum;
            }
            // when we encounter that longest side which is less than sum of all previous sides means polygon can be formed so we add 
            // that side to sum of all previous sides resulting in perimeter of that polygon so formed.
            sum += nums[i]; // till nums[i]>sum, add all nums[i] to sum which will contain sum of all sides.
        }
        return (peri == 0) ? -1 : peri; // returning the final perimeter of polygon so formed.
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    long long int result = solution.largestPerimeter(nums);
    cout << "Largest Perimeter: " << result << endl;
    return 0;
}
