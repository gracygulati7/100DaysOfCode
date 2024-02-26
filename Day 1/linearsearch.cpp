<<<<<<< HEAD
#include <iostream>
#include <vector>
using namespace std;
int linearSearch(int n, int num, vector<int> &arr) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int num;
    cout << "Enter the number to search: ";
    cin >> num;
    int result = linearSearch(n, num, arr);
    if (result != -1) {
        cout << "Number " << num << " found at index " << result << endl;
    } else {
        cout << "Number " << num << " not found in the array" << endl;
    }
    return 0;
}

// link for question:
=======
#include <iostream>
#include <vector>
using namespace std;
int linearSearch(int n, int num, vector<int> &arr) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int num;
    cout << "Enter the number to search: ";
    cin >> num;
    int result = linearSearch(n, num, arr);
    if (result != -1) {
        cout << "Number " << num << " found at index " << result << endl;
    } else {
        cout << "Number " << num << " not found in the array" << endl;
    }
    return 0;
}

// link for question:
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://www.codingninjas.com/studio/problems/linear-search_6922070