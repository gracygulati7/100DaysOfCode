#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int n = hours.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (hours[i] >= target) {
                count++;
            }
        }
        return count;
    }
};
int main() {
    cout << "Enter the number of employees: ";
    int n;
    cin >> n;
    cout << "Enter the hours worked by each employee separated by spaces: ";
    vector<int> hours(n);
    for (int i = 0; i < n; i++) {
        cin >> hours[i];
    }
    cout << "Enter the target hours: ";
    int target;
    cin >> target;
    Solution solution;
    int result = solution.numberOfEmployeesWhoMetTarget(hours, target);
    cout << "Number of employees who met or exceeded the target: " << result << endl;
    return 0;
}
