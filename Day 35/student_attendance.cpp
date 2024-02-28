//! leetcode question 551. Student Attendance Record I

//? link: https://leetcode.com/problems/student-attendance-record-i/description/

#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool checkRecord(string s) {
        int n=s.length(); int acount=0,lcount=0;
        for(int i=0;i<n;i++){
            if(s[i]=='A'){
                acount++;
            }
            if(s[i]=='L'){
                lcount++;
            }
            else{
                lcount=0;
            }
            if(acount>=2 || lcount>=3){
                return false;
            }
        }
        return true;
    }
};
int main(){
    Solution s;
    cout<<s.checkRecord("PPALLP")<<endl;
    return 0;
}