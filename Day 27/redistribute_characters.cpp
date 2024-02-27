//! leetcode question 1897. Redistribute Characters to Make All Strings Equal

//? link: https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/description/?envType=daily-question&envId=2024-02-20

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        // Get the total number of words in the array
        int n = words.size();
        // Create a vector 'count' with 26 elements, initialized to 0
        // Each element represents the count of a specific character in the alphabet
        vector<int> count(26, 0);
        // Loop through each word in the array
        for (int i = 0; i < n; i++) {
            // Loop through each character in the current word
            for (int j = 0; j < words[i].size(); j++) {
                count[words[i][j] - 'a']++; // This line increments the count of the current character in the count array. 
                // It uses the ASCII value difference between the current character and 'a' to determine the index in the count array.
            }
        }
        // Check if the counts are evenly divisible by the total number of words
        for (int i = 0; i < 26; i++) {
            if (count[i] % n != 0) { // it checks if the count of the character at index i is not evenly divisible by the total number of words 
            // (n). If the count is not divisible, it means that the characters cannot be evenly distributed among the words.
                // If any character count is not divisible, return false
                return false;
            }
        }
        // If all character counts are divisible, return true
        return true;
    }
};