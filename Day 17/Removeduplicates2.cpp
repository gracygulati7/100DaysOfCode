<<<<<<< HEAD
//! remove duplicates from sorted array 2
//! leetcode question 80

//? link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 1; // k is starting index of modified array and will store number of elements in array that occurs at most 2 times.
        int count = 1; // this will store how many times each element occcurs in array.
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) { 
                count++; // if current element = previous element then count increases.
            } else {
                count = 1; // if there current element occurs only 1 time in array so its count will be 1.
            }

            if (count <= 2) { // it checks for those elements that occurs at most twice in array.
                nums[k] = nums[i]; // then it places those elements at the start of the array 
                k++; // index shifts to next position to check for other elements and add them.
            }
        }
        return k; // now this will return last index of those elements that occurs at most twice in array 
                  // or u may say it stores count of elements that occurs at most twice in array.
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    cout << "Enter the elements of the array (-1 to end input):" << endl;
    int num;
    while (cin >> num && num != -1) {
        nums.push_back(num);
    }
    int length = solution.removeDuplicates(nums);
    cout << "Modified array after removing duplicates: [";
    for (int i = 0; i < length; i++) {
        cout << nums[i];
        if (i < length - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}
=======
//! remove duplicates from sorted array 2
//! leetcode question 80

//? link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 1; // k is starting index of modified array and will store number of elements in array that occurs at most 2 times.
        int count = 1; // this will store how many times each element occcurs in array.
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) { 
                count++; // if current element = previous element then count increases.
            } else {
                count = 1; // if there current element occurs only 1 time in array so its count will be 1.
            }

            if (count <= 2) { // it checks for those elements that occurs at most twice in array.
                nums[k] = nums[i]; // then it places those elements at the start of the array 
                k++; // index shifts to next position to check for other elements and add them.
            }
        }
        return k; // now this will return last index of those elements that occurs at most twice in array 
                  // or u may say it stores count of elements that occurs at most twice in array.
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    cout << "Enter the elements of the array (-1 to end input):" << endl;
    int num;
    while (cin >> num && num != -1) {
        nums.push_back(num);
    }
    int length = solution.removeDuplicates(nums);
    cout << "Modified array after removing duplicates: [";
    for (int i = 0; i < length; i++) {
        cout << nums[i];
        if (i < length - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
