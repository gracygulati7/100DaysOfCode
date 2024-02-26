//! find maximum occuring character

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    char getMaxOccuringChar(string str) {
        int maxCount = 0;
        char result = '\0'; 
        for (int i = 0; i < str.length(); i++) {
            int count = 1; 
            for (int j = i + 1; j < str.length(); j++) {
                if (str[i] == str[j]) {
                    count++;
                }
            }
            if (count > maxCount || (count == maxCount && str[i] < result)) {
                maxCount = count;
                result = str[i];
            }
        }
        return result;
    }
};
int main() {
    Solution solution;
    cout << "Enter a string: ";
    string inputString;
    cin >> inputString;
    char result = solution.getMaxOccuringChar(inputString);
    cout << "The maximum occurring character is: " << result << endl;
    return 0;
}

// https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1?page=1&difficulty[]=-1&category[]=Strings&sortBy=submissions