//! leetcode question 495. Teemo Attacking

//? link: https://leetcode.com/problems/teemo-attacking/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findPoisonedDuration(std::vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int totalPoisonedTime = 0;
        for (int i = 1; i < n; i++) {
            totalPoisonedTime += std::min(duration, timeSeries[i] - timeSeries[i - 1]);
        }
// This line calculates the duration of poisoning for the current attack. It takes the minimum of the specified duration
//  and the time gap between the current attack (timeSeries[i]) and the previous attack (timeSeries[i - 1]). This prevents 
// double-counting if the next attack occurs before the previous poisoning ends.

        totalPoisonedTime += duration; // This adds the duration for the last attack, assuming the poisoning lasts until the end.
        return totalPoisonedTime;
    }
};
int main(){
    Solution s;
    vector<int> timeSeries = {1,4};
    int duration = 2;
    cout << s.findPoisonedDuration(timeSeries, duration) << endl;
    return 0;
}