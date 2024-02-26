#include <iostream>
#include <vector>
using namespace std;
void segregateElements(int arr[],int n){
        vector<int> result;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                result.push_back(arr[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                result.push_back(arr[i]);
            }
        }
        for(int i=0;i<n;i++){
            arr[i]=result[i];
        }
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    segregateElements(arr, n);
    cout << "Array after segregating positive and negative elements: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}


// link for question:
// https://practice.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1?page=2&difficulty[]=0&category[]=Arrays&sortBy=submissions