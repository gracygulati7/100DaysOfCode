<<<<<<< HEAD
//! Factorial Trailing Zeroes
//! Leetcode Question 172

//? Link: https://leetcode.com/problems/factorial-trailing-zeroes/description/?envType=study-plan-v2&envId=top-interview-150

//* LOGIC : 
//* The logic is based on the observation that for each multiple of 5 in the factorial, there will be one trailing zero. 
//* This is why we count the multiples of 5 in the loop.

#include <iostream>
using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n > 0) { // The while loop continues until the value of n becomes 0, at which point the loop exits.
            count += n / 5; // In each iteration, the value of count is incremented by the result n/5.
            // This operation effectively calculates the number of multiples of 5 in the current value of n and adds it to the count.
            n /= 5; // After updating the count, the value of n is divided by 5. 
            // This step is taken because, when calculating trailing zeroes in a factorial, multiples of 5 contribute to 
            // the number of trailing zeroes. By dividing n by 5, we effectively remove one factor of 5 from n.
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
=======
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
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
