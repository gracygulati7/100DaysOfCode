#include <iostream>
using namespace std;
class Solution {
public:
    void nextGreatest(int arr[], int n) {
        int temp1 = -1;
        for (int i = n - 1; i >= 0; i--) {
            int temp2 = arr[i];
            arr[i] = temp1;
            temp1 = max(temp1, temp2);
        }
    }
};
int main() {
    Solution solution;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solution.nextGreatest(arr, n);
    cout << "Array after replacing with next greatest elements:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
