//! leetcode question 338. Counting Bits

//? link: https://leetcode.com/problems/counting-bits/description/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans; // Declare a vector to store the result.
        for(int i=0;i<=n;i++){
            // Initialize sum to count the number of set bits (1s) in the binary representation of i. 
            int sum=0;
            int num=i;  // Store the current value of i in a separate variable num.
            while(num!=0){
                // Add the last bit of num to sum. This counts the set bits in the binary representation of i. 
                sum+=num%2; // coz num%2 returns either 0 or 1 and by adding that to sum we can know number of 1's bit for each i.
                // Right shift num by 1 to consider the next bit in the binary representation.
                num/=2; // basically after storing remainder of original i is sum, this statement reduces i to quotient left 
                // after 1st division operation and then performs division until i becomes 0.
            }
            // Add the sum (count of set bits of 1 for each i) to the ans vector.
            ans.push_back(sum);
        }
        // Return the vector containing the count of 1's set bits for each number from 0 to n.
        return ans;
    }
};
int main(){
    Solution s;
    vector<int>ans=s.countBits(5);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//* EXAMPLE:
 /*
 if n=5,
 Loop Execution (0 to 5):
For each i from 0 to 5 (inclusive):
i = 0: Binary representation = 0, Count of set bits = 0
i = 1: Binary representation = 1, Count of set bits = 1
i = 2: Binary representation = 10, Count of set bits = 1
i = 3: Binary representation = 11, Count of set bits = 2
i = 4: Binary representation = 100, Count of set bits = 1
i = 5: Binary representation = 101, Count of set bits = 2
The counts are added to the ans vector.
Output:
The final output will be: "Count of set bits for numbers from 0 to 5: 0 1 1 2 1 2"
 */