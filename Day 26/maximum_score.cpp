<<<<<<< HEAD
//! leetcode question 1422. Maximum Score After Splitting a String

//? link: https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2024-02-19

#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int maxScore = 0;
        // Count the number of ones in the whole string
        int totalOnes = count(s.begin(), s.end(), '1');
        // Initialize variables leftZeros and rightOnes to keep track of the count of zeros on the left and ones on the right, respectively.
        int leftZeros = 0;
        int rightOnes = totalOnes;
        // Iterate through the string, excluding the last character
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                leftZeros++;
            } else {
                rightOnes--;
            }
// Inside the loop, update leftZeros and rightOnes based on the current character. If the current character is '0', increment leftZeros; 
// otherwise, decrement rightOnes.
            // Calculate the current score
            int currentScore = leftZeros + rightOnes;
            // Update the maximum score if the current score is greater
            maxScore = max(maxScore, currentScore);
        }
        return maxScore;
    }
};
=======
//! leetcode question 1422. Maximum Score After Splitting a String

//? link: https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2024-02-19

#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int maxScore = 0;
        // Count the number of ones in the whole string
        int totalOnes = count(s.begin(), s.end(), '1');
        // Initialize variables leftZeros and rightOnes to keep track of the count of zeros on the left and ones on the right, respectively.
        int leftZeros = 0;
        int rightOnes = totalOnes;
        // Iterate through the string, excluding the last character
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                leftZeros++;
            } else {
                rightOnes--;
            }
// Inside the loop, update leftZeros and rightOnes based on the current character. If the current character is '0', increment leftZeros; 
// otherwise, decrement rightOnes.
            // Calculate the current score
            int currentScore = leftZeros + rightOnes;
            // Update the maximum score if the current score is greater
            maxScore = max(maxScore, currentScore);
        }
        return maxScore;
    }
};
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
