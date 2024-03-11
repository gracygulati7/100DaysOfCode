//! leetcode question 791. Custom Sort String (PROBLEM OF THE DAY 11-3-2024)

//? link: https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-03-11

#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string customSortString(string order, string s) {
        int n=order.length(),m=s.length(); string res="";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(order[i]==s[j]){
                    res+=s[j];
                    s[j]='1';
                }
            }
        }
        for(int j=0;j<m;j++){
            if(s[j]!='1'){
                res+=s[j];
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    cout<<s.customSortString("cba", "abcd")<<endl;
    return 0;
}