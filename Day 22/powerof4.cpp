//! Leetcode Question 342. Power of Four

//? link: https://leetcode.com/problems/power-of-four/description/?envType=daily-question&envId=2024-02-15

#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int n) {
        for (int i = 0; pow(4, i) <= n; i++) {
            if (pow(4, i) == n) {
                return true;
            }
        }
        return false;
    }
};
// the loop iterates only over powers of 4 <= n. like it will iterate over (4,0)=1 , (4,1)=4 , (4,2)=16 and so on till n.
// then it will check if ny power of 4 = n then it returns true , false otherwise.

int main() {
    Solution solution;
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    bool result = solution.isPowerOfFour(n);
    if (result) {
        cout << n << " is a power of four." << endl;
    } else {
        cout << n << " is not a power of four." << endl;
    }
    return 0;
}
