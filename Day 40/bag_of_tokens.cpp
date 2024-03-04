//! leetcode question 948. Bag of Tokens
//! PROBLEM OF THE DAY 4-3-2024

//? link: https://leetcode.com/problems/bag-of-tokens/description/?envType=daily-question&envId=2024-03-04

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n=tokens.size(); int score=0, maxscore=0, left=0,right=n-1;
        while(left<=right){
            if(power>=tokens[left]){
                power-=tokens[left];
                score+=1; left+=1;
                maxscore=max(maxscore,score);
            }
            else if(score>0){
                power+=tokens[right];
                score-=1; right-=1;
            }
            else break;
        }
        return maxscore;
    }
};
int main(){
    Solution s;
    vector<int> tokens={1,2,3,4,5,6,7,8,9,10};
    cout<<s.bagOfTokensScore(tokens,10)<<endl;
    return 0;
}