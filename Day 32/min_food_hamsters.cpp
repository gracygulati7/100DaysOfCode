//! leetcode question 2086. Minimum Number of Food Buckets to Feed the Hamsters

//? link: https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters/description/

#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int minimumBuckets(string hamsters) {
        int n=hamsters.length();
        int food=0;
        for (int i=0;i<n;) {
            if (hamsters[i]=='H') { // Check if the current character is 'H', indicating the presence of a hamster.
                if(i+1<n && hamsters[i+1]=='.'){ // Check if there is an empty spot to the right of the hamster.
                    food++; // If true, increment the food counter to indicate placing a food bucket to feed the hamster.
                    i+=3; // Move three positions to the right after placing a food bucket 
// bcoz at i+1 we already placed at bucket, so then we will move to i+3 and check if there is a hamster or not coz if there will be then 
// we will check for empty space at i-1 (which is i+2 in case of jump) and i+1
                }                 
                else if(i-1>=0 && hamsters[i-1]=='.'){ // If there is no empty spot to the right,check if there is an empty spot to the left of the hamster.
                    food++; // If true, increment the food counter to indicate placing a food bucket to feed the hamster.
                    i++; // Move one position to the right after placing a food bucket
                }
                else{
                    return -1; // No empty spot on either side, so it's impossible to feed all hamsters
                }
            }
            else{
                i++;  // If the current character is not 'H', increment i to move to the next position in the string.
            }
        }
        return food;
    }
};
int main(){
    Solution s;
    cout<<s.minimumBuckets("H..H")<<endl;
    return 0;
}