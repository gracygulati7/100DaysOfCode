//! leetcode question 821. Shortest Distance to a Character

//? link: https://leetcode.com/problems/shortest-distance-to-a-character/description/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.length(); 
        vector<int> answer(n,0);
        for(int i=0;i<n;i++){
            int mindist=INT_MAX;
            for(int j=0;j<n;j++){
                if(s[j]==c){
                    int distance=abs(i-j);
                    mindist=min(mindist,distance);
                }
            }
            answer[i]=mindist;
        }
        return answer;
    }
};