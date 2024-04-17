//! Geeksforgeeks quesion Count Pairs in an Array (PROBLEM OF THE DAY 17-4-2024)

//? link: https://www.geeksforgeeks.org/problems/count-pairs-in-an-array4145/1

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPairs(int arr[], int n)
    {
        // Brute Force
        /*
              int count_pairs = 0;
              for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                  if (i * arr[i] > j * arr[j]) {
                    count_pairs++;
                  }
                }
              }
              return count_pairs;
        */
        // g -> i * arr[i]
        // s -> sorted g
        vector<int> g, s;
        // Traverse the array and store i * arr[i] in g
        for (int i = 0; i < n; i++)
        {
            g.push_back(i * arr[i]);
            // Store the values in s of g for sorting
            s.push_back(g[i]);
        }
        // Sort the s vector
        sort(s.begin(), s.end());
        int ans = 0;
        // Traverse the g vector
        for (int i = 0; i < n; i++)
        {
            // Find the index of the element in s
            // basically lower_bound is used to find the index of the element in the
            // sorted array s which is greater than or equal to the element in g
            // lower_bound(s.begin(), s.end(), g[i]) means find the index of the element
            // g[i] in the sorted array s from s.begin() to s.end()... 
            // - s.begin() is done to get the index of the element in 0 based indexing
            int index = lower_bound(s.begin(), s.end(), g[i]) - s.begin();
            // Add the index to the answer
            ans += index;
            // This is done to remove the element from the sorted array s so that we can
            // get the next greater element in the next iteration
            s.erase(s.begin() + index);
        }
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution ob;
    cout << ob.countPairs(arr, n) << endl;
    return 0;
}