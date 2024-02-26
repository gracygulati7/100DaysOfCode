<<<<<<< HEAD
//! minimum subsets with consecutive numbers
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numofsubset(int arr[], int n) {
        sort(arr, arr + n);
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] != 1) {
                // If the current number is not consecutive to the previous, start a new subset
                count++;
            }
        }
        return count;
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
    Solution obj;
    int result = obj.numofsubset(arr, n);
    cout << "Number of subsets: " << result << endl;
    return 0;
}


// link for question:
=======
//! minimum subsets with consecutive numbers
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numofsubset(int arr[], int n) {
        sort(arr, arr + n);
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] != 1) {
                // If the current number is not consecutive to the previous, start a new subset
                count++;
            }
        }
        return count;
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
    Solution obj;
    int result = obj.numofsubset(arr, n);
    cout << "Number of subsets: " << result << endl;
    return 0;
}


// link for question:
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://practice.geeksforgeeks.org/problems/min-subsets-with-consecutive-numbers0601/1?page=3&difficulty[]=0&status[]=solved&category[]=Arrays&sortBy=submissions