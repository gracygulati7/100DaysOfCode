<<<<<<< HEAD
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);
        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }
        return ans;
    }
};
int main() {
    cout << "Enter the number of elements in the vector: ";
    int size;
    cin >> size;
    vector<int> nums(size);
    cout << "Enter the elements of the vector, separated by space:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    Solution solution;
    vector<int> concatenated = solution.getConcatenation(nums);
    cout << "Concatenated Vector: ";
    for (int i = 0; i < concatenated.size(); i++) {
        cout << concatenated[i] << " ";
    }
    return 0;
}

//link for question:
=======
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);
        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }
        return ans;
    }
};
int main() {
    cout << "Enter the number of elements in the vector: ";
    int size;
    cin >> size;
    vector<int> nums(size);
    cout << "Enter the elements of the vector, separated by space:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    Solution solution;
    vector<int> concatenated = solution.getConcatenation(nums);
    cout << "Concatenated Vector: ";
    for (int i = 0; i < concatenated.size(); i++) {
        cout << concatenated[i] << " ";
    }
    return 0;
}

//link for question:
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://leetcode.com/problems/concatenation-of-array/description/