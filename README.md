# 100DaysOfCode
```
Pairs: 
total pairs in an array of n elements = (n(n-1))/2
eg- arr=[2,4,6,8]
pairs of 2= (2,4), (2,6), (2,8)
pairs of 4= (4,6), (4,8)
pairs of 6= (6,8)
total pairs= (4*3)/2= 6 pairs
logic-
start-> for int i=0 to `i<n`
int curr=arr[i]
end-> for int j=i+1 to `j<n`
pairs= (curr,arr[j])
```
```
# subarray - continuous part of array. 
eg- arr=[2,4,6,8]
subarrays of 2= (2), (2,4), (2,4,6), (2,4,6,8)
subarrays of 4= (4), (4,6), (4,6,8)
subarrays of 6= (6), (6,8)
subarrays of 8= (8)
logic-
start-> for int i=0 to `i<n`
int start=i
end-> for int j=i to `j<n`  // starts from i bcz in subarray we also take the digit to be paired by itself
int end=j
for(int k=start to k<=end)
print arr[k]
```