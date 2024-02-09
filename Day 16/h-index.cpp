//! H-Index 
//! Leetcode Question 274:

//* LOGIC :
//* The goal is to find the maximum value of h such that there are at least h papers with at least h citations each.
//* In the context of the h-index calculation:
//* The h-index is the maximum value h such that there are at least h papers with at least h citations each.
//* The condition is satisfied if there are at least h papers with at least h citations each, 
//* and it's not necessary to have exactly h papers with exactly h citations.
//* Example : [1, 1, 3]:
//* The h-index is 1 because there is at least 1 paper with at least 1 citation.
//* even if we have 2 papers with at max 1 citation each but we need the (number of papers = number of citations) so least is considered.

//? link: https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int ans=0;
        int s=0, e=n-1;
        while (s<=e) {
            int mid=(s+e)/2;
            int count=n-mid; // Count of papers with at least citations[mid] citations
            if (citations[mid]>=count) {
                // If the current paper has at least count citations, update the answer
                ans=count;
                e=mid-1; // Check the left half for a higher h-index
            } else {
                s=mid+1; // Check the right half for a higher h-index
            }
            // If the current paper has at least count citations, it means there are at least count papers with at least count citations each. 
            // The answer is updated to count, and the left half is searched for a higher h-index.
            // If the current paper has fewer citations than count, it means we need to search the right half for a higher h-index.
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of papers: ";
    cin >> n;
    vector<int> citations(n);
    cout << "Enter the number of citations for each paper: ";
    for (int i = 0; i < n; ++i) {
        cin >> citations[i];
    }
    int result = solution.hIndex(citations);
    cout << "The h-index is: " << result << endl;
    return 0;
}
