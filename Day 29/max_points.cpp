//! leetcode question 149. Max Points on a Line

//? link: https://leetcode.com/problems/max-points-on-a-line/description/?envType=study-plan-v2&envId=top-interview-150

#include<iostream>
#include<climits>
#include<vector>
using namespace std;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size(); int maxslopepoints=0;
        if(n<=1){
            return n; // Return 0 or 1 if there are 0 or 1 points
        }
        for(int i=0;i<n;i++){
            int x1=points[i][0]; int y1=points[i][1];
            int j=i+1;
            while(j<n){
                int x2=points[j][0]; int y2=points[j][1];
                int slope=(x2-x1==0)? INT_MAX :(y2-y1)/(x2-x1);
                int count=2; // count starts from 2 as we have two points on the line (points[i] and points[j])
                // Check for other points on the same line
                int k=j+1;
                while(k<n){
                    int x3=points[k][0]; int y3=points[k][1];
                    if((x2-x1)*(y3-y1)==(x3-x1)*(y2-y1)){
                        count++;
                    }
                    k++;
                }
                // Update maxSlopePoints if the current line has more points
                if(slope>maxslopepoints){
                    maxslopepoints=count;
                }
                j++;
            }
        }
    return maxslopepoints;
    }
};