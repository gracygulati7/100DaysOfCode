//! leetcode question 1716. Calculate Money in Leetcode Bank

//? link: https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/?envType=daily-question&envId=2024-02-18

#include <iostream>
using namespace std;
class Solution {
public:
    int totalMoney(int n) {
        // money will represent the total amount of money Hercy has, and week will represent the current week.
        int money = 0;
        int week = 0;
        for (int i = 0; i < n; i++) { // The loop represents each day.
            if (i % 7 == 0) {
                week++;
            } // This condition checks if the current day is the beginning of a new week (Monday). If it is, week is incremented by 1, 
              // indicating the start of a new week.
            money += week + (i % 7); // money is updated by adding the current value of week and the day of the week represented by (i % 7). 
        }
        return money;
    }
};
int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    Solution solution;
    int result = solution.totalMoney(n);
    cout << "Total amount of money Hercy will have after " << n << " days: " << result << endl;
    return 0;
}
