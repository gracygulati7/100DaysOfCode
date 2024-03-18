//! leetcode question 452. Minimum Number of Arrows to Burst Balloons (PROBLEM OF THE DAY 18-3-2024)

//? link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=daily-question&envId=2024-03-18

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end()); // Sort balloons
        int n=points.size();
        int end=points[0][1]; // Ending point of the first balloon
        int arrow=1; // there would be atleast one arrow shot for one balloon
        for(int i=0;i<n;i++){
            if(points[i][0]>end){ // If current balloon's starting point is greater than end, a new arrow needs to be shot
                arrow++; // Increment arrow count
                end=points[i][1]; // Update end to the ending point of current balloon
            }
            // If current balloon's starting point is less than or equal to end,
            // it can be burst by the previous arrow
            // No need to shoot a new arrow
            // Update end to the minimum of the current end and the ending point of current balloon
            end=min(points[i][1],end); 
        }
        return arrow;
    }
};
int main(){
    Solution s;
    vector<vector<int>> points={{10,16},{2,8},{1,6},{7,12}};
    cout<<s.findMinArrowShots(points)<<endl;
    return 0;
}

//*PROBLEM STATEMENT:
/*
? Given: 
You are given an array called points, where each element points[i] represents a balloon. 
Each balloon is represented as an interval [xstart, xend] on the X-axis. 
This means that the balloon's horizontal diameter stretches between xstart and xend.

? Objective: 
Your objective is to find the minimum number of arrows needed to burst all the balloons.

? Arrows: 
Arrows can only be shot vertically upwards, along the Y-axis. 
When an arrow is shot at a certain x coordinate, it will burst any balloon whose interval [xstart, xend] contains that x coordinate.

? Bursting Balloons: 
When an arrow is shot at a particular x coordinate, it bursts all the balloons whose horizontal diameter includes that x coordinate.

? Constraints: 
The constraints indicate the limitations on the input data. 
In this case, 1 <= points.length <= 10^5, meaning there could be up to 100,000 balloons, and -2^31 <= xstart < xend <= 2^31 - 1, 
indicating the range of possible x coordinates for the balloons.

To solve the problem, you need to devise an algorithm that efficiently determines the minimum number of arrows required 
to burst all the balloons. Usually, this involves sorting the balloons based on their xstart or xend coordinates and then 
iterating through them to find the minimum number of arrows needed to burst them all.
*/