//! leetcode question 85. Maximal Rectangle (PROBLEM OF THE DAY 13-4-2024)

//? link: https://leetcode.com/problems/maximal-rectangle/description/?envType=daily-question&envId=2024-04-13

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        // This line checks if the input matrix is empty. If it is, it means there are no elements in the matrix,
        // so the function returns 0, indicating that the largest rectangle area is 0.
        if (matrix.empty())
            return 0;

        // This line initializes a variable maxArea to store the maximum rectangle area containing only '1's found so far,
        // and rows and cols to store number of rows and columns in input matrix
        int maxarea = 0, rows = matrix.size(), cols = matrix[0].size();

        // left will store the leftmost index of the rectangle
        // cols, 0 means that we are initializing the vector with 0 of size cols
        // we are initializing it with 0 because we need to calculate the leftmost index of the rectangle
        // left will have the same size as the number of columns because we need to
        // keep track of the leftmost index of the rectangle for each column
        vector<int> left(cols, 0);

        // right will store the rightmost index of the rectangle
        // cols, cols means that we are initializing the vector with cols elements of size which is same as number of columns in matrix
        vector<int> right(cols, cols);

        // Here we are initializing the heights vector with 0 of size cols because we
        // need to calculate the height of the rectangle heights will store the height of the rectangle
        // heights of rectangle is the number of consecutive 1's in the column
        vector<int> height(cols, 0);

        // We will iterate over the rows of the matrix
        // this if for the left boundary of the matrix so we iterate from starting index to the ending index of rows and cols
        for (int i = 0; i < rows; i++)
        {
            // curr_left will store the current leftmost index of the rectangle
            // curr_right will store the current rightmost index of the rectangle
            int curr_left = 0, curr_right = cols;

            // We will iterate over the columns of the matrix
            for (int j = 0; j < cols; j++)
            {
                // If the current element is 0 means the current position cannot be part of a rectangle,
                // so we reset the height, left boundary, and update cur_left accordingly
                if (matrix[i][j] == '0')
                {
                    height[j] = 0;
                    left[j] = 0;
                    curr_left = j + 1;
                }
                // If it is '1', we update the height and left boundary based on the current left boundary and the previous height.
                else
                {
                    height[j] += 1;
                    left[j] = max(left[j], curr_left);
                }
            }
            // j = cols - 1 because we are iterating from the last column to the first column for right boundary
            for (int j = cols - 1; j >= 0; j--)
            {
                // If the current element is 0 then we will update the right and curr_right
                if (matrix[i][j] == '0')
                {
                    // right[j] = cols because we are initialized the rightmost index of the rectangle with cols in right vector
                    right[j] = cols;
                    curr_right = j; // curr_right will store the current rightmost index of the rectangle
                }
                else
                {
                    // We will update the rightmost index of the rectangle if current element is 1
                    right[j] = min(curr_right, right[j]);
                }
            }
            // We will iterate over the columns of the matrix and calculate the maximum area
            for (int j = 0; j < cols; j++)
            {
                // maxArea = max(maxArea, heights[j] * (right[j] - left[j])) will give us the max area of the rectangle that can be obtained
                // heights[j] * (right[j] - left[j]) will give us the area of the current rectangle
                maxarea = max(maxarea, height[j] * (right[j] - left[j]));
            }
        }
        return maxarea;
    }
};
int main()
{
    Solution s;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};
    cout << s.maximalRectangle(matrix) << endl;
    return 0;
}