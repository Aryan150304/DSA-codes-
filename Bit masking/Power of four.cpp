// leetcode problem 

// Approach 1 --> to use log and not to use recursion and check whether the number is complete divisble by 4. If number is in float then return false elese return true 

#include <cmath>

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }

        double element = log(n)/log(4);
        // now we have to check if it is an integer or not 
        if(floor(element)==element){
            return true;
        }
        else{
            return false;
        }
    }
};
