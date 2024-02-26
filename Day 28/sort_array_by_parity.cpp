<<<<<<< HEAD
//! leetcode question 905. Sort Array By Parity

//? link: https://leetcode.com/problems/sort-array-by-parity/description/?envType=daily-question&envId=2024-02-21

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size(); vector<int> even;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even.push_back(nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                even.push_back(nums[i]);
            }
        }
        return even;
    }
=======
//! leetcode question 905. Sort Array By Parity

//? link: https://leetcode.com/problems/sort-array-by-parity/description/?envType=daily-question&envId=2024-02-21

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size(); vector<int> even;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even.push_back(nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                even.push_back(nums[i]);
            }
        }
        return even;
    }
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
};