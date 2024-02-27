//! leetcode question 1535. Find the Winner of an Array Game

//? link: https://leetcode.com/problems/find-the-winner-of-an-array-game/?envType=daily-question&envId=2024-02-23

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size(); int count=0; // to store count of wins of each element
        for(int i=1;i<n;i++){
            if(arr[i]>arr[0]){ // comparing with arr[0] coz maxele should be present at arr[0] position.
                arr[0]=arr[i];
                count=1; 
            }
            else{
                count++;
            }
            if(count==k){
                return arr[0];
            }
        }
    return arr[0];  // bcoz even if no element wins k times , then it prints max element present at arr[0] position.
    }
};
int main(){
    Solution s;
    vector<int> arr={1,2,3,4,5};
    int k=3;
    cout<<s.getWinner(arr,k)<<endl;
    return 0;
}