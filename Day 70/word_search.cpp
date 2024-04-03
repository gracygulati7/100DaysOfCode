//! leetcode question 79. Word Search (PROBLEM OF THE DAY 3-4-2024)

//? link: https://leetcode.com/problems/word-search/description/?envType=daily-question&envId=2024-04-03

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // pass board by reference
    bool DFS(vector<vector<char>>& board, string word, int i, int j, int n) {

		// Base case: If the entire word has been found, return true
        if(n == word.size()) return true; 
        
		// Base case: If the current cell is out of bounds or does not match the current character in word, return false
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[n]) return false;
        
		// Mark the current cell as visited by changing its value to a special character (e.g., '0')
        board[i][j] = '0';
        
		// Recursively search for the remaining characters of the word in the neighboring cells
        bool status = DFS(board, word, i + 1, j, n + 1) ||     // down
                        DFS(board, word, i, j + 1, n + 1) ||   // right
                        DFS(board, word, i - 1, j, n + 1) ||   // up
                        DFS(board, word, i, j - 1, n + 1);     // left
        
		// Restore the original value of the current cell after backtracking for other searches
        board[i][j] = word[n];

        // Return the status (true if the word is found, false otherwise)
        return status;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()) return false;
        for(int i = 0; i < board.size(); i++){ 
            for(int j = 0; j < board[i].size(); j++) {
                // If the current cell contains the first character of the word and the
                // DFS search returns true (means whole word is found), then return true
                if(board[i][j] == word[0] && DFS(board, word, i, j, 0)){ 
                    return true;
                }
            }
        }
        // If the word is not found, return false
        return false;
    }
};