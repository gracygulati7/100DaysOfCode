//! leetcode question 31. Next Permutation

//? link: https://leetcode.com/problems/next-permutation/description/

#include <string>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1; // index that stores the first number which not increase in a ascending order from right to left of array.
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                idx = i - 1; // storing that element in idx  which is the first number which not increase in a ascending order from right to left of array.
                break;
            }
        }
        if (idx != -1) { // if that element is found
        // so now we will start from right to left till that idx & try to find the first number which is larger than idx.
            int minDiff = INT_MAX;
            int swapIdx = -1; // index that stores the first number which is larger than idx element.
            for (int j = n - 1; j > idx; j--) {
                int diff = nums[j] - nums[idx];
                if (diff > 0 && diff < minDiff) {
                    swapIdx = j; // storing that element in swapIdx  which is the first number which is larger than idx element.
                    minDiff = diff;
                }
            }
            swap(nums[idx], nums[swapIdx]); // now we will swap the two elements.
            reverse(nums.begin() + idx + 1, nums.end()); // now we will reverse the array from idx + 1 to the end. 
            // bcoz after swapping the two elements, the first number which is larger than idx element (that was previously present at swapIdx), 
            // will now be present at idx position in array so we reverse array after that element ie from idx+1 position.
        } 
        else {
            reverse(nums.begin(), nums.end()); // if We cant find the number(means array is in decreasing order from left or 
            // all the numbers are increasing in an ascending order from right). 
            // This means this permutation is the last permutation, we need to rotate back to the first permutation. So we reverse the whole array.
        }
    }
};
int main(){
    Solution s;
    vector<int> nums = {2,3,6,5,4,1};
    s.nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}

/*
here is an example:
arr=[2,3,6,5,4,1]
Solution:
Step1, from right to left, find the first number which does not increase in an ascending order. In this case which is 3.
Step2, here we can have two situations:
i) We cannot find the number, all the numbers are increasing in an ascending order or u can say array is in descending order from left. 
This means this permutation is the last permutation, we need to rotate back to the first permutation. So we reverse the whole array, 
for example, 6,5,4,3,2,1 , we turn it to 1,2,3,4,5,6.

ii) We can find the number, then the next step, we will start from right to left till 3 , try to find the first number which is larger than 3, 
in this case it is 4.
Then we swap 3 and 4, the list turn to 2,4,6,5,3,1.
Lastly, we reverse numbers on the right of 4 (exclusive of 4), we finally get 2,4,1,3,5,6.

if there is an array like [3,2,1] which is in descending order so its next permutation will be [1,2,3].
*/