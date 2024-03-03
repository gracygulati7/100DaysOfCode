//! leetcode question 191. Number of 1 Bits

//? link: https://leetcode.com/problems/number-of-1-bits/description/

#include <iostream>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0; // Initialize a variable 'ans' to store the count of set bits (1s).
        while(n){ // Start a loop that continues until 'n' becomes 0.
            if(n & 1){ // Check if the rightmost bit of 'n' is 1 using the bitwise AND operation
                ans++; // If the rightmost bit is 1, increment the count.
            }
            n=n>>1; // Right-shift 'n' by one position to examine the next bit.
        }
        return ans; // Return the final count of 1's set bits in n.
    }
};
int main(){
    Solution s;
    cout<<s.hammingWeight(00000000000000000000000000001011)<<endl;
    cout<<s.hammingWeight(11111111111111111111111111111101)<<endl;
    cout<<s.hammingWeight(00000000000000000000000010000000)<<endl;
    return 0;
}