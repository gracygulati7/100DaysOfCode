//! leetcode question 2706. Buy Two Chocolates

//? link: https://leetcode.com/problems/buy-two-chocolates/description/?envType=daily-question&envId=2024-02-18

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        int minsum = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = prices[i] + prices[j];
                if (sum < minsum) {
                    minsum = sum;
                }
            }
        }
        if (money >= minsum) {
            money -= minsum;
        }
        return money;
    }
};

int main() {
    int n;
    cout << "Enter the number of chocolates: ";
    cin >> n;
    vector<int> prices(n);
    cout << "Enter the prices of chocolates: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    int money;
    cout << "Enter your initial amount of money: ";
    cin >> money;
    Solution solution;
    int leftoverMoney = solution.buyChoco(prices, money);
    cout << "The amount of money you will have leftover after buying two chocolates is: " << leftoverMoney << endl;
    return 0;
}
