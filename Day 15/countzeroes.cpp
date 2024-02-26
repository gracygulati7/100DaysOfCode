<<<<<<< HEAD
//! count the zeroes
//* geeks for geeks question:
//? link: https://practice.geeksforgeeks.org/problems/count-the-zeros2550/1?page=1&difficulty[]=0&category[]=Searching&sortBy=submissions

#include <iostream>
using namespace std;
class Solution {
public:
    int countZeroes(int arr[], int n) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
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
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter element at position " << i << ": ";
        cin >> arr[i];
    }
    Solution solution;
    int zeroCount = solution.countZeroes(arr, n);
    cout << "Number of zeroes in the array: " << zeroCount << endl;
    return 0;
}
=======
//! count the zeroes
//* geeks for geeks question:
//? link: https://practice.geeksforgeeks.org/problems/count-the-zeros2550/1?page=1&difficulty[]=0&category[]=Searching&sortBy=submissions

#include <iostream>
using namespace std;
class Solution {
public:
    int countZeroes(int arr[], int n) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
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
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter element at position " << i << ": ";
        cin >> arr[i];
    }
    Solution solution;
    int zeroCount = solution.countZeroes(arr, n);
    cout << "Number of zeroes in the array: " << zeroCount << endl;
    return 0;
}
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
