#include <iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int x) {
        if(x > 0) {
            if ((x & (x - 1)) == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};
int main() {
    Solution solution;
    int x;
    cout << "Enter a number: ";
    cin >> x;
    if(solution.isPowerOfTwo(x)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}

// link for question: 
// https://leetcode.com/problems/power-of-two/description/