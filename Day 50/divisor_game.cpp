//! leetcode question 1025. Divisor Game

//? link: https://leetcode.com/problems/divisor-game/description/

#include <iostream>
using namespace std;
class Solution {
public:
    bool divisorGame(int n) {
        // Assuming Alice starts the game, we can represent even and odd numbers as win for Alice and Bob, respectively.
        // Since Alice starts, if the number is even, she can always choose 1 (n = n - 1), making the number odd and passing it to Bob.
        // If the number is odd, there's no way to make a move, hence Bob wins.
        return n % 2 == 0;
    }
};

int main()
 {
    Solution s;
    cout << s.divisorGame(10) << endl;
    return 0;
 }