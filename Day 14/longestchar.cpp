<<<<<<< HEAD
//! Longest Substring with Distinct Characters

#include <iostream>
#include <set>
#include <string>
using namespace std;
int longestSubstrDistinctChars(string s) {
  int maxi = 0; // ismein longest substr store hoga
  int i = 0;    // starting index
  int j = 0;    // Ending Index
  set<char> st; // Char present in substr

  while (j < s.size()) {
    if (st.count(s[j]) == 0) { // s[j] is not present in st
      st.insert(s[j]);
      j++;
      maxi = max(maxi, j - i); // maxi ko update krne ke liye = max(maxi, j-i)
                               // because j-i is the length of the substring
    } else {
      st.erase(s[i]); // yeah tab hoga jab s[j] present hai st mein matlab
                      // substring mein repeat hai koi character
      i++;
    }
  }
  return maxi;
}

=======
//! Longest Substring with Distinct Characters

#include <iostream>
#include <set>
#include <string>
using namespace std;
int longestSubstrDistinctChars(string s) {
  int maxi = 0; // ismein longest substr store hoga
  int i = 0;    // starting index
  int j = 0;    // Ending Index
  set<char> st; // Char present in substr

  while (j < s.size()) {
    if (st.count(s[j]) == 0) { // s[j] is not present in st
      st.insert(s[j]);
      j++;
      maxi = max(maxi, j - i); // maxi ko update krne ke liye = max(maxi, j-i)
                               // because j-i is the length of the substring
    } else {
      st.erase(s[i]); // yeah tab hoga jab s[j] present hai st mein matlab
                      // substring mein repeat hai koi character
      i++;
    }
  }
  return maxi;
}

>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1?page=1&difficulty[]=0&category[]=Strings&sortBy=submissions