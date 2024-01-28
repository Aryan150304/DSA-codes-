class Solution {
public:
    int kthFactor(int n, int k) {
        // 2 to n-1 start dividing by n if modulus is 0 then push it and done 
        int counter =0;
        if(n>=1){
            counter++;
        }
        int elem =1;
        for(int i=2;i<=n;i++){
            int num = n%i;
            if(num==0){
                counter++;
                if(counter==k){
                    elem =i;
                    break;
                }
            }
        }
        if(counter<k){
            return -1;
        }
        return elem;
        
    }
};
