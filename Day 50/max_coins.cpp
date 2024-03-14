//! leetcode question 1561. Maximum Number of Coins You Can Get

//? link: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(), piles.rend());
        int me=0;
        for (int i=1;i<piles.size()/3*2;i+=2) {
            me+=piles[i];
        }
        return me;
    }
};
int main(){
    Solution s;
    vector<int> piles={2,4,1,2,7,8};
    cout<<s.maxCoins(piles)<<endl;
    return 0;
}

//* LOGIC:
/*
We sort the array in non-increasing order to ensure that Alice will take the highest pile and Bob will take the lowest pile.
We iterate through the sorted array, starting from the second highest pile and skipping every other pile, 
as you'll take the middle piles after Alice and Bob have made their choices.
We sum up the values of the piles you'll take and return the total number of coins.
*/