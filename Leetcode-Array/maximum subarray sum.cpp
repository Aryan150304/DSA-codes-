class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadanen algorithm 
        int maxi = nums[0];
        int sum = 0;
        for(auto it: nums){
            sum += it;
            maxi = max(sum,maxi);
            if(sum<0){
                sum = 0;
            }
        }  
        return maxi;
    }
};
// it uses kadanen's algorithm 
