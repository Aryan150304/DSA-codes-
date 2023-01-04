/* Code Ninjas problem solution of finding unique element in an array
Link of the problem - https://www.codingninjas.com/codestudio/problems/find-unique_625159


Solution - /* 

int findUnique(int *arr, int n)
{
    int ans = 0 ;
    for(int i = 0;i<n;i++){
        ans = ans ^ arr[i];
    }
    return ans; 
}

// here we use the concept of bit manipulation . Using XOR operator we find the unique element in an array in O(n) time complexity
