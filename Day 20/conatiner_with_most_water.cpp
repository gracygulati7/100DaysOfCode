<<<<<<< HEAD
//! leetcode question 11
//! container with most water

//? link: https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-interview-150

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            int h = min(height[left], height[right]); // take minimum of heights of left and right bcoz container will be formed with height 
            // of minimum one else if we take max height so water will overflow and wont form a container
            int w = right - left; // distance btw two poles forming container
            int area = h * w;
            maxArea = max(maxArea, area); // calculate max area that can be formed by container
            if (height[left] < height[right]) { 
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
=======
//! leetcode question 11
//! container with most water

//? link: https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-interview-150

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            int h = min(height[left], height[right]); // take minimum of heights of left and right bcoz container will be formed with height 
            // of minimum one else if we take max height so water will overflow and wont form a container
            int w = right - left; // distance btw two poles forming container
            int area = h * w;
            maxArea = max(maxArea, area); // calculate max area that can be formed by container
            if (height[left] < height[right]) { 
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
};