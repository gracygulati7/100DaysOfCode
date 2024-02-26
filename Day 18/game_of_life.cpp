//! Game Of Life
//! Leetcode Question 289

//? link: https://leetcode.com/problems/game-of-life/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(); 
        int m = board[0].size();
        vector<vector<int>> newboard(board); // Create a copy of the board to store the next state
        // Iterate through each cell in the current state
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int countlive = countLiveNeighbors(board, i, j); // to count live neighbours
                // Apply the rules:
                if (board[i][j] == 1) { // check if element of current board is 0 or 1
                    if (countlive < 2 || countlive > 3) {
                        newboard[i][j] = 0; // make changes in new board
                    }
                    if (countlive == 2 || countlive == 3) {
                        newboard[i][j] = 1;
                    }
                } 
                else {
                    if (countlive == 3) {
                        newboard[i][j] = 1;
                    }
                }
            }
        }
        board = newboard; // Update the original board with the next state
    }
private:
    int countLiveNeighbors(vector<vector<int>>& board, int row, int col) {
        int n = board.size();
        int m = board[0].size();
        int countLive = 0; // Initialize the count of live neighbors to 0
        // The loops go from -1 to 1, covering the cells in the row above, the current row, and the row below, 
        // as well as the columns to the left, the current column, and the columns to the right.
        for (int i = -1; i <= 1; i++) { 
            for (int j = -1; j <= 1; j++) { 
                // This line ensures that the central cell (the current cell) is skipped, as we are interested in its neighbors.
                if (i == 0 && j == 0) continue;
                // row: Represents the row index of the current cell.
                // col: Represents the column index of the current cell.
                // These lines calculate the indices of potential neighboring cells based on the current cell's position (row and col) 
                // and the offsets (i and j). The loops iterate over a 3x3 neighborhood (including the current cell), and these lines 
                // help calculate the indices of the neighboring cells within that neighborhood.
                int newRow = row + i;
                int newCol = col + j;
                // This checks whether the calculated indices newRow and newCol are within the valid boundaries of the board. 
                // If they are, it adds the value of the cell at those indices to the countLive variable, counting live neighbors.
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    countLive += board[newRow][newCol] == 1 ? 1 : 0; // if current cell has 1 then countlive increases to 1 or 0 otherwise
                    // meaning it will have count of live neighbours around a cell
                }
            }
        }
        return countLive;
    }
};

int main() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;
    vector<vector<int>> board(n, vector<int>(m, 0));
    cout << "Enter the initial state of the board (0 for dead, 1 for alive):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    Solution solution;
    solution.gameOfLife(board);
    cout << "Next state of the board:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

//* Example:
//* 1 0 1
//* 0 1 0
//* 1 1 0
//* Let's say we want to calculate the number of live neighbors for the cell at position (1, 1) which has the value 1. 
//* Using the countLiveNeighbors function:
/* 
int countLive = countLiveNeighbors(board, 1, 1);
Now, let's break down the steps:
int n = board.size(); and int m = board[0].size(); : These lines get the number of rows (n = 3) and columns (m = 3) in the board.

The nested loops iterate over the 3x3 neighborhood around the cell at (1, 1), and for each neighboring cell, 
it calculates the indices (newRow and newCol) and checks if they are within the valid boundaries.

When i = -1, j = -1: newRow = 1 - 1 = 0, newCol = 1 - 1 = 0 (Valid)
When i = -1, j = 0: newRow = 1 - 1 = 0, newCol = 1 + 0 = 1 (Valid)
When i = -1, j = 1: newRow = 1 - 1 = 0, newCol = 1 + 1 = 2 (Valid)
When i = 0, j = -1: newRow = 1 + 0 = 1, newCol = 1 - 1 = 0 (Valid)
When i = 0, j = 0: Skipped (current cell)
When i = 0, j = 1: newRow = 1 + 0 = 1, newCol = 1 + 1 = 2 (Valid)
When i = 1, j = -1: newRow = 1 + 1 = 2, newCol = 1 - 1 = 0 (Valid)
When i = 1, j = 0: newRow = 1 + 1 = 2, newCol = 1 + 0 = 1 (Valid)
When i = 1, j = 1: newRow = 1 + 1 = 2, newCol = 1 + 1 = 2 (Valid)
For each valid neighboring cell, it increments countLive by the value of the cell at that position.

countLive += board[0][0]: Incremented by 1
countLive += board[0][1]: Incremented by 0 (dead cell)
countLive += board[0][2]: Incremented by 1
countLive += board[1][0]: Incremented by 0 (dead cell)
countLive += board[1][2]: Incremented by 0 (dead cell)
countLive += board[2][0]: Incremented by 1
countLive += board[2][1]: Incremented by 1
countLive += board[2][2]: Incremented by 0 (dead cell)
The final count is returned, and in this case, countLive would be 4, 
representing the number of live neighbors for the cell at (1, 1). 
This count is then used in the main logic to determine the next state based on the Game of Life rules. 

*/