#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
class Solution {
public:
    bool check(vector<ll> A, vector<ll> B, int N) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for (int i = 0; i < N; i++) {
            if (A[i] != B[i]) {
                return false;
            }
        }
        return true;
    }
};
int main() {
    int N;
    cout << "Enter the size of the arrays: ";
    cin >> N;
    vector<ll> A(N), B(N);
    cout << "Enter elements of the first array: ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << "Enter elements of the second array: ";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    Solution obj;
    if (obj.check(A, B, N)) {
        cout << "The arrays are equal." << endl;
    } else {
        cout << "The arrays are not equal." << endl;
    }
    return 0;
}
