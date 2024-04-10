//! leetcode question 950. Reveal Cards In Increasing Order (PROBLEM OF THE DAY 10-4-2024)

//? link: https://leetcode.com/problems/reveal-cards-in-increasing-order/description/?envType=daily-question&envId=2024-04-10

//* LOGIC: overall role of count variable is:
/*
The count variable ensures that cards are revealed in an orderly manner 
according to the problem's rule of revealing every second unrevealed card. 
It helps maintain the alternating reveal pattern and ensures that the 
correct number of cards are revealed until all cards are revealed.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        vector<int> res(n, 0); // Initialize a vector to store the reordered deck

        // Initialize variables for iteration and counting
        int revealed = 1; // Tracks the number of revealed cards, its 1 as first card is already revealed
        int count = 0; // Tracks the number of iterations

        // Iterate until all cards are revealed
        while (revealed <= n) {
            // Iterate through the reordered deck (res)
            for (int i = 0; i < n; i++) {
                // Check if the current position in the reordered deck is unrevealed 
                if (res[i] == 0) {
                    // Check if it's the turn to reveal a card
                    if (count % 2 == 0) {
                        // Reveal the card by placing it in the reordered deck (res)
                        res[i] = deck[revealed - 1];
                        revealed++; // increment revealed as we revealed another card and placed it in reordered deck (res)
                    }
                    count++; // Increment the count for each iteration
                }
            }
        }
        return res; // Return the reordered deck
    }
};
int main(){
    Solution s;
    vector<int> deck = {17,13,11,2,3,5,7};
    vector<int> res = s.deckRevealedIncreasing(deck);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}