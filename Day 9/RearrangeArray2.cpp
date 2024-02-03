//! rearrange array alternately 
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    // Function to rearrange the array elements alternately.
    void rearrange(long long *arr, int n) {
        vector<long long> ans;
        long long int s = 0;
        long long int e = n - 1;
        while (s <= e) {
            ans.push_back(arr[e]);
            ans.push_back(arr[s]);
            s++;
            e--;
        }
        for (int i = 0; i < n; i++) {
            arr[i] = ans[i];
        }
    }
};
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    long long arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution obj;
    obj.rearrange(arr, n);
    cout << "Rearranged array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}


// link for question:
// https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1?page=1&difficulty[]=1&category[]=Arrays&sortBy=submissions