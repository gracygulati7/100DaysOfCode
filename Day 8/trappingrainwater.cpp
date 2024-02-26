#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxleft(n, 0);
        vector<int> maxright(n, 0);
        int sum = 0;
        if (n <= 2) {
            return 0;
        }
        maxleft[0] = height[0];
        for (int i = 1; i < n; i++) {
            maxleft[i] = max(height[i], maxleft[i - 1]);
        }
        maxright[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxright[i] = max(height[i], maxright[i + 1]);
        }
        for (int i = 0; i < n; i++) {
            int water = min(maxleft[i], maxright[i]);
            int trap = max(0, water - height[i]);
            sum += trap;
        }
        return sum;
    }
};
int main() {
    int n;
    cout << "Enter the number of elements in the height vector: ";
    cin >> n;
    vector<int> height(n);
    cout << "Enter the height values: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    Solution solution;
    int result = solution.trap(height);
    cout << "The trapped water amount is: " << result << endl;
    return 0;
}


// link for question:
// https://leetcode.com/problems/trapping-rain-water/description/