<<<<<<< HEAD
#include <iostream>
using namespace std;
class Solution {
public:
    string removeDuplicates(string str) {
        int n = str.length();
        string res = "";
        for (int i = 0; i < n; i++) {
            if (res.find(str[i]) == string::npos) {
                res += str[i];
            }
        }
        return res;
    }
};
int main() {
    Solution sol;
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    string result = sol.removeDuplicates(str);
    cout << "String after removing duplicates: " << result << endl;
    return 0;
}

=======
#include <iostream>
using namespace std;
class Solution {
public:
    string removeDuplicates(string str) {
        int n = str.length();
        string res = "";
        for (int i = 0; i < n; i++) {
            if (res.find(str[i]) == string::npos) {
                res += str[i];
            }
        }
        return res;
    }
};
int main() {
    Solution sol;
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    string result = sol.removeDuplicates(str);
    cout << "String after removing duplicates: " << result << endl;
    return 0;
}

>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://practice.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1?page=1&difficulty[]=0&category[]=Strings&sortBy=submissions