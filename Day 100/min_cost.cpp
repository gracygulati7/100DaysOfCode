//! Leetcode Question 746. Min Cost Climbing Stairs

//? link: https://leetcode.com/problems/min-cost-climbing-stairs/?envType=study-plan-v2&envId=leetcode-75

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); // Get the size of the cost array
        
        // Iterate through the array starting from the third element
        for(int i = 2; i < n; i++) {
            // At each step, update the cost of reaching the current step
            // The cost of reaching the current step is the minimum of 
            // the cost of reaching the previous step or two steps back,
            // plus the cost of the current step
            cost[i] = min(cost[i - 1], cost[i - 2]) + cost[i];
        }
        
        // Finally, return the minimum cost of reaching the top floor,
        // which is the minimum of the cost of reaching the last step
        // or the second last step
        return min(cost[n - 1], cost[n - 2]);
    }
};

int main(){
    Solution s;
    vector<int> v={10,15,20};
    cout<<s.minCostClimbingStairs(v)<<endl;
    return 0;
}