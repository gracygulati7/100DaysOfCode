//! Leetcode Question 752. Open the Lock (PROBLEM OF THE DAY 22-4-2024)

//? link: https://leetcode.com/problems/open-the-lock/description/?envType=daily-question&envId=2024-04-22

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        // set to store the deadends because we need to check if the target is a deadend or not
        unordered_set<string> dead(deadends.begin(), deadends.end());
        
        if (dead.count("0000")) return -1; // if the target is a deadend, return -1
        if (target == "0000") return 0; // if the target is already at 0000, return 0

        queue<string> q; // queue to perform BFS
        q.push("0000"); // push the starting point to the queue
        
        unordered_set<string> visited; // set to store the visited nodes
        visited.insert("0000"); // insert the starting point to the visited set
       
        int level = 0;  // variable to store the level of the BFS
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string front = q.front();
                q.pop();
                
                if (front == target) return level; // if the current node is the target, return the level
                for (int i = 0; i < 4; i++) { // loop through all the 4 digits of the current node
                    
                    string up = front; // string up is the current node with the ith digit incremented by 1
                    string down = front; // string down is the current node with the ith digit decremented by 1

                    // up[i] is the ith digit of the current node
                    // up[i] - '0' converts the character to an integer value
                    // (up[i] - '0' + 1) assigns the incremented value to the ith digit
                    // % 10 is used to handle the case when the digit is 9
                    // + '0' converts the integer value back to a character
                    up[i] = (up[i] - '0' + 1) % 10 + '0';

                    // down[i] is the ith digit of the current node
                    // down[i] - '0' converts the character to an integer value
                    // + 9 is used to decrement the digit by 1 and handle the case when the
                    // digit is 0
                    // % 10 is used to handle the case when the digit is 0
                    // + '0' converts the integer value back to a character
                    down[i] = (down[i] - '0' + 9) % 10 + '0';

                    // if the up node is not visited and not a deadend, push it to the queue
                    if (visited.count(up) == 0 && dead.count(up) == 0) {
                        q.push(up);
                        visited.insert(up); // insert the up node to the visited set
                    }

                    // if the down node is not visited and not a deadend, push it to the queue
                    if (visited.count(down) == 0 && dead.count(down) == 0) {
                        q.push(down);
                        visited.insert(down); // insert the down node to the visited set
                    }
                }
            }
            level++; // increment the level
        }
        return -1; // if We cannot reach the target without getting stuck in deadends.
    }
};
int main(){
    Solution s;
    vector<string> deadends = {"8888"};
    string target = "0009";
    cout << s.openLock(deadends, target) << endl;
    return 0;
}