<<<<<<< HEAD
//! leetcode question 1496. Path Crossing

//? link: https://leetcode.com/problems/path-crossing/description/?envType=daily-question&envId=2024-02-19

#include <string>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPathCrossing(string path) {
        int n = path.size();
        int x = 0, y = 0;
        set<vector<int>> paths;
        paths.insert({0, 0});
        for (char i : path) {
            switch (i) {
                case 'N': y++; break;
                case 'S': y--; break;
                case 'E': x++; break;
                case 'W': x--; break;
            }
            if (paths.find({x, y}) != paths.end()) {
                return true;
            }
            paths.insert({x, y});
        }
        return false;
    }
};
=======
//! leetcode question 1496. Path Crossing

//? link: https://leetcode.com/problems/path-crossing/description/?envType=daily-question&envId=2024-02-19

#include <string>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPathCrossing(string path) {
        int n = path.size();
        int x = 0, y = 0;
        set<vector<int>> paths;
        paths.insert({0, 0});
        for (char i : path) {
            switch (i) {
                case 'N': y++; break;
                case 'S': y--; break;
                case 'E': x++; break;
                case 'W': x--; break;
            }
            if (paths.find({x, y}) != paths.end()) {
                return true;
            }
            paths.insert({x, y});
        }
        return false;
    }
};
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
