//! leet question 2942. Find Words Containing Character

//? link: https://leetcode.com/problems/find-words-containing-character/description/

#include <iostream>
#include <vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                if (words[i][j] == x) {
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    int numWords;
    cout << "Enter the number of words: ";
    cin >> numWords;
    vector<string> words(numWords);
    cout << "Enter the words:" << endl;
    for (int i = 0; i < numWords; i++) {
        cin >> words[i];
    }
    char targetChar;
    cout << "Enter the character to find: ";
    cin >> targetChar;
    Solution solution;
    vector<int> result = solution.findWordsContaining(words, targetChar);
    cout << "Words containing '" << targetChar << "': ";
    for (int index : result) {
        cout << words[index] << " ";
    }
    return 0;
}
