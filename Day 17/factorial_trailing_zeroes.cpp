//! Factorial Trailing Zeroes
//! Leetcode Question 172

//? Link: https://leetcode.com/problems/factorial-trailing-zeroes/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n > 0) {
            count += n / 5;
            n /= 5;
        }
        return count;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int result = solution.trailingZeroes(n);
    cout << "Number of trailing zeroes in " << n << "! is: " << result << endl;
    return 0;
}