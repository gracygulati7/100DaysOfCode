//! leetcode question 57. Insert Interval (PROBLEM OF THE DAY 17-3-2024)

//? link: https://leetcode.com/problems/insert-interval/description/?envType=daily-question&envId=2024-03-17

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size(), i=0;
        vector<vector<int>> res;
        //case 1: no overlapping case before the merge intervals
		//compare ending point of intervals to starting point of newInterval
        while(i<n && intervals[i][1]<newInterval[0]){
            res.push_back(intervals[i]);
            i++;            
        }
        //case 2: overlapping case and merging of intervals
        while(i<n && newInterval[1]>=intervals[i][0]){
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);
            i++;
        }
        res.push_back(newInterval);
        // case 3: no overlapping of intervals after newinterval being merged
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<vector<int>> intervals;
    vector<int> newInterval;
    intervals.push_back({1,3});
    intervals.push_back({6,9});
    intervals.push_back({12,16});
    intervals.push_back({20,24});
    newInterval={8,10};
    vector<vector<int>> res=s.insert(intervals,newInterval);
    for(int i=0;i<res.size();i++){
        cout<<res[i][0]<<" "<<res[i][1]<<endl;
    }
    return 0;
}