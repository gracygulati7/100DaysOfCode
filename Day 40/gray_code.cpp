//! leetcode question 89. Gray Code

//? link: https://leetcode.com/problems/gray-code/description/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for(int i=0;i<(1<<n);i++){ // i<(1<<n) ka mtlb hai ki 2^n-1 tak loop chalega
            ans.push_back(i^(i>>1));
            /*
    i >> 1 ka mtlb hai ki i ke binary representation me se last bit ko hata
    do
    For example,
    i = 3
    i ka binary representation = 011
    i >> 1 = 001
    i ^ (i >> 1) = 010
    010 is the gray code of 011
    */
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> ans = s.grayCode(2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/*
For example,
  n = 2
    00
    01
    11
    10
    So, the sequence is [00, 01, 11, 10]
    And humne loop 2^n tak isliye chalaya kyuki as in the above example, we have
  2^2 = 4 numbers
*/