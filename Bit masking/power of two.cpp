class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        double value =(double) log10(n)/(double)log10(2);
        if(value==floor(value)){
            return true;
        }
        return false;
    }
};
