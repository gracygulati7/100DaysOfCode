#include <bits/stdc++.h> 
#include<vector>
using namespace std;
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
        vector<vector<int>> result;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 2; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) continue;
            int left = i + 1;
            int right = arr.size() - 1;
            while (left < right) {
                int currentSum = arr[left] + arr[right] + arr[i];
                if (currentSum == K) {
                    result.push_back({arr[i], arr[left], arr[right]});
                    while (left < right && arr[left] == arr[left + 1]) left++;
                    while (left < right && arr[right] == arr[right - 1]) right--;
                    left++;
                    right--;
                } else if (currentSum < K) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }

// link for question:
// https://leetcode.com/problems/3sum/description/