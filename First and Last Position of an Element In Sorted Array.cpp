/* Code Ninjas problem solution of finding unique element in an array
Link of the problem - https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549


Solution - /* 
#include <bits/stdc++.h>
int firstOccur(vector<int>&arr, int n, int elem)
{
    int lb = 0;
    int ub = n - 1;
    int ans = -1;
    int mid = lb + (ub - lb) / 2;
    while (n)
    {
        if (lb <= ub)
        {
            mid = (lb + ub
                  ) / 2;
            if (arr[mid] == elem)
            {
                ans = mid;
                ub = mid - 1;
            }
            else if (arr[mid] > elem)
            {
                ub = mid - 1;
            }
            else
            {
                lb = mid + 1;
            }
        }
        n--;
    }
    return ans;
}


int lastOccur(vector<int>&arr, int n, int elem)
{
    int lb = 0;
    int ub = n - 1;
    int ans = -1;
    int mid = lb + (ub - lb) / 2;
    while (n)
    {
        if (lb <= ub)
        {
            mid = (lb + ub) / 2;
            if (arr[mid] == elem)
            {
                ans = mid;
                lb = mid + 1;
            }
            else if (arr[mid] > elem)
            {
                ub = mid - 1;
            }
            else
            {
                lb = mid + 1;
            }
        }
        n--;
    }
    return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int , int> p;
    p.first = firstOccur(arr,n,k);
    p.second = lastOccur(arr,n,k);
    return p;
}
// here we use the concept of Binary search to find the last and first occurence of any element 
