//! leetcode question 1550. Three Consecutive Odds

//? link: https://leetcode.com/problems/three-consecutive-odds/description/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        for(int i=1;i<n-1;i++){
            if(arr[i]%2!=0 && arr[i-1]%2!=0 && arr[i+1]%2!=0){
                return true;
            }
        }
        return false;
    }
};
int main(){
    Solution s;
    vector<int> arr={1,2,3,4,5};
    cout<<s.threeConsecutiveOdds(arr)<<endl;
    return 0;
}