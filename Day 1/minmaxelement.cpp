#include <iostream>
#include <climits>
using namespace std;
class Solution {
public:
    int findSum(int A[], int N) {
        int maxno = INT_MIN;
        int minno = INT_MAX;
        for (int i = 0; i < N; i++) {
            maxno = max(maxno, A[i]);
            minno = min(minno, A[i]);
        }
        int sum = maxno + minno;
        return sum;
    }
};
int main() {
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;

    int A[N];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    Solution obj;
    int result = obj.findSum(A, N);
    cout << "Sum of the maximum and minimum elements in the array: " << result <<   endl;
    return 0;
}

// link for ques: 
// https://www.geeksforgeeks.org/problems/max-min/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article