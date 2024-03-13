//! leetcode question 2485. Find the Pivot Integer (PROBLEM OF THE DAY 13-3-2024)

//? link: https://leetcode.com/problems/find-the-pivot-integer/description/?envType=daily-question&envId=2024-03-13

#include <iostream>
using namespace std;
class Solution {
public:
    int pivotInteger(int n) {
        int total=0;
        for(int i=1;i<=n;i++){
            total+=i;
        }
        int sum=0;
        for(int i=0;i<=n;i++){
            sum+=i;
            if((total-sum+i)==sum){
                return i;
            }
        }
        return -1;
    }
};
int main(){
    Solution s;
    cout<<s.pivotInteger(10)<<endl;
    return 0;
}