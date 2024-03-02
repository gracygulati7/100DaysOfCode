//! leetcode question 1947. Maximum Compatibility Score Sum

//? link: https://leetcode.com/problems/maximum-compatibility-score-sum/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m=students.size(); // Gets the number of students/mentors (m).
         int n=students[0].size(); // Gets the number of questions/answers (n) by accessing the size of the first student's/mentor's answers
         int maxscore=0; // initializes the variable maxScore to keep track of the maximum compatibility score sum.
        vector<bool>used(m,false); // Initializes a boolean vector used of size m to keep track of which mentors have been assigned to students.
        backtrack(0,m,n,students,mentors,used,0,maxscore); // Call the recursive backtrack function to explore all possible pairings
        return maxscore;
    }
    void backtrack(int i,int m,int n,vector<vector<int>>& students,vector<vector<int>>& mentors,vector<bool>& used, int currscore,int& maxscore){
    // Checks if all students have been assigned mentors. 
    // If true, updates maxScore with the maximum compatibility score sum found so far and returns.    
        if(i==m){
            maxscore=max(maxscore,currscore);
            return;
        }
        for(int j=0;j<m;j++){ // Iterates through each mentor to find the best pairing for the current student.
            if(!used[j]){ // Checks if the current mentor j is not already assigned to a student.
                used[j]=true; // Marks the current mentor j as assigned to a student.
                int score=0; //  Initializes the compatibility score for the current pairing.
                for(int k=0;k<n;k++){ //  Iterates through each question and compares the answers of the current student and mentor.
                    if(students[i][k]==mentors[j][k]){ //  If the answers are the same, increment the compatibility score.
                        score++;
                    }
                }
                backtrack(i+1,m,n,students,mentors,used,currscore+score,maxscore); // Recursive call to explore pairings for the next student.
                used[j]=false; // Backtrack: unassign the mentor for the next iteration
            }
        }
    }
};

//* WHY WE PASSED maxscore by reference and if we didn't do this, then why wont it produce correct results?
/*
when a parameter is passed by reference (int& maxScore), any changes made to the parameter inside the function will be reflected outside 
the function. This is important in this case because we want to keep track of the maximum compatibility score across all possible pairings.
If maxScore were passed by value (not by reference), each recursive call to backtrack would operate on a local copy of maxScore, and any 
updates to it wouldn't affect the original variable. By passing it by reference, we ensure that all recursive calls share the same variable, 
allowing us to keep track of the maximum compatibility score accurately.
*/