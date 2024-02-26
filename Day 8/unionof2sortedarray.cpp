#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    // arr1, arr2: the arrays
    // n, m: size of arrays
    // Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        vector<int> result;
        for (int i = 0; i < n; i++) {
            result.push_back(arr1[i]);
        }
        for (int i = 0; i < m; i++) {
            result.push_back(arr2[i]);
        }
        set<int> s;
        s.insert(result.begin(), result.end());
        vector<int> vec(s.begin(), s.end());
        return vec;
    }
};
int main() {
    int n, m;
    cout << "Enter the size of the first array: ";
    cin >> n;
    cout << "Enter the size of the second array: ";
    cin >> m;
    int arr1[n], arr2[m];
    cout << "Enter elements of the first array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    cout << "Enter elements of the second array:" << endl;
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    Solution obj;
    vector<int> result = obj.findUnion(arr1, arr2, n, m);
    cout << "Union of the two arrays: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}


// link for question:
// https://practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1?page=2&difficulty[]=0&category[]=Arrays&sortBy=submissions