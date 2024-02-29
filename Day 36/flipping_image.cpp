//! leetcode question 832. Flipping an Image

//? link: https://leetcode.com/problems/flipping-an-image/description/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m/2;j++){
                swap(image[i][j],image[i][m-j-1]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(image[i][j]==1){
                    image[i][j]=0;
                }
                else if(image[i][j]==0){
                    image[i][j]=1;
                }
            }
        }
        return image;
    }
};

//* LOGIC:
//! for iterating loop from j=0 to j=m/2:
/*
The reason for iterating up to m/2 in the loop for reversing each row is that when you swap elements, if you go beyond the midpoint,
you will end up swapping the elements back to their original positions, effectively undoing the reversal.
Consider the process of reversing an array:
If you swap the first element with the last element, the array becomes reversed.
If you swap the second element with the second-to-last element, the array continues to be reversed.
If you keep doing this until you reach the midpoint of the array, you would have reversed the entire array.
After the midpoint, if you continue swapping elements, you will start to undo the reversal, and you will end up with the original order. 
*/

//! for swapping swap(image[i][j],image[i][m-j-1]); ->
/*
When swapping elements to reverse an array or row, the expression m-j-1 is used to find 
the corresponding element on the opposite side of the array or row.
Let's break down the logic:
j is the current index as we iterate through the array or row.
m is the total number of elements in the array or row.
m - j - 1 calculates the index of the element symmetrically opposite to the current element with respect to the midpoint of the array or row.
Consider the following example:
int array[] = {1, 2, 3, 4, 5};
int m = 5; // total elements
for (int j = 0; j < m / 2; j++) {
    swap(array[j], array[m - j - 1]);
}
Here, as j increases from 0 to m/2 - 1, the expression m - j - 1 calculates the corresponding index to swap with. For example:
When j = 0, m - j - 1 = 4, swapping array[0] with array[4].
When j = 1, m - j - 1 = 3, swapping array[1] with array[3].
... and so on.
This ensures that we reverse the array by swapping elements from the beginning 
with their corresponding elements from the end, moving towards the center.
*/