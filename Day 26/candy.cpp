//! leetcode question 135. Candy

//? link: https://leetcode.com/problems/candy/description/?envType=study-plan-v2&envId=top-interview-150

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
// This vector will store the number of candies each child receives. its set to 1 for each child bcoz each child atleast recieves 1 candy each.
        for (int i = 0; i < n - 1; i++) {
            if (ratings[i] < ratings[i + 1]) {
                candies[i + 1] = candies[i] + 1;
            }
        }
// Inside the loop, check if the current child's rating is less than the next child's rating. 
// If true, update the candies for the next child to be one more than the current child.
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
// Start another loop to iterate through the ratings vector from the second-to-last element to the beginning.
// Inside this loop, check if the current child's rating is greater than the next child's rating. If true, 
// update the candies for the current child to be the maximum of its current value and one more than the next child's candies.
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += candies[i];
        }
// After both loops, calculate the total number of candies needed by summing up the values in the candies vector.
        return total;
    }
};