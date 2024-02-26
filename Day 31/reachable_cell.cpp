<<<<<<< HEAD
//! leetcode question 2849. Determine if a Cell Is Reachable at a Given Time

//? link: https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/?envType=daily-question&envId=2024-02-21

#include <iostream>
using namespace std;
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x=abs(sx-fx);
        int y=abs(sy-fy);
        if(x==0 && y==0){
            return t!=1; // if t!=1 return true , false otherwise.
        }
        return x<=t && y<=t; // if x<=t && y<=t both are true then it returns true, false otherwise.
    }
};

int main(){
    Solution s;
    cout<<s.isReachableAtTime(0,0,0,0,1)<<endl;
    cout<<s.isReachableAtTime(0,0,0,0,2)<<endl;
    return 0;
}

//* APPROACH:
/*
First of all, we need to calculate distance from start cell to finish cell 
x distance = abs(sx - fx)
y distance = abs(sy - fy)

NOW, We have two cases to check.

Case 1: start cell and finish cell are the same position
When x distance and y distance are both 0, start cell and finish cell are the same place.  
The description says "Each second, you must move to any of its adjacent cells". 
That means at least we need 2 times to go back to the same cell. So check t!=1.

Case 2: start cell and finish cell are different positions
This is a simple case. Just check x distance <= t and y distance <= t. 
If we meet the condition, we can return true, if not return false.
=======
//! leetcode question 2849. Determine if a Cell Is Reachable at a Given Time

//? link: https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/?envType=daily-question&envId=2024-02-21

#include <iostream>
using namespace std;
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x=abs(sx-fx);
        int y=abs(sy-fy);
        if(x==0 && y==0){
            return t!=1; // if t!=1 return true , false otherwise.
        }
        return x<=t && y<=t; // if x<=t && y<=t both are true then it returns true, false otherwise.
    }
};

int main(){
    Solution s;
    cout<<s.isReachableAtTime(0,0,0,0,1)<<endl;
    cout<<s.isReachableAtTime(0,0,0,0,2)<<endl;
    return 0;
}

//* APPROACH:
/*
First of all, we need to calculate distance from start cell to finish cell 
x distance = abs(sx - fx)
y distance = abs(sy - fy)

NOW, We have two cases to check.

Case 1: start cell and finish cell are the same position
When x distance and y distance are both 0, start cell and finish cell are the same place.  
The description says "Each second, you must move to any of its adjacent cells". 
That means at least we need 2 times to go back to the same cell. So check t!=1.

Case 2: start cell and finish cell are different positions
This is a simple case. Just check x distance <= t and y distance <= t. 
If we meet the condition, we can return true, if not return false.
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
*/