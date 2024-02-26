<<<<<<< HEAD
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
=======
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
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://leetcode.com/problems/power-of-two/description/