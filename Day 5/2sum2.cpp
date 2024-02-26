<<<<<<< HEAD
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int s = 0, e = n - 1;
        while (s < e) {
            int sum = numbers[s] + numbers[e];
            if (sum == target) {
                return {s + 1, e + 1};
            } else if (sum < target) {
                s++;
            } else {
                e--;
            }
        }
        return {};
    }
};
int main() {
    vector<int> numbers;
    int n, target, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        numbers.push_back(num);
    }
    cin >> target;
    Solution solution;
    vector<int> result = solution.twoSum(numbers, target);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}


// link for question:
=======
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int s = 0, e = n - 1;
        while (s < e) {
            int sum = numbers[s] + numbers[e];
            if (sum == target) {
                return {s + 1, e + 1};
            } else if (sum < target) {
                s++;
            } else {
                e--;
            }
        }
        return {};
    }
};
int main() {
    vector<int> numbers;
    int n, target, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        numbers.push_back(num);
    }
    cin >> target;
    Solution solution;
    vector<int> result = solution.twoSum(numbers, target);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}


// link for question:
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/