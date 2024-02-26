//! LeetCode Question 1481. Least Number of Unique Integers after K Removals
//! Problem Of The Day 16-02-2024

//? link: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/?envType=daily-question&envId=2024-02-16

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        // vector frequencies is declared to store the frequencies of each unique element in the sorted array. 
        // The variable count is initialized to 1 and will be used to count consecutive occurrences of the same element.
        vector<int> frequencies;
        int count = 1;
        // Count the frequencies of each element
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] == arr[i - 1]) {
                count++;
            } else {
                frequencies.push_back(count);
                count = 1;
            }
        }
        // Inside the loop, it checks if the current element is equal to the previous element. 
        // If true, it increments the count variable, indicating consecutive occurrences of the same element. 
        // If false, it means a new element is encountered, so the count is pushed into the frequencies vector, and count is reset to 1.
        frequencies.push_back(count); // After the loop, the count of the last element is pushed into the frequencies vector.
        sort(frequencies.begin(), frequencies.end());
        // uniqueCount is initialized to the size of the frequencies vector, representing the initial count of unique integers.
        int uniqueCount = frequencies.size();
        // Iterate through frequencies and remove elements until k becomes zero
        for (int freq : frequencies) {
            if (k >= freq) {
                k -= freq;
                uniqueCount--;
            } else {
                break;
            }
        }
        // A for loop iterates through the sorted frequencies. If the remaining removal capacity k >= the current frequency, 
        // it means we can remove all occurrences of the current element. In that case, decrement k by the frequency, and 
        // decrement the count of unique integers (uniqueCount). If k < the current frequency, break out of the loop as we 
        // cannot remove more elements.
        return uniqueCount; // the function returns the calculated count of unique integers after removing elements.
    }
};

int main() {
    Solution solution;
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;
    int result = solution.findLeastNumOfUniqueInts(arr, k);
    cout << "The least number of unique integers after removing " << k << " elements is: " << result << endl;
    return 0;
}
