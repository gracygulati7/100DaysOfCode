#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> doUnion(int a[], int n, int b[], int m) {
        set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(a[i]);
        }
        for (int i = 0; i < m; i++) {
            s.insert(b[i]);
        }
        vector<int> vec(s.begin(), s.end());
        return vec;
    }
};
int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        int n, m;
        cout << "Enter the size of array a: ";
        cin >> n;
        int a[n];
        cout << "Enter the elements of array a: ";
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << "Enter the size of array b: ";
        cin >> m;
        int b[m];
        cout << "Enter the elements of array b: ";
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        Solution obj;
        vector<int> result = obj.doUnion(a, n, b, m);
        cout << "Union of arrays a and b: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

