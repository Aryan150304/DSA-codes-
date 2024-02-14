// better space optimised solution 

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       // much optimised version 
       vector<int> ans(nums.size());
       // we are using only array so it is better in space complexity 
       
       int i = 0;
       int j = 1;
       for(auto it : nums){
           if(it>0){
               ans[i] = it;
               i+=2;
           }
           else{
               ans[j] = it;
               j+=2;
           }
       }
       return ans;
    }
};
// less space optimised solution 
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // even length 
        // positive and negative integers 
        // order should be maintained
        vector<int> pos;
        vector<int> neg;
        for(auto it: nums){
            if(it>0){
                pos.push_back(it);
            }
            else{
                neg.push_back(it);
            }
        }
        int i = 0;
        int j= 0;
        int index = 0;
        while(i<pos.size()&&j<neg.size()){
            nums[index++]=pos[i++];
            nums[index++] = neg[j++];
        }
        return nums;

        
    }
};
