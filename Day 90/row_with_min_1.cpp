//! GeeksForGeeks Question Row with minimum number of 1's (PROBLEM OF THE DAY 22-4-2024)

//? link: https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        int mincount=INT_MAX; int idx=-1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                if(a[i][j]==1) count++; 
            }
            if(count<mincount){
                mincount=count;
                idx=i;
            }
        }
        return idx+1;
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    Solution obj;
    cout<<obj.minRow(n,m,a)<<endl;
    return 0;
}