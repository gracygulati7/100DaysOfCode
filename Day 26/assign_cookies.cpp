<<<<<<< HEAD
//! leetcode question 455. Assign Cookies

//? link: https://leetcode.com/problems/assign-cookies/description/?envType=daily-question&envId=2024-02-19

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(),m=s.size();
        int i=0,j=0,count=0;
        sort(g.begin(),g.end()); 
        sort(s.begin(),s.end());
        while(i<n && j<m){
            if(g[i]<=s[j]){ // if greed factor of child <= size of cookie means child can be satisfied
                i++; j++;
                count++;
            }
//if greed factor of child > size of cookie then increase j to see if there are other sizes of cookies available to make the child satisified
            else{ 
                j++;
            }
        }
        return count;
    }
=======
//! leetcode question 455. Assign Cookies

//? link: https://leetcode.com/problems/assign-cookies/description/?envType=daily-question&envId=2024-02-19

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(),m=s.size();
        int i=0,j=0,count=0;
        sort(g.begin(),g.end()); 
        sort(s.begin(),s.end());
        while(i<n && j<m){
            if(g[i]<=s[j]){ // if greed factor of child <= size of cookie means child can be satisfied
                i++; j++;
                count++;
            }
//if greed factor of child > size of cookie then increase j to see if there are other sizes of cookies available to make the child satisified
            else{ 
                j++;
            }
        }
        return count;
    }
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
};