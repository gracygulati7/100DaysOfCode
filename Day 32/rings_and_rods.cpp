//! leetcode question 2103. Rings and Rods

//? link: https://leetcode.com/problems/rings-and-rods/description/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countPoints(string rings) {
        int n=rings.length(); int count=0;
        vector<int> red(10,0); vector<int>blue(10,0); vector<int> green(10,0);
        for(int i=0;i<n;i+=2){
            int color=rings[i];
            int rod=rings[i+1]-'0';
            if (color=='R') red[rod]++;
            else if (color=='G') green[rod]++;
            else if (color=='B') blue[rod]++;
        }
        for(int i=0;i<10;i++){
            if (red[i]>0 && green[i]>0 && blue[i]>0) count++;
        }
        return count;
    }
};
int main(){
    Solution s;
    cout<<s.countPoints("B0B6G0R6R0R6G9")<<endl;
    return 0;
}