//! richest customer wealth
//* leetcode question no. = 1672 
//? link: https://leetcode.com/problems/richest-customer-wealth/description/

#include <iostream>
#include <vector>
#include<climits>
using namespace std;
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        int m = accounts[0].size();
        int maxsum = INT_MIN;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += accounts[i][j];
            }
            if (sum > maxsum) {
                maxsum = sum;
            }
        }
        return maxsum;
    }
};
int main() {
    int n, m;
    cout << "Enter the number of customers: ";
    cin >> n;
    cout << "Enter the number of banks: ";
    cin >> m;
    vector<vector<int>> accounts(n, vector<int>(m));
    cout << "Enter the account balances for each customer and bank:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Enter balance for customer " << i + 1 << " and bank " << j + 1 << ": ";
            cin >> accounts[i][j];
        }
    }
    Solution solution;
    int maxWealth = solution.maximumWealth(accounts);
    cout << "The maximum wealth among the customers is: " << maxWealth << endl;
    return 0;
}
