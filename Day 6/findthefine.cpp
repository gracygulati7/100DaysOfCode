<<<<<<< HEAD
#include <iostream>
using namespace std;
class Solution {
public:
    long long int totalFine(int n, int date, int car[], int fine[]) {
        long long int sum = 0;
        for (int i = 0; i < n; i++) {
            if ((date % 2 == 0 && car[i] % 2 != 0) || (date % 2 != 0 && car[i] % 2 == 0)) {
                sum += fine[i];
            }
        }
        return sum;
    }
};
int main() {
    Solution solution;
    int n;
    cout << "Enter the number of cars: ";
    cin >> n;
    int date;
    cout << "Enter the date: ";
    cin >> date;
    int car[n];
    cout << "Enter the car numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> car[i];
    }
    int fine[n];
    cout << "Enter the fines: ";
    for (int i = 0; i < n; i++) {
        cin >> fine[i];
    }
    cout << "Total Fine: " << solution.totalFine(n, date, car, fine) << endl;
    return 0;
}


// link for question:
=======
#include <iostream>
using namespace std;
class Solution {
public:
    long long int totalFine(int n, int date, int car[], int fine[]) {
        long long int sum = 0;
        for (int i = 0; i < n; i++) {
            if ((date % 2 == 0 && car[i] % 2 != 0) || (date % 2 != 0 && car[i] % 2 == 0)) {
                sum += fine[i];
            }
        }
        return sum;
    }
};
int main() {
    Solution solution;
    int n;
    cout << "Enter the number of cars: ";
    cin >> n;
    int date;
    cout << "Enter the date: ";
    cin >> date;
    int car[n];
    cout << "Enter the car numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> car[i];
    }
    int fine[n];
    cout << "Enter the fines: ";
    for (int i = 0; i < n; i++) {
        cin >> fine[i];
    }
    cout << "Total Fine: " << solution.totalFine(n, date, car, fine) << endl;
    return 0;
}


// link for question:
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://practice.geeksforgeeks.org/problems/find-the-fine4353/1?page=3&difficulty[]=-1&category[]=Arrays&sortBy=submissions