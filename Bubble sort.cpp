
/* OPTIMAL SOLUTION FOR IMPLEMENTING BUBBLE SORT WITH TIME COMPLEXITY OF BEST CASE AS O(n) */ 
// solution
#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{ 
    // much optimal solution 
    int k = n - 1;
    bool swapped = false ;
    int j = 1 ;
    while (k)
    {
        for (int i = 0; i < n - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true ;
            }
        }
        if(swapped==false)
            break;
        k--;
        j++;
    }
}
// Here the time complexity of best case is O(n) and worst case as o(n*n)
