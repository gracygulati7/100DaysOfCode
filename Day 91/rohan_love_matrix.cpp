//! GeeksForGeeks Question Rohan's Love for Matrix (PROBLEM OF THE DAY 23-4-2024)

//? link: https://www.geeksforgeeks.org/problems/rohans-love-for-matrix4723/1

//* LOGIC: you can see that if we calculate a1,a2,a3... it form sequence of fibonacci series and hence that concept will be used here.

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int firstElement(int n) {
        //  three integers a, b, and c are initialized to 1, 1, and 0 respectively. 
        // These variables are used to represent elements of the matrix. 
        // mod is also defined to be 1000000007, which will be used for modulo arithmetic later in the code.
        int a=1,b=1,c=0; int mod=1000000007;

        // This condition checks if n is either 1 or 2. If so, it returns 1, which corresponds to the first element of the original matrix.
        if(n==1 || n==2) return 1; 

        // This for loop starts from i = 3 and iterates up to n, calculating subsequent powers of the matrix
        for(int i=3;i<=n;i++){
            // Inside the loop, the variable c is calculated as the sum of a and b, modulo mod. 
            // Then, a is updated to the previous value of b, and b is updated to the current value of c. 
            // This process simulates the multiplication of the matrix by itself in each iteration of the loop.
            c=(a+b)%mod;
            a=b;
            b=c;
        }
        return c; // After the loop finishes, the value of c represents the value of a10 in the matrix which is our desired answer. 
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}