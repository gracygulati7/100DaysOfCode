<<<<<<< HEAD
#include <iostream>
#include <vector>
using namespace std;
vector<int> reverseArray(int n, vector<int> &nums) {
    int start=0 , end=n - 1;
    while (start <= end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
    return nums;
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    reverseArray(n, nums);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}

// link for the question :
=======
#include <iostream>
#include <vector>
using namespace std;
vector<int> reverseArray(int n, vector<int> &nums) {
    int start=0 , end=n - 1;
    while (start <= end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
    return nums;
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    reverseArray(n, nums);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}

// link for the question :
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://www.codingninjas.com/studio/problems/reverse-an-array_8365444