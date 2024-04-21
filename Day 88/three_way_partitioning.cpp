//! GeeksForGeeks question Three way partitioning (PROBLEM OF THE DAY 21-4-2024)

//? link: https://www.geeksforgeeks.org/problems/three-way-partitioning/1

#include<bits/stdc++.h>
using namespace std;
class Solution{   
public:
    void threeWayPartition(vector<int>& array,int a, int b) {
        vector<int> ans;
        for(int i=0;i<array.size();i++){
            if(array[i]<a){
                ans.push_back(array[i]);
            }
        }
        for(int i=0;i<array.size();i++){
            if(array[i]>=a && array[i]<=b){
                ans.push_back(array[i]);
            }
        }
        for(int i=0;i<array.size();i++){
            if(array[i]>b){
                ans.push_back(array[i]);
            }
        }
        for(int i=0;i<array.size();i++){ // for inplace modification
            array[i]=ans[i];
        }
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int a,b;
    cin>>a>>b;
    Solution obj;
    obj.threeWayPartition(array,a,b);
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}