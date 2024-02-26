<<<<<<< HEAD
#include <bits/stdc++.h> 
using namespace std;
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	int i=0,j=0;
	vector<int> result;
	while(i<n && j<m){
		if(arr1[i]==arr2[j]){
			result.push_back(arr1[i]);
			i++;
			j++;
		}
		else if(arr1[i]<arr2[j]){
			i++;
		}
		else{
			j++;
		}
	}
	return result;
}


// link for question:
=======
#include <bits/stdc++.h> 
using namespace std;
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	int i=0,j=0;
	vector<int> result;
	while(i<n && j<m){
		if(arr1[i]==arr2[j]){
			result.push_back(arr1[i]);
			i++;
			j++;
		}
		else if(arr1[i]<arr2[j]){
			i++;
		}
		else{
			j++;
		}
	}
	return result;
}


// link for question:
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
// https://www.codingninjas.com/studio/problems/intersection-of-2-arrays_1082149