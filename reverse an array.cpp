/* This is a problem of code studio where we have tio reverse an array after a given index 
Problem level - easy 
Problem link - https://www.codingninjas.com/codestudio/problems/reverse-the-array_1262298
Solution 
*/
#include <bits/stdc++.h> 
void reverseArray(vector<int> &arr , int m)
{
	int s = m+ 1 ;
    int e = arr.size()-1;
    while(s<e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}
