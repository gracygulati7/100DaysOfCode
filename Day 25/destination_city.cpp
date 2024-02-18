//! leetcode question 1436. Destination City

//? link: https://leetcode.com/problems/destination-city/?envType=daily-question&envId=2024-02-18

#include<iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size(); 
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (paths[i][1] == paths[j][0]) {
                    count++;
                    break;
                }    
            }
            if (count == 0) {
                return paths[i][1];
            }
        }
        return "";
    }
};