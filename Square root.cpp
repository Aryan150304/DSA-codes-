/* Code Ninjas problem solution of finding Square Root of a number in o(log n ) complexity
Link of the problem - https://www.codingninjas.com/codestudio/problems/square-root-integral_893351
Solution - */ 

#include <bits/stdc++.h>  
long long int sqrtN(long long int N)
{
    long long int lb = 0 ;
    long long int ub = N ;
    long long int mid  = lb + (ub-lb)/2 ;
    long long int ans ;
    if(N<2){
        return N ; 
    }
    while(lb<=ub){
        mid  = lb + (ub-lb)/2 ;
        if(mid==N/mid){
            return mid;
        }
        else if (mid > N/mid){
            ub = mid -1 ;
        }
        else {
            ans = mid ;
            lb = mid + 1 ;
        }    
    }
    return ans ;
}

// To find the square root of a number in o(logn) we use the concept of binary search. The concept used in this question is an essential
// building block for medium and hard problems like book allocation problem
