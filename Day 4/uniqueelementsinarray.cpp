#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int i = 0;
        sort(arr.begin(), arr.end());
        vector<int> ans;
        while (i < arr.size()) {
            int count = 1;
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[i] == arr[j]) {
                    count++;
                } else {
                    break;
                }
            }
            ans.push_back(count);
            i = i + count;
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size() - 1; i++) {
            if (ans[i] == ans[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
int main() {
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    vector<int> arr(size);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    Solution solution;
    bool result = solution.uniqueOccurrences(arr);
    if (result) {
        cout << "The occurrences are unique.\n";
    } else {
        cout << "The occurrences are not unique.\n";
    }
    return 0;
}

// link for question:
// https://leetcode.com/problems/unique-number-of-occurrences/description/