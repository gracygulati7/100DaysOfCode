//! leetcode question 1700. Number of Students Unable to Eat Lunch (PROBLEM OF THE DAY 8-4-2024)

//? link: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/?envType=daily-question&envId=2024-04-08

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        bool del = true;  // del is used to check if any student is unable to eat lunch

        // While del is true we will check if any student is unable to eat lunch
        while (del==true) {
            // marking del as false initially for each student
            del = false;
            for (int i = 0; i < students.size(); i++) {

                // If student[i] == sandwiches[0] then student[i] can eat the sandwiches[0]
                if (students[i] == sandwiches[0]) {

                    // This will remove the student[i] from the students vector as he/she has eaten the sandwiches[0]
                    students.erase(students.begin() + i);
                    // students.begin() + i because we want to remove the student[i] from the students  vector not the first element
                    i--;

                    // It will remove the first element of the sandwiches vector as it has been eaten by the student[i]
                    sandwiches.erase(sandwiches.begin());
                    // sandwiches.begin() because we want to remove the first element of the sandwiches vector,
                    // del = true means student ate the lunch and now it has been deleted from student vector
                    del = true;
                }
            }
        }
        //  students.size() will return the number of students who are unable to eat lunch as the students vector 
        // will have the students who are unable to eat lunch.
        return students.size();
    }
};
int main() {
    Solution s;
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};
    cout << s.countStudents(students, sandwiches) << endl;
    return 0;
}