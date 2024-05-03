//! Leetcode question 605. Can Place Flowers

//? link: https://leetcode.com/problems/can-place-flowers/?envType=study-plan-v2&envId=leetcode-75

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // If n is 0, it means we can always place 0 flowers.
        if(n == 0) return true;
        
        // Loop through the flowerbed array
        for(int i = 0; i < flowerbed.size(); i++) {
            // Check if the current position is empty (0) and both of its adjacent positions are also empty
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && 
               (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                // If conditions are met, decrement the number of flowers to place
                n--;
                // If no more flowers need to be placed, return true
                if(n == 0) return true;
                // Mark the current position as planted (1)
                flowerbed[i] = 1;
            }
        }
        // If after iterating through the flowerbed, we still need to place flowers, return false
        return false;
    }
};
int main(){
    Solution s;
    vector<int> flowerbed = {1,0,0,0,1};
    int n = 1;
    cout << s.canPlaceFlowers(flowerbed, n);
    return 0;
}