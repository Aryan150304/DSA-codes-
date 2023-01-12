/* Code Ninjas problem solution of finding intersection among two arrays
Link of the problem - https://www.codingninjas.com/codestudio/problems/intersection-of-2-arrays_1082149

Solution - */ 

#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
   vector<int> ans ;
    int i =0;
    int j = 0 ;
    while(i<n&&j<m){
        if(arr1[i]==arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i]<arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return ans ; 
}


// here we use the two pointer approach between two arrays.
