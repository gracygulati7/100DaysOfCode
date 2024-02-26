<<<<<<< HEAD
//! Product of Array except Self
//! LeetcodeQuestion 238

//? link: https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-interview-150

//* Now, let's go through a simple example with nums = [1, 2, 3, 4]:
//* Initialize answer as [1, 1, 1, 1] and left product and right product also as 1 initially.
//* Calculate the product of all elements to the left:
//* For index 0: leftProduct = 1, no change.
//* For index 1: leftProduct = 1 * 1 = 1.
//* For index 2: leftProduct = 1 * 2 = 2.
//* For index 3: leftProduct = 2 * 3 = 6.
//* So, the answer becomes [1, 1, 2, 6] after the first loop.
//* Calculate the product of all elements to the right:
//* For index 3: rightProduct = 1, no change.
///* For index 2: rightProduct = 1 * 4 = 4.
//* For index 1: rightProduct = 4 * 3 = 12.
//* For index 0: rightProduct = 12 * 2 = 24.
//* So, the answer becomes [24, 12, 8, 6] after the second loop.
//* The final result is [24, 12, 8, 6], which is the product of all elements except the one at each index in the original array [1, 2, 3, 4].

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();                                                                            // 1,2,3,4
        vector<int> answer(n, 1); // Initialize answer array with all 1s
        // Calculate the product of all elements to the left of each element
        int leftProduct = 1;
        for (int i = 0; i < n; i++) {
            answer[i] *= leftProduct; // Multiply the running product from the left
            leftProduct *= nums[i];   // Update the running product
        }
        // Calculate the product of all elements to the right of each element
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= rightProduct; // Multiply the running product from the right
            rightProduct *= nums[i];   // Update the running product
        }
        return answer;
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    cout << "Enter the elements of the array (-1 to end input):" << endl;
    int num;
    while (cin >> num && num != -1) {
        nums.push_back(num);
    }
    vector<int> result = solution.productExceptSelf(nums);
    cout << "Resulting array: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}
=======
//! Product of Array except Self
//! LeetcodeQuestion 238

//? link: https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-interview-150

//* Now, let's go through a simple example with nums = [1, 2, 3, 4]:
//* Initialize answer as [1, 1, 1, 1] and left product and right product also as 1 initially.
//* Calculate the product of all elements to the left:
//* For index 0: leftProduct = 1, no change.
//* For index 1: leftProduct = 1 * 1 = 1.
//* For index 2: leftProduct = 1 * 2 = 2.
//* For index 3: leftProduct = 2 * 3 = 6.
//* So, the answer becomes [1, 1, 2, 6] after the first loop.
//* Calculate the product of all elements to the right:
//* For index 3: rightProduct = 1, no change.
///* For index 2: rightProduct = 1 * 4 = 4.
//* For index 1: rightProduct = 4 * 3 = 12.
//* For index 0: rightProduct = 12 * 2 = 24.
//* So, the answer becomes [24, 12, 8, 6] after the second loop.
//* The final result is [24, 12, 8, 6], which is the product of all elements except the one at each index in the original array [1, 2, 3, 4].

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();                                                                            // 1,2,3,4
        vector<int> answer(n, 1); // Initialize answer array with all 1s
        // Calculate the product of all elements to the left of each element
        int leftProduct = 1;
        for (int i = 0; i < n; i++) {
            answer[i] *= leftProduct; // Multiply the running product from the left
            leftProduct *= nums[i];   // Update the running product
        }
        // Calculate the product of all elements to the right of each element
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= rightProduct; // Multiply the running product from the right
            rightProduct *= nums[i];   // Update the running product
        }
        return answer;
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    cout << "Enter the elements of the array (-1 to end input):" << endl;
    int num;
    while (cin >> num && num != -1) {
        nums.push_back(num);
    }
    vector<int> result = solution.productExceptSelf(nums);
    cout << "Resulting array: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
