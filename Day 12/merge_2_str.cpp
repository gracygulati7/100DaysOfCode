#include <iostream>
#include <vector>
#include <string>
using namespace std;
string merge(string S1, string S2) {
    vector<char> result;
    int start = 0, end = S1.length() - 1;
    int left = 0, right = S2.length() - 1;
    while (left <= right && start <= end) {
        result.push_back(S1[start]);
        result.push_back(S2[left]);
        left++;
        start++;
    }
    while (start <= end) {
        result.push_back(S1[start]);
        start++;
    }
    while (left <= right) {
        result.push_back(S2[left]);
        left++;
    }
    return string(result.begin(), result.end());
}
int main() {
    string input1, input2;
    cout << "Enter the first string: ";
    getline(cin, input1);
    cout << "Enter the second string: ";
    getline(cin, input2);
    string result = merge(input1, input2);
    cout << "Merged string: " << result << endl;
    return 0;
}

// https://practice.geeksforgeeks.org/problems/merge-two-strings2736/1?page=1&difficulty[]=-1&category[]=Strings&sortBy=submissions