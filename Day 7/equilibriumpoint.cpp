#include <iostream>
using namespace std;
class Solution {
public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        long long int leftsum = 0, rightsum = 0;
        long long int s = 0, e = n - 1;
        while (s <= e) {
            if (leftsum < rightsum) {
                leftsum += a[s];
                s++;
            } else if (leftsum > rightsum) {
                rightsum += a[e];
                e--;
            } else {
                if (s == e) {
                    return s + 1;
                } else {
                    leftsum += a[s];
                    rightsum += a[e];
                    s++;
                    e--;
                }
            }
        }
        return -1;
    }
};
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    long long a[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution obj;
    int equilibrium = obj.equilibriumPoint(a, n);
    if (equilibrium != -1) {
        cout << "Equilibrium point is at index: " << equilibrium << endl;
    } else {
        cout << "No equilibrium point found." << endl;
    }
    return 0;
}


// link for question:
// https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1?page=1&difficulty[]=0&category[]=Arrays&sortBy=submissions