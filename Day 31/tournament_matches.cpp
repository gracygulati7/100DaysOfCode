//! leetcode question 1688. Count of Matches in Tournament

//? link: https://leetcode.com/problems/count-of-matches-in-tournament/?envType=daily-question&envId=2024-02-24

#include <iostream>
using namespace std;
class Solution {
public:
    int numberOfMatches(int n) {
        int sum=0,matches=0;
        while(n>1){
            if(n%2==0){
                matches=n/2;
                n=n/2;
            }
            else{
                matches=(n-1)/2;
                n=(n-1)/2+1;
            }
            sum+=matches;
        }
    return sum;      
    }
};
int main(){
    Solution s;
    cout<<s.numberOfMatches(5)<<endl;
    return 0;
}