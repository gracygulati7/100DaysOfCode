<<<<<<< HEAD
//! leetcode question 2109. Adding Spaces to a String

//? link: https://leetcode.com/problems/adding-spaces-to-a-string/description/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n=s.length(); int m=spaces.size(); string result="";
        int i=0,j=0;
        while(i<n){
            if(j<m && i==spaces[j]){
                result+=' ';
                j++;
            }
            result+=s[i];
            i++;
        }
        return result;
    }
=======
//! leetcode question 2109. Adding Spaces to a String

//? link: https://leetcode.com/problems/adding-spaces-to-a-string/description/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n=s.length(); int m=spaces.size(); string result="";
        int i=0,j=0;
        while(i<n){
            if(j<m && i==spaces[j]){
                result+=' ';
                j++;
            }
            result+=s[i];
            i++;
        }
        return result;
    }
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
};