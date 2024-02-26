//! leetcode question 739
//! Daily Temperatures

//? link: https://leetcode.com/problems/daily-temperatures/description/?envType=daily-question&envId=2024-01-31

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        int nextWarmer[n];  // To store the index of the next warmer day
        nextWarmer[n - 1] = n;  // Initialize the last element to be beyond the array
        for (int i = n - 2; i >= 0; i--) {
            int j = i + 1;
            while (j < n && temperatures[j] <= temperatures[i]) {
                // Jump to the next warmer day using the information from nextWarmer array
                j = nextWarmer[j];
            }
            nextWarmer[i] = (j < n) ? j : n;  // Store the index of the next warmer day or beyond the array
            if (j < n) {
                answer[i] = j - i;
            }
        }
        return answer;
    }
};

int main() {
    int n;
    cout << "Enter the number of temperatures: ";
    cin >> n;
    vector<int> temperatures(n);
    cout << "Enter the temperatures: ";
    for (int i = 0; i < n; i++) {
        cin >> temperatures[i];
    }
    Solution sol;
    vector<int> result = sol.dailyTemperatures(temperatures);
    cout << "Result: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    return 0;
}
