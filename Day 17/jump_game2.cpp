//! Jump Game 2
//! leetcode question 45

//? link: https://leetcode.com/problems/jump-game-ii/?envType=study-plan-v2&envId=top-interview-150

//* The logic of this code is to simulate jumping through the array, 
//* updating the maximum reachable index at each step, and making jumps when needed.

//? Example:
/* 
Suppose we have the array nums = [2, 3, 1, 1, 4]. The numbers represent the maximum number of steps that can be taken from that position.
Initialize maxjumps to 0, jumps to 0, and idx to 0.
Loop through the array:
At index 0 (value 2), update maxjumps to max(0, 0 + 2) = 2.
At index 1 (value 3), update maxjumps to max(2, 1 + 3) = 4. Since maxjumps increased, no jump is made yet.
At index 2 (value 1), update maxjumps to max(4, 2 + 1) = 4. No change, continue.
At index 3 (value 1), update maxjumps to max(4, 3 + 1) = 4. No change, continue.
At index 4 (value 4), update maxjumps to max(4, 4 + 4) = 8. Since maxjumps increased, make a jump.
Set idx to maxjumps (i.e., 8).
Increment jumps by 1.
At this point, idx is set to the index where the last jump was made. If the condition if (i == idx) is true in the next iteration, 
it means we have reached the position where the last jump landed, and we need to update idx to the new farthest reachable position (maxjumps). 
This ensures that the next jump is made to the farthest possible location.
This logic continues as we iterate through the array, updating maxjumps and making jumps when needed. 
The final result will be the minimum number of jumps required to reach the end of the array.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0; // if there is only 1 elements so we dont need to make any jump to reach end of array
        if (nums[0] == 0) return -1; // if 1st element is 0 then we cant make any jumps
        int maxjumps = 0, jumps = 0, idx = 0; 
        // maxjumps stores the maximum reachable index from the current position.
        // jumps to 0, representing the number of jumps made, and idx to 0, which will represent= the max index that can be reached by maxjumps
        for (int i = 0; i < n; i++) {
            maxjumps = max(maxjumps, i + nums[i]); // determines the farthest reachable index.
            if (maxjumps >= n - 1) return jumps + 1; 
            // If the maximum reachable index >= the last index of the array, we can reach the end with the jumps made so far returning jumps+1.
            if (i == idx) {
            // Checks if the current index i=idx, which represents the last maximum reached index through last maxjumps.
                idx = maxjumps; // Updates idx to the new maximum reachable index. 
                jumps++; // Increments the jumps counter to track the number of jumps made
            }
        }
        return -1; // If we cannot reach the end of the array, the function returns -1
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    cout << "Enter the elements of the array:" << endl;
    int num;
    while (cin >> num && num != -1) {
        nums.push_back(num);
    }
    int result = solution.jump(nums);
    if (result != -1) {
        cout << "Minimum number of jumps required: " << result << endl;
    } else {
        cout << "It's not possible to reach the end of the array." << endl;
    }
    return 0;
}
