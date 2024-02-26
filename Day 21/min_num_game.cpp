<<<<<<< HEAD
//! leetcode question 2974. Minimum Number Game

//? link: https://leetcode.com/problems/minimum-number-game/description

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        sort(nums.begin(), nums.end()); // sorting the array to get minimum elements
        for (int i = 0; i < n - 1; i += 2) { 
            // here instead of i++ we are doing i+=2 coz we want to skip 2 indexes bcoz 2 elements are added and after they have been added 
            // we want next two least elements to get added in the array.
            int aliceMove = nums[i]; 
            int bobMove = nums[i + 1];
            arr.push_back(bobMove);
            arr.push_back(aliceMove);
        }
        return arr;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution solution;
    vector<int> result = solution.numberGame(nums);
    cout << "Result after the game: ";
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
=======
//! leetcode question 2974. Minimum Number Game

//? link: https://leetcode.com/problems/minimum-number-game/description

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        sort(nums.begin(), nums.end()); // sorting the array to get minimum elements
        for (int i = 0; i < n - 1; i += 2) { 
            // here instead of i++ we are doing i+=2 coz we want to skip 2 indexes bcoz 2 elements are added and after they have been added 
            // we want next two least elements to get added in the array.
            int aliceMove = nums[i]; 
            int bobMove = nums[i + 1];
            arr.push_back(bobMove);
            arr.push_back(aliceMove);
        }
        return arr;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution solution;
    vector<int> result = solution.numberGame(nums);
    cout << "Result after the game: ";
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
