#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    reverse(str.begin(), str.end());
    cout << "Reversed string: " << str << endl;
    return 0;
}

//link for question:
//https://www.geeksforgeeks.org/problems/reverse-a-string/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Strings&sortBy=submissions