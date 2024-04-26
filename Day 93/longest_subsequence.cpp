//! LeetCode Question 2370. Longest Ideal Subsequence (POTD 25-4-2024)

//? link: https://leetcode.com/problems/longest-ideal-subsequence/?envType=daily-question&envId=2024-04-25

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestIdealString(string s, int k) {
        // Declare a vector 'v' of size 26 initialized with zeros
        vector<int> v(26, 0);
        
        // Initialize a variable 'ans' to store the maximum length of the ideal string
        int ans = 0;
        
        // Loop through the characters of the string 's' in reverse order
        for (int i = s.size() - 1; i >= 0; i--) {
            // Initialize a variable 'cnt' to store the maximum count of ideal characters
            int cnt = 0;
            
            // Loop through a range of characters centered around the current character
            // The range is determined by 'k', the maximum allowed distance from the current character
            for (int j = s[i] - 'a' - k; j <= s[i] - 'a' + k; ++j) {
                // Check if the character index 'j' is within the valid range [0, 25]
                if (j >= 0 && j < 26)
                    // Update 'cnt' to the maximum count of ideal characters within the range
                    cnt = max(cnt, v[j]);
            }
            
            // Update the count of the current character 's[i]' to 'cnt + 1' in vector 'v'
            v[s[i] - 'a'] = cnt + 1;
            
            // Update 'ans' to the maximum value between 'ans' and the count of current character
            ans = max(ans, v[s[i] - 'a']);
        }
        
        // Return the maximum length of the ideal string
        return ans;
    }
};
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    Solution ob;
    cout<<ob.longestIdealString(s,k);
    return 0;
}