<<<<<<< HEAD
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


// link for question:
=======
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


// link for question:
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://practice.geeksforgeeks.org/problems/greater-on-right-side4305/1?page=3&difficulty[]=-1&category[]=Arrays&sortBy=submissions