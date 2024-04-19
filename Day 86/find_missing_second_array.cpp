//! geeksforgeeks question Find missing in second array (PROBLEM OF THE DAY 19-4-2024)

//? link: https://www.geeksforgeeks.org/problems/in-first-but-second5423/1

#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
	vector<int> findMissing(int a[], int b[], int n, int m) { 
	   vector<int> ans; set<int> s;
	   for(int i=0;i<m;i++){
	       s.insert(b[i]);
	   }
	   for(int i=0;i<n;i++){
	       if(s.find(a[i])==s.end()){
	           ans.push_back(a[i]);
	       }
	   }
	   return ans;
	} 
};
int main(){
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int b[]={2,3,4,5,6,7,8,9,10,11};
    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(b)/sizeof(b[0]);
    Solution ob;
    vector<int> ans=ob.findMissing(a,b,n,m);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}