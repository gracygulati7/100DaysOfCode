//! leeetcode question 2511. Maximum Enemy Forts That Can Be Captured

//? link: https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/description/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n=forts.size();
        int ans=0; // it will store the maximum count of consecutive zeros encountered around a '1' in the vector.
        for(int i=0;i<n;i++){
            if(forts[i]==1){
                int count=0; // It will be used to count the number of consecutive zeros encountered.
                int j=i-1;
                while(j>=0){ // A while loop is initiated to check the elements to the left of the current '1' (forts[i] == 1).
                    if(forts[j]==0) count++; // If the element is 0, increment the count.
                    else if(forts[j]==-1){ // If the element is -1, update the answer (ans) with the maximum of its current value and count, 
                    // and then break out of the loop.
                        ans=max(ans,count);
                        break;
                    }
                    else if(forts[j]==1) break; // If the element is 1, break out of the loop.
                    j--;
                }
                count=0; // The count is reset to 0, and a while loop is initiated to check the elements to the right
                j=i+1;
// The process is similar to the left loop, updating the count for consecutive zeros and breaking out of the loop if -1 or 1 is encountered.
                while(j<n){
                    if(forts[j]==0) count++;
                    else if(forts[j]==-1){
                        ans=max(ans,count);
                        break;
                    }
                    else if(forts[j]==1) break;
                    j++;
                }
            }
        }
        return ans; // represents the maximum count of consecutive zeros around any '1' in the input vector.
    }
};
int main(){
    Solution s;
    vector<int> forts={1,0,0,-1,0,0,0,0,1};
    cout<<s.captureForts(forts)<<endl;
    return 0;
}