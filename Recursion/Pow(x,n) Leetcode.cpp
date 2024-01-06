// leetcode problem -https://leetcode.com/problems/powx-n/

class Solution {
public:
long double negative(double x, long int n){
    if(n==0){
            return 1;
        }
    else if (n==1){
            return x;
        }
        long double ans = negative(x,n/2);
        // storing in variable to reduce the tree
        // and reduce it iteratiosn
        if(n%2==0){
            return ans*ans;
        }
        else{
            return x * ans * ans;
        }
}
    double myPow(double x, long int n) {
        if(n<0){
            double power = negative(x,n*-1);
            return 1/power;
        }
        if(n==0){
            return 1;
        }
        else if (n==1){
            return x;
        }
        double ans = myPow(x,n/2);
        // storing in variable to reduce the tree
        // and reduce it iteratioss
        if(n%2==0){
            return ans*ans;
        }
        else{
            return x * ans * ans;
        }
    }
};
