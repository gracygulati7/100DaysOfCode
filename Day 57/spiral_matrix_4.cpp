//! leetcode question 2326. Spiral Matrix IV

//? link: https://leetcode.com/problems/spiral-matrix-iv/description/

#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m,vector<int>(n,-1)); // This creates a 2D vector ans of size m x n initialized with -1
        int r1=0,r2=m-1,c1=0,c2=n-1;
        while((r1<=r2 && c1<=c2) && head!=NULL){

            // top
            for(int i=c1;i<=c2 && head;i++){
                res[r1][i]=head->val;
                head=head->next;
            }
            r1++; // because top row is r1

            // right 
            for(int i=r1;i<=r2 && head;i++){
                res[i][c2]=head->val;
                head=head->next;
            }
            c2--; // because right column is c2

            // bottom
            for(int i=c2;i>=c1 && head;i--){
                res[r2][i]=head->val;
                head=head->next;
            }
            r2--; // because bottom row is r2

            // left
            for(int i=r2;i>=r1 && head;i--){
                res[i][c1]=head->val;
                head=head->next;
            }
            c1++; // because left column is c1
        }
        return res;
    }
};

int main() {
    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int m = 3;
    int n = 3;
    Solution sol;
    vector<vector<int>> spiral = sol.spiralMatrix(m, n, head);
    cout << "Spiral Matrix:" << endl;
    for (int i = 0; i < spiral.size(); ++i) {
        for (int j = 0; j < spiral[i].size(); ++j) {
            cout << spiral[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}