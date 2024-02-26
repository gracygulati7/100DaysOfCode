<<<<<<< HEAD
//! leetcode question 1704. Determine if String Halves Are Alike

//? link: https://leetcode.com/problems/determine-if-string-halves-are-alike/description/?envType=daily-question&envId=2024-02-17

#include<iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int mid = n / 2;  
        int counta = 0, countb = 0;
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    if (i < mid) {
                        counta++;
                    } else {
                        countb++;
                    }
                    break;
            }
        }
        return counta == countb;
    }
};
=======
//! leetcode question 1704. Determine if String Halves Are Alike

//? link: https://leetcode.com/problems/determine-if-string-halves-are-alike/description/?envType=daily-question&envId=2024-02-17

#include<iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int mid = n / 2;  
        int counta = 0, countb = 0;
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    if (i < mid) {
                        counta++;
                    } else {
                        countb++;
                    }
                    break;
            }
        }
        return counta == countb;
    }
};
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
