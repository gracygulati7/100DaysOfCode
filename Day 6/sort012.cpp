#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    void sort012(int a[], int n) {
        sort(a, a + n);
    }
};
int main() {
    Solution solution;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[n];
    cout << "Enter " << n << " elements (0, 1, or 2): ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solution.sort012(a, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
