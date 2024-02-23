class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int kami = 0;
        int balance = 0;
        int start = 0;

        for(int i=0;i<gas.size();i++){
            balance += gas[i]-cost[i];
            if(balance<0){
                kami+=balance;
                balance =0;
                start = i+1;
            }
        }
        int num = kami+ balance;
        if(num>=0){
            return start;
        }
        return -1;
    }
};
