//! leetcode question 2124. Check if All A's Appears Before All B's

//? link: https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/description/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool checkString(string s) {
        int n=s.length(); vector<char> store;
        for(int i=0;i<n;i++){
            store.push_back(s[i]);
        }
        vector<char> result=store;
        sort(store.begin(),store.end());
        if(result==store) return true;
        return false;
    }
};
int main(){
    Solution s;
    cout<<s.checkString("ab")<<endl;
    return 0;
}