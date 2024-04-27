//! Leetcode Question 390. Elimination Game

//? link: https://leetcode.com/problems/elimination-game/description/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastRemaining(int n) {
        // Base case: if there's only one number, return it.
        if (n == 1)
            return 1;

        // Initialize the initial step size and remaining count of numbers.
        int step = 1;
        int remaining = n;
        int leftMost = 1; // The leftmost number in the sequence.

        bool leftToRight = true; // Flag to track the direction of movement.

        // Repeat until there's only one number left.
        while (remaining > 1) {
            // If moving from left to right or remaining count is odd, update leftMost.
            if (leftToRight || remaining % 2 == 1) {
                leftMost += step;
            }
            // Update the step size.
            step *= 2;
            // Update the remaining count (halved after each iteration).
            remaining /= 2;
            // Toggle the direction for the next iteration.
            leftToRight = !leftToRight;
        }

        return leftMost;
    }
};

int main(){
    Solution s;
    cout<<s.lastRemaining(9)<<endl;
    return 0;
}