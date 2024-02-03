#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int costprice = prices[0]; 
        int profit = 0;
        for (int i = 1; i < n; i++) {
            costprice = min(costprice, prices[i]); // cp should be as min as possible
            profit = max(profit, prices[i] - costprice); // profit = sp - cp
            // sp or profit should be as max as possible
        }
        return profit;
    }
};
int main() {
    int n;
    cout << "Enter the number of days: ";
    cin >> n;
    vector<int> prices(n);
    cout << "Enter the prices for each day:\n";
    for (int i = 0; i < n; i++) {
        cout << "Day " << i + 1 << ": ";
        cin >> prices[i];
    }
    Solution obj;
    int result = obj.maxProfit(prices);
    cout << "Maximum profit: " << result << endl;
    return 0;
}


// link for question:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/