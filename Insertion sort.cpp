/* Codes for Insertion sort
Problem statement - https://www.codingninjas.com/codestudio/problems/insertion-sort_3155179 */

// Solution - 1 
#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
 for(int i=0;i<n-1;i++){
     if(arr[i+1]<arr[i]){
         swap(arr[i+1],arr[i]);
         for(int j=i;j>0;j--){
             if(arr[j]<arr[j-1]){
                 swap(arr[j],arr[j-1]);
             }
         }
     }
 }
}

//OPTIMAL SOLUTION 
#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
   // Write your code here.
    int result;
   int i = 1; 
   while (i<n)
   {
        result = arr[i];
       int j = i-1;
       while (j>=0)
       {
           if (arr[j]> result)
           {
               arr[j+1] = arr[j];
           }
           else 
           {
               break;
           }

           j--;
       }
       arr[j+1]=result;
       i++;
   }
}

