//! Plus One
//! Leetcode Question 66

//? link: https://leetcode.com/problems/plus-one/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            digits[i] = digits[i] + 1;
            // If there is no carrying, return the result
            if (digits[i] <= 9) {
                return digits;
            } else {
                digits[i] = 0;
            }
        }
        // If we are here, it means there is a carry in the most significant digit
        // Add a new digit with value 1 at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution solution;
    vector<int> input;
    cout << "Enter the elements of the array (enter -1 to end input):" << endl;
    int num;
    while (cin >> num && num != -1) {
        input.push_back(num);
    }
    vector<int> result = solution.plusOne(input);
    cout << "Result after incrementing by one:" << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
