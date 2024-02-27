//! leetcode question 2086. Minimum Number of Food Buckets to Feed the Hamsters

//? link : https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters/description/

#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int minimumBuckets(string hamsters) {
        int n=hamsters.length();
        int food=0;
        for (int i=0;i<n;) {
            if (hamsters[i]=='H') {
                if(i+1<n && hamsters[i+1]=='.'){
                    food++; i+=3;
                }
                else if(i-1>=0 && hamsters[i-1]=='.'){
                    food++; i++;
                }
                else{
                    return -1;
                }
            }
            else{
                i++;
            }
        }
        return food;
    }
};
int main(){
    Solution s;
    cout<<s.minimumBuckets("H.H.H.H.");
    return 0;
}