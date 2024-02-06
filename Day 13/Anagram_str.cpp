#include <iostream>
#include <string>
using namespace std;
int remAnagram(string str1, string str2) {
    string remove = "";
    int n = str1.length(), m = str2.length();
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (str1[i] == str2[j]) {
                found = true;
                str2.erase(j, 1);
                break;
            }
        }
        if (!found) {
            remove += str1[i];
        }
    }
    remove += str2;
    return remove.length();
}
int main() {
    string str1, str2;
    cout << "Enter the first string: ";
    getline(cin, str1);
    cout << "Enter the second string: ";
    getline(cin, str2);
    int result = remAnagram(str1, str2);
    cout << "Minimum number of characters to be deleted: " << result << endl;
    return 0;
}

// https://practice.geeksforgeeks.org/problems/anagram-of-string/1?page=1&difficulty[]=-1&category[]=Strings&sortBy=submissions