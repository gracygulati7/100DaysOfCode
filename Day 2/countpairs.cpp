#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] + nums[i] < target) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
int main() {
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    cout << "Enter the elements separated by spaces: ";
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter the target sum: ";
    int target;
    cin >> target;
    Solution solution;
    int result = solution.countPairs(nums, target);
    cout << "Number of pairs with sum less than " << target << ": " << result << endl;
    return 0;
}
