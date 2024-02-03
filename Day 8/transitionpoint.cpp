#include <iostream>
using namespace std;
class Solution {
public:
    int transitionPoint(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                return i;
            }
        }
        return -1;
    }
};
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array (0s and 1s only): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution solution;
    int result = solution.transitionPoint(arr, n);
    if (result != -1) {
        cout << "Transition point found at index: " << result << endl;
    } else {
        cout << "No transition point found." << endl;
    }
    return 0;
}


// link for question:
// https://practice.geeksforgeeks.org/problems/find-transition-point-1587115620/1?page=1&difficulty[]=0&category[]=Arrays&sortBy=submissions