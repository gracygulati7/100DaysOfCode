<<<<<<< HEAD
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    int remove_duplicate(int a[], int n) {
        sort(a, a + n);
        set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(a[i]);
        }
        int i = 0;
        for (int x : s) {
            a[i++] = x;
        }
        return s.size();
        // or 2nd method of 1 line only -
        // std::unique(a, a + n) - a;
    }
};
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution obj;
    int result = obj.remove_duplicate(a, n);
    cout << "Number of distinct elements: " << result << endl;
    cout << "Modified array: ";
    for (int i = 0; i < result; i++) {
        cout << a[i] << " ";
    }
    return 0;
}


// link for question:
=======
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    int remove_duplicate(int a[], int n) {
        sort(a, a + n);
        set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(a[i]);
        }
        int i = 0;
        for (int x : s) {
            a[i++] = x;
        }
        return s.size();
        // or 2nd method of 1 line only -
        // std::unique(a, a + n) - a;
    }
};
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution obj;
    int result = obj.remove_duplicate(a, n);
    cout << "Number of distinct elements: " << result << endl;
    cout << "Modified array: ";
    for (int i = 0; i < result; i++) {
        cout << a[i] << " ";
    }
    return 0;
}


// link for question:
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1?page=1&difficulty[]=0&category[]=Arrays&sortBy=submissions