/* Code Ninjas problem solution of finding duplicate element in an array
Link of the problem - https://www.codingninjas.com/codestudio/problem-details/duplicate-in-array_893397


Solution - /* 
Approach 1  - 
int findDuplicate(vector<int> &arr) 
{
    //second approach
    int ans = 0;
    int natans = 0;
     for(int i=0;i<arr.size();i++){
        natans = natans ^ i;
     }
     for(int i=0;i<arr.size();i++){
        ans = ans ^ arr[i];
     }
    return natans^ans;
    
    
}

Approach 2  - 
int findDuplicate(vector<int> &arr) 
{
  //array = sum of N natural numbers + one repeated element 
    int naturalsum = 0 ;
    int arraySum  = 0;
    for(int i=0;i<arr.size();i++){
         naturalsum +=i;
   }
    // sum of array elements 
    for(int i=0;i<arr.size();i++){
       arraySum +=arr[i];
    }
   return arraySum-naturalsum;  
}  

// in approach 1 we use the concept of bit manipulation . Using XOR operator we find the duplicate element in an array in O(n) time complexity
// in approach 2 we use an appraoch of sum of natural numbers and subtract the sum of arrays and natural numbers sum
