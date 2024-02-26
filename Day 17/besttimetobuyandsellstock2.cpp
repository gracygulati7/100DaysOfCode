<<<<<<< HEAD
//! best time to buy and sell stock 2
//! leetcode question 122

//? link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150

//* Example 1:
/* Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7. */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        // Initialize the variable 'p' to store the profit
        int p = 0;
        //  Loop through the vector starting from the second day (i=1)
        for (int i = 1; i < n; i++) {
            // Check if the current day's stock price is greater than the previous day
            if (prices[i] > prices[i - 1]) {
                // If true, calculate the difference in prices and add it to the profit
                // this is coz in this ques we can buy and sell stock on same day hence we need to make use for it to maximize the profit.
                p += prices[i] - prices[i - 1];
            }
        }
        return p;
    }
};

int main() {
    int n;
    cout << "Enter the number of days: ";
    cin >> n;
    vector<int> prices(n);
    cout << "Enter the stock prices for each day:\n";
    for (int i = 0; i < n; i++) {
        cout << "Day " << i + 1 << ": ";
        cin >> prices[i];
    }
    Solution sol;
    int result = sol.maxProfit(prices);
    cout << "Maximum profit: " << result << endl;
    return 0;
}
=======
//! best time to buy and sell stock 2
//! leetcode question 122

//? link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150

//* Example 1:
/* Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7. */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        // Initialize the variable 'p' to store the profit
        int p = 0;
        //  Loop through the vector starting from the second day (i=1)
        for (int i = 1; i < n; i++) {
            // Check if the current day's stock price is greater than the previous day
            if (prices[i] > prices[i - 1]) {
                // If true, calculate the difference in prices and add it to the profit
                // this is coz in this ques we can buy and sell stock on same day hence we need to make use for it to maximize the profit.
                p += prices[i] - prices[i - 1];
            }
        }
        return p;
    }
};

int main() {
    int n;
    cout << "Enter the number of days: ";
    cin >> n;
    vector<int> prices(n);
    cout << "Enter the stock prices for each day:\n";
    for (int i = 0; i < n; i++) {
        cout << "Day " << i + 1 << ": ";
        cin >> prices[i];
    }
    Solution sol;
    int result = sol.maxProfit(prices);
    cout << "Maximum profit: " << result << endl;
    return 0;
}
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
