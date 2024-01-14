// leetcode link -https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // if there is no 0 then return length -1 
        // if there are 0. then do what mind says 
        if(*max_element(nums.begin(),nums.end())==0){
            return 0;
        }
        vector<int> zero;
        int count =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero.push_back(count);
                count =0;
            }
            else{
                count++;
            }
           
        }
        if(count !=0){
            zero.push_back(count);
        }
      
        int maxi = 0;
        for(int i=0;i<zero.size()-1;i++){
            int elem = zero[i]+zero[i+1];
            if(maxi<elem){
                maxi = elem;
            }
        }
        if(maxi ==0){
            return nums.size()-1;
        }
        return maxi; 
    }
};
