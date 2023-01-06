/* Code Ninjas problem solution of searching in a sorted rotated array
Link of the problem - https://www.codingninjas.com/codestudio/problem-details/search-in-rotated-sorted-array_1082554
Solution - /* 

#include <bits/stdc++.h> 
int getPivot(vector<int>& arr, int n){
    int lb  = 0 ;
    int ub = n-1 ;
    int mid = lb + (ub-lb)/2;
    while(lb<ub){
        if(arr[mid]>=arr[0]){
            lb = mid + 1 ;
        }
        else {
            ub = mid ;
        }
       mid = lb + (ub-lb)/2;
    }
    return mid ;
}
int binarySearch(vector<int>& arr, int n , int lb , int ub, int elem){
    int mid = lb + (ub-lb)/2;
    while(lb<=ub){
        if(arr[mid]==elem){
            return mid ;
        }
        else if (arr[mid]>elem){
            ub = mid -1 ;
        }
        else {
            lb = mid +1 ;
        }
       mid = lb + (ub-lb)/2;;
    }
    return -1;
}
int findPosition(vector<int>& arr, int n, int k)
{
    // step 1 find pivot 
    int pivot = getPivot(arr,n);
    // step 2 decide where to appply binary search 
    if(arr[pivot]<=k&&k<=arr[n-1]){
       return  binarySearch(arr,n,pivot,n-1,k);
    }
    else {
       return  binarySearch(arr,n,0,pivot-1,k);
    }
    // step 2 apply bs 
    
    
}


// Before understanding the solution, we shall know how to find the pivot element in this array. 
After finding the pivot element we decide the part where binary search is to be applied and hence we apply the binary search in the respective part 
in third step
