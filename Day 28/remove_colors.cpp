//! leetcode question 2038. Remove Colored Pieces if Both Neighbors are the Same Color

//? link: https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/?envType=daily-question&envId=2024-02-21

#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size(); int scoreA=0, scoreB=0;
        if(n<=2) return false;
        for(int i=1;i<n-1;i++){
            if(colors[i+1]==colors[i] && colors[i-1]==colors[i]){
                if(colors[i]=='A'){
                    scoreA++;
                }
                else{
                    scoreB++;
                }
            }
        }
        return scoreA>scoreB;
    }
};

int main() {
    Solution solution;
    cout << solution.winnerOfGame("BBBAAAABB") << endl;  
    return 0;
}