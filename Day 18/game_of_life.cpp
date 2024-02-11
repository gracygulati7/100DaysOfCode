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
        vector<vector<int>> newboard(board);
        int countlive = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int countlive = countLiveNeighbors(board, i, j);
                // conditions:
                if (board[i][j] == 1) {
                    if (countlive < 2 || countlive > 3) {
                        newboard[i][j] = 0;
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
        board = newboard;
    }
private:
    int countLiveNeighbors(vector<vector<int>>& board, int row, int col) {
        int n = board.size();
        int m = board[0].size();
        int countLive = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                int newRow = row + i;
                int newCol = col + j;
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    countLive += board[newRow][newCol] == 1 ? 1 : 0;
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