//! leetcode question 2396. Strictly Palindromic Number

//? link: https://leetcode.com/problems/strictly-palindromic-number/description/

#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        int temp; string base;
        for(int i=2;i<=n-2;i++){
            temp=n; // store n into a temp val so actual n will not affected
            // calculating the base i for value tmp 
            while(temp!=0){
                base+=to_string(temp%i); // for storing the value of each base (2 to n-2)
                temp/=i;
            }
            // check for palindrome
            int s=0,e=base.size()-1;
            while(s<e){
                if(base[s++]!=base[e--]) return false;
            }
            base.clear(); // clear base each time after iteration
        }
        return true;
    }
};
int main(){
    Solution s;
    cout<<s.isStrictlyPalindromic(10)<<endl;
    return 0;
}

//* LOGIC:

/* 
while(temp!=0){
    base+=to_string(temp%i); 
    temp/=i;
}
Inside the loop, temp % i calculates the remainder when temp is divided by i, 
effectively extracting the digits of n in the current base i. 
This remainder is converted to a string using to_string() function and then appended to the base string.

For example, if temp initially holds the value of n, after the first iteration, 
base will contain the least significant digit of n in base i. On subsequent iterations, 
the loop divides temp by i and appends the remainders to base, effectively extracting digits from right to left.
temp/=i : This line divides temp by i, shifting the digits to the right (towards lower significant positions) as the loop progresses.

By iterating through this loop, base string will eventually contain the digits of n in the specified base i. 
This process extracts the digits of n in a specific base by repeatedly finding the remainder when dividing by that base
and appending it to the base string.

* EXAMPLE:
temp = n = 25;
We start with temp set to the value of n.
while (temp) {
    base = base + to_string(temp % i);
    temp /= i;
}

In the first iteration of the loop:
i = 2: We're converting n to base 2.
temp % i = 25 % 2 = 1: The remainder when dividing 25 by 2 is 1.
to_string(1): Converts the remainder to a string, resulting in "1".
base = base + "1": Appends "1" to base.
Now, temp is updated by integer division:

temp /= i becomes temp = temp / i, which is temp = 25 / 2 = 12.
In the second iteration of the loop:

temp % i = 12 % 2 = 0: The remainder when dividing 12 by 2 is 0.
to_string(0): Converts the remainder to a string, resulting in "0".
base = base + "0": Appends "0" to base.
Now, temp is updated:

temp /= i becomes temp = temp / i, which is temp = 12 / 2 = 6.
In the third iteration of the loop:

temp % i = 6 % 2 = 0: The remainder when dividing 6 by 2 is 0.
to_string(0): Converts the remainder to a string, resulting in "0".
base = base + "0": Appends "0" to base.
Now, temp is updated:

temp /= i becomes temp = temp / i, which is temp = 6 / 2 = 3.
In the fourth iteration of the loop:

temp % i = 3 % 2 = 1: The remainder when dividing 3 by 2 is 1.
to_string(1): Converts the remainder to a string, resulting in "1".
base = base + "1": Appends "1" to base.
Now, temp is updated:

temp /= i becomes temp = temp / i, which is temp = 3 / 2 = 1.
In the fifth iteration of the loop:

temp % i = 1 % 2 = 1: The remainder when dividing 1 by 2 is 1.
to_string(1): Converts the remainder to a string, resulting in "1".
base = base + "1": Appends "1" to base.
Now, temp is updated:

temp /= i becomes temp = temp / i, which is temp = 1 / 2 = 0.
Since temp is 0, the loop ends.

After this loop, base will contain "11001", which represents 25 in binary.

This process is repeated for other bases, and then the resulting string base is checked for palindromicity. 
If it's palindromic in all bases, the function returns true, indicating that n is strictly palindromic.

*/