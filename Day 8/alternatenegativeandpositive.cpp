//! Alternate positive and negative numbers in an array

#include <bits/stdc++.h>
using namespace std;
void rearrange(int arr[], int n) {
  vector<int> pos;
  vector<int> neg;
  for (int i = 0; i < n; i++) {
    if (arr[i] >= 0) {
      pos.push_back(arr[i]);
    } else {
      neg.push_back(arr[i]);
    }
  }
  int iPos = 0, iNeg = 0, iArr = 0;  // Indexes
  while (iPos < pos.size() &&
         iNeg < neg.size()) {  // Check if both indexes are in vector range
    arr[iArr] = pos[iPos];     // Insert positive number
    iArr++;
    iPos++;
    arr[iArr] = neg[iNeg];
    iArr++;
    iNeg++;
  }
  while (iPos < pos.size()) {  // If negative vector is finished
    arr[iArr++] = pos[iPos++];
  }
  while (iNeg < neg.size()) {
    arr[iArr++] = neg[iNeg++];
  }
}

/*
//*logic:
1. create two vectors pos and neg
2. seperate pos and neg elements from array by pushing pos elements is pos vector and same for neg elements in neg vector.
3. create 3 indices ipos for pos vector, ineg for neg vector and iarr for arr vector and initialize them all with 0 (starting index)
4. take 1st while loop and check whether ipos is in range of pos vector. check same for ineg in neg vector
5. inside loop assign arr[iarr]=pos[ipos] and increment iarr++ and ipos++
6. then do same for neg ie arr[iarr]=neg[ineg] and increment iarr++ and ineg++
7. this will add one pos element and then one neg element inside original array till ipos & ineg are in range of pos and neg vectors.
8. now 2nd while loop ipos in range of pos vector ... arr[iarr]=pos[ipos] then increment iarr++ and ipos++.
9. do same for neg vector in 3rd while loop.
10. this is coz 1st while loop check both if ipos is in range of pos vector & ineg is in range of neg vector and if both are true only then are
the statements inside it are executed.
11. however if neg vector is finished and positive vector still remains then 2nd while loop takes place and vice versa for neg vector.
*/


// link for question:
// https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1?page=2&difficulty[]=0&category[]=Arrays&sortBy=submissions