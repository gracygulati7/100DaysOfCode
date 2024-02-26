<<<<<<< HEAD
//! leetcode question 1921. Eliminate Maximum Number of Monsters

//? link: https://leetcode.com/problems/eliminate-maximum-number-of-monsters/submissions/1183846636/?envType=daily-question&envId=2024-02-23

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();  vector<float> time;
        for(int i=0;i<n;i++){
            time.push_back((float)dist[i]/speed[i]); // arrival time of monsters
        }
        sort(time.begin(),time.end());
        int result=0, currtime=0; // result is how many monsters have been eliminated 
        // currtime is the time at which we are killing the monsters and the time at which weapon is getting charged.
        for(int i=0;i<time.size();i++){
            if(currtime>=time[i]){ // if currtime>=arrival time of monsters means mere marne se phle hi monster aagya
                return result; // then return result means return how many monsters i have eliminated so far.
            } 
            result++; // or increment count of monsters i have killed
            currtime++; // increment the time of charging weapon after i've killed a monster
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<int> dist = {1,2,3,4};
    vector<int> speed = {1,2,3,4};
    cout<<s.eliminateMaximum(dist, speed)<<endl;
    return 0;
=======
//! leetcode question 1921. Eliminate Maximum Number of Monsters

//? link: https://leetcode.com/problems/eliminate-maximum-number-of-monsters/submissions/1183846636/?envType=daily-question&envId=2024-02-23

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();  vector<float> time;
        for(int i=0;i<n;i++){
            time.push_back((float)dist[i]/speed[i]); // arrival time of monsters
        }
        sort(time.begin(),time.end());
        int result=0, currtime=0; // result is how many monsters have been eliminated 
        // currtime is the time at which we are killing the monsters and the time at which weapon is getting charged.
        for(int i=0;i<time.size();i++){
            if(currtime>=time[i]){ // if currtime>=arrival time of monsters means mere marne se phle hi monster aagya
                return result; // then return result means return how many monsters i have eliminated so far.
            } 
            result++; // or increment count of monsters i have killed
            currtime++; // increment the time of charging weapon after i've killed a monster
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<int> dist = {1,2,3,4};
    vector<int> speed = {1,2,3,4};
    cout<<s.eliminateMaximum(dist, speed)<<endl;
    return 0;
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
}