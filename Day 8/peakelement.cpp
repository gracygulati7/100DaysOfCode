#include <iostream>
#include <climits>
using namespace std;
class Solution {
public:
    int peakElement(int arr[], int n) {
        int maxn = INT_MIN;
        int temp = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > maxn) {
                maxn = arr[i];
                temp = i;
            }
        }
        return temp;
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
    Solution solution;
    int result = solution.peakElement(arr, n);
    cout << "Peak element is at index: " << result << endl;
    return 0;
}
