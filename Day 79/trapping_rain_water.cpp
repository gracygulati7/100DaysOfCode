//! leetcode question 42. Trapping Rain Water (PROBLEM OF THE DAY 12-4-2024)

//? link: https://leetcode.com/problems/trapping-rain-water/description/?envType=daily-question&envId=2024-04-12

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> maxleft(n,0);  //initializes vector with n elements with value = 0
        vector<int> maxright(n,0);
        int sum=0;
        if(n<=2){
            return 0;
        }
        maxleft[0]=height[0];
        for(int i=1;i<n;i++){
            maxleft[i]=max(height[i],maxleft[i-1]); // comparing height of current bar with previous bars max height
        }
        maxright[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            maxright[i]=max(height[i],maxright[i+1]);
        }
        for(int i=0;i<n;i++){
            int water=min(maxleft[i],maxright[i]);
            int trap=max(0,water-height[i]);
            sum+=trap; // taking max with 0 so that if at any bar value comes -ve to take it as 0
        }
        return sum;
    }
};
int main(){
    Solution s;
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<s.trap(height)<<endl;
    return 0;
}