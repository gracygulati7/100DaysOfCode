//! leetcode question 119. Pascal's Triangle II

//? link: https://leetcode.com/problems/pascals-triangle-ii/description

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pascal; // declares a vector named pascal that will store the elements of the Pascal's Triangle row.
        pascal.push_back(1); //  initializes the vector with the first element, which is always 1.
        for(int i=0;i<=rowIndex;i++){ // The outer loop runs from i=0 to i=rowIndex, iterating through each row of Pascal's Triangle
            for(int j=i;j>=1;j--){ //The inner loop runs from j=i to j=1, iterating through each element in the current row.
                if(j==i){ // If j=i,it means we are at the last element of the row. In this case, 
                // we push 1 to the vector as the last element of the current row.
                    pascal.push_back(1);
                }
                else{ // For other elements in the row, we calculate the value using the Pascal's Triangle recurrence relation.
                    pascal[j]=pascal[j]+pascal[j-1]; // The value at position j is the sum of the values at the same position 
                    // and the position to its left in the previous row.
                }
            }
        }
        return pascal;
    }
};
int main(){
    Solution s;
    vector<int> result=s.getRow(3);
    for (int num:result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}