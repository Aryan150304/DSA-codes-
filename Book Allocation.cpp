/* The problem of Book allocation focussed on concepts of binary search and was available on code studio 
problem link - https://www.codingninjas.com/codestudio/problems/allocate-books_1090540?leftPanelTab=0
*/
#include <bits/stdc++.h> 
bool isPossible(vector<int>arr, int n , int mid , int m){
    int pageCount =0;
    int sizeCount =1 ;
    for(int i=0;i<n;i++){
       if(pageCount+arr[i]<=mid){
           pageCount+=arr[i];
       }
        else {
            sizeCount++;
            if(sizeCount>m||arr[i]>mid){
               return false;
            }
            pageCount = arr[i];
        }
    }
    return true ;
}
int allocateBooks(vector<int> arr, int n, int m) {
   // step 1 appply binary search on search space of sum of pages 
    // step 2 decide the solution is acceptable or not 
    int lb =0;
    int ans =-1 ;
    int ub = 0;
    for(int i=0;i<n;i++){
        ub+=arr[i];
    }
    int mid = lb +(ub-lb)/2;
    while(lb<=ub){
        if(isPossible(arr,n,mid,m)){
            ans = mid ;
            ub=mid -1 ;
        }
        else {
            lb = mid + 1 ;
        }
        mid = lb +(ub-lb)/2; 
    }
    return ans;
}
// This problem includes division of array on the basis of binary search
