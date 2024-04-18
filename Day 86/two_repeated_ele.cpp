//! Geeksforgeeks question Two Repeated Elements (PROBLEM OF THE DAY 18-4-2024)

//? link: https://www.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoRepeated(int arr[], int n) {
        vector<int> ans;
        // Traverse the array
        for (int i = 0; i < n + 2; i++) {
            // Check if the element at the current index is negative (initially all elements will be positive)
            if (arr[abs(arr[i])] > 0) {
                // If not negative, make it negative (marking as visited)
                arr[abs(arr[i])] = -arr[abs(arr[i])];
            } else {
                // If negative, it means this element is a repeat coz if an element is repeated 
                // means it would be marked negative when its first occurence wouuld be traversed 
                ans.push_back(abs(arr[i]));
            }
        }
        // Reset the array to its original values
        for (int i = 0; i < n + 2; i++) {
            if (arr[i] < 0) {
                arr[i] = -arr[i];
            }
        }
        return ans;
    }
};

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution obj;
    vector<int> ans = obj.twoRepeated(arr, n);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}