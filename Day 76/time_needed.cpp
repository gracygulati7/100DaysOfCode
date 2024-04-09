//! leetcode question 2073. Time Needed to Buy Tickets (PROBLEM OF THE DAY 9-4-2024)

//? link: https://leetcode.com/problems/time-needed-to-buy-tickets/description/?envType=daily-question&envId=2024-04-09

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();

        // This initializes a variable steps to keep track of the number of steps (or time) taken to buy all the tickets.
        int steps=0;

        // This starts an infinite loop that will continue until a return statement is executed inside the loop.
        while(true){
            for(int i=0;i<n;i++){
                // This condition skips current iteration if the person at position i has already bought all their tickets 
                // (i.e., if tickets[i] is 0).
                if(tickets[i]==0) continue;

                // This decrements the number of tickets the person at position i wants to buy. 
                tickets[i]--;
                steps++; // This increments the steps variable, indicating that one step (or one unit of time) has passed.

                // This condition checks if the person we are interested in (at position k) has bought all their tickets. 
                // If so, it immediately returns the total number of steps taken so far.
                if(tickets[k]==0) return steps;
                //If none of the if conditions are met inside the loop, the loop continues, and the process repeats 
                // until the person at position k has bought all their tickets.
            }
        }
    }
};
int main(){
    Solution s;
    vector<int> tickets={5,1,1,1};
    int k=0;
    cout<<s.timeRequiredToBuy(tickets,k)<<endl;
    return 0;
}