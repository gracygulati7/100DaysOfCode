#include <iostream>
#include <vector>
using namespace std;
int binarysearch(vector<int> &nums, int target) {
    int N = nums.size();
    int start = 0, end = N - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array in sorted order:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int target;
    cout << "Enter the target element to search: ";
    cin >> target;
    int result = binarysearch(nums, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}
