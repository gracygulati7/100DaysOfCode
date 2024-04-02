//! leetcode question 205. Isomorphic Strings (PROBLEM OF THE DAY 2-4-2024)

//? link: https://leetcode.com/problems/isomorphic-strings/description/?envType=daily-question&envId=2024-04-02

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Two integer arrays map1 and map2 are declared, each with a size of 256. 
        // These arrays are used to store the mapping of characters from strings s and t, respectively. 
        // The size 256 corresponds to the ASCII character set.
        // n is initialized with the size of string s, which is used for looping through the characters of both strings.
        int map1[256]={0} , map2[256]={0} , n=s.size();

        for(int i=0;i<n;i++){ // This is a for loop that iterates through each character of the strings s and t.

        // Within the loop, it checks if the mappings of the current characters s[i] and t[i] are not equal in the arrays m1 and m2. 
        // If they are not equal, it means the characters are not mapped consistently between the two strings, so function returns false, 
        // indicating that the strings are not isomorphic.
            if(map1[s[i]]!=map2[t[i]]) return false;

        // If the mappings of the current characters are equal, it updates the mappings in arrays m1 and m2 with the current index i + 1. 
        // The i + 1 value is used here to differentiate from the default initialization value of 0, ensuring that it doesn't match the 
        // default initialized value. This effectively maps the characters of s to corresponding characters of t and vice versa.
            map1[s[i]]=i+1;
            map2[t[i]]=i+1;
        }
        return true; // After iterating through all characters of both strings without encountering any inconsistency, 
        // the function returns true, indicating that the strings are isomorphic.
    }
};
int main(){
    Solution s;
    cout<<s.isIsomorphic("egg","add")<<endl;
    cout<<s.isIsomorphic("foo","bar")<<endl;
    cout<<s.isIsomorphic("paper","title")<<endl;
}


//* EXAMPLE:
/*
In the code, i + 1 is used to update the mappings in the arrays map1 and map2. 
The purpose of i + 1 is to differentiate the default initialized value of 0. 

Suppose we have two strings:

s = "egg"
t = "add"
We want to check if these two strings are isomorphic.

Initialize two arrays m1 and m2, each of size 256, to store mappings of characters from s to t and from t to s respectively.

Start iterating through each character of the strings s and t:

For the first iteration:
s[0] = 'e' and t[0] = 'a'
m1['e'] and m2['a'] are both 0 (since arrays are initialized with zeros).
So, m1['e'] is updated to 1 and m2['a'] is also updated to 1.

For the second iteration:
s[1] = 'g' and t[1] = 'd'
m1['g'] and m2['d'] are both 0.
So, m1['g'] is updated to 2 and m2['d'] is also updated to 2.

For the third iteration:
s[2] = 'g' and t[2] = 'd'
m1['g'] and m2['d'] are both 2.
So, the condition m1[s[i]] != m2[t[i]] is false.

After iterating through all characters without encountering any inconsistency, the function returns true, 
indicating that the strings "egg" and "add" are indeed isomorphic.

In summary, the characters 'e' in string s can be replaced with 'a' in string t, 
and 'g' in string s can be replaced with 'd' in string t, resulting in isomorphic strings. 
The i + 1 is used simply to update the mapping arrays, it does not affect the correctness of the algorithm.

*/