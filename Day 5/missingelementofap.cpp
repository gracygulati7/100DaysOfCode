#include <iostream>
using namespace std;
class Solution {
public:
    int findMissing(int arr[], int n) {
        int cd = (arr[n - 1] - arr[0]) / n;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] != cd) {
                return arr[i] + cd;
            }
        }
        return 0;
    }
};
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution sol;
    int result = sol.findMissing(arr, n);
    cout << "The missing element in the array is: " << result << endl;
    return 0;
}
