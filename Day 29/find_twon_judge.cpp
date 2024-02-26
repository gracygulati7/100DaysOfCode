<<<<<<< HEAD
//! leetcode question 997. Find the Town Judge
//* Problem of the Day 22-02-2024

//? link: https://leetcode.com/problems/find-the-town-judge/?envType=daily-question&envId=2024-02-22

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustcount(n+1,0);
        for(int i=0;i<trust.size();i++){
            int a=trust[i][0];
            int b=trust[i][1];
            trustcount[a]--; // Decrement trust count for the person who trusts
            trustcount[b]++; // Increment trust count for the person who is trusted
        }
        for(int i=1;i<=n;i++){
            if(trustcount[i]==n-1){
                return i; // This person is the town judge
            }
        }
    return -1; // in case no town judge is found
    }
};
=======
//! leetcode question 997. Find the Town Judge
//* Problem of the Day 22-02-2024

//? link: https://leetcode.com/problems/find-the-town-judge/?envType=daily-question&envId=2024-02-22

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustcount(n+1,0);
        for(int i=0;i<trust.size();i++){
            int a=trust[i][0];
            int b=trust[i][1];
            trustcount[a]--; // Decrement trust count for the person who trusts
            trustcount[b]++; // Increment trust count for the person who is trusted
        }
        for(int i=1;i<=n;i++){
            if(trustcount[i]==n-1){
                return i; // This person is the town judge
            }
        }
    return -1; // in case no town judge is found
    }
};
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
