//! leetcode question 621. Task Scheduler (PROBLEM OF THE DAY 19-3-2024)

//? link: https://leetcode.com/problems/task-scheduler/description/?envType=daily-question&envId=2024-03-19

#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26]={0}; // initialized to store the frequency of each task. 
        // Each index corresponds to a character ('A' to 'Z'). Initialized with zeros.

        int maxfreq=0; // This variable will store the maximum frequency of any task.
        int num_max=0; //  This variable will store the number of tasks that have the maximum frequency.

        // Calculate frequencies of each task
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++; 

            // If the current task's count is greater than the current maximum, update max to the new maximum and reset num_max to 1.
            if(freq[tasks[i]-'A']>maxfreq){
                maxfreq=max(maxfreq,freq[tasks[i]-'A']);
                num_max=1;
            }
            
            // If the current task's count = maximum, increment num_max to indicate that there is another task with the same maximum frequency.
            else if(freq[tasks[i]-'A']==maxfreq){
                num_max++;
            }
        }
        // After this loop, max will contain the maximum frequency of any task, 
        // and num_max will contain the number of tasks with that maximum frequency.

        // This part of the code is responsible for checking if there are enough tasks to fill up all the intervals without needing 
        // any idle time. If there are enough tasks, we won't need to insert idle time slots between task executions. 
        // If there aren't enough tasks, we'll need to insert idle time slots to fulfill the cooldown period.
        if(tasks.size()-maxfreq-(num_max-1) > n*(maxfreq-1)){
            return tasks.size();
        }
        return maxfreq+n*(maxfreq-1)+num_max-1;
    }
};
int main(){
    Solution s;
    vector<char> tasks = {'A','A','A','B','B','B'};
    cout<<s.leastInterval(tasks, 2)<<endl;
    return 0;
}


//* LOGIC:

/*
? if(tasks.size()-maxfreq-(num_max-1) > n*(maxfreq-1)):

tasks.size(): Total number of tasks.
maxfreq: Maximum frequency of any task.
num_max: Number of tasks with the maximum frequency.
n: Cooldown period.

-> This part calculates if there are enough tasks to fill up all the intervals without any idle time. 
It checks if the remaining number of tasks after considering the most frequent tasks and their 
frequencies (tasks.size() - maxfreq - (num_max - 1)) is greater than the total time needed for 
cooldown periods between executions of the most frequent task (n * (maxfreq - 1)). If this condition is true, 
it means there are enough tasks to execute without needing any idle time.

return tasks.size();:

-> If there are enough tasks, we return the total number of tasks because they can be executed without needing any idle time.

? return maxfreq + n * (maxfreq - 1) + num_max - 1; :

If there aren't enough tasks to fill up all the intervals without idle time, 
this part calculates the minimum number of intervals required, including idle time between tasks as necessary.

maxfreq: Represents the maximum frequency of any task. This accounts for the executions of the most frequent task.
n * (maxfreq - 1): Represents the total time needed for the cooldown periods between executions of the most frequent task. 
Here, maxfreq - 1 represents the number of intervals between executions, each of length n.
num_max - 1: Represents the number of tasks with the maximum frequency minus one. 
We subtract one because the last task doesn't need to wait for the cooldown.

-> So, this code part essentially checks if there are enough tasks to execute without idle time. 
If there are, it returns the total number of tasks. Otherwise, it calculates the minimum number of intervals required, 
including idle time between tasks as necessary, and returns that value.

*/