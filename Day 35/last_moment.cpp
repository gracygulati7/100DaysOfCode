//! leetcode question 1503. Last Moment Before All Ants Fall Out of a Plank

//? link: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res=0; // This variable will be used to keep track of the last moment when an ant (from either the left or right) is present.
        for(int i=0;i<left.size();i++){
            res=max(res,left[i]); // updates res to the maximum value between its current value and the current element in the left vector. 
            // This ensures that res will store the maximum position of ants from the left side.
        }
        for(int i=0;i<right.size();i++){
            res=max(res,n-right[i]); // updates res to the maximum value between its current value and the position n-right[i]. 
// The position of each ant in the right vector is given as its initial position from the right end of the rod.
// When we calculate n-right[i], we determine current position of the ant relative to the left end of the rod means from the starting index.
        }
        return res; // this represents the last moment when an ant is present considering both the left and right vectors.
    }
};
int main(){
    Solution s;
    int n=3;
    vector<int> left={1,2,3};
    vector<int> right={1,2,3};
    cout<<s.getLastMoment(n,left,right)<<endl;
    return 0;
}