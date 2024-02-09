//! Jump Game
//! Leetcode Question 55:

//? link: https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) { // if there is only one element then its the last one also so problem is solved
            return true;
        }
        int i = 0;
        while (i < n) {
            int temp = nums[i]; // storing jump length in temp
            if (temp == 0 && i != n - 1) { // if jump=0 and index is not last so u cannot jump forward so u r stuck
                int j = i - 1; // if the condition is met, it initializes a variable j to the position one step before the current position 
                // meaning to Check if any previous position can jump over the current zero
                while (j >= 0 && nums[j] <= i - j) {
                    j--;
                }
                // It enters a while loop that iterates as long as j is greater than or equal to zero (j >= 0) and the jump length at 
                // position j is less than or equal to the distance between the current position i and j (nums[j] <= i - j).
                // The loop decrements j until it finds a position that can jump over the zero or until j becomes negative.
                if (j < 0) {
                    return false; // No previous position can jump over the current zero
                }
                i = j; // If a previous position is found, it sets the current position i to the found position j.
            } else {
                i += temp; // If the jump length is non-zero or after handling the zero case, it increments i by the current jump length 
            }
            // If the last index is reached or surpassed, return true
            if (i >= n - 1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    vector<int> nums(size);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> nums[i];
    }
    Solution solution;
    bool result = solution.canJump(nums);
    cout << "Result: " << (result ? "true" : "false") << endl;
    return 0;
}
