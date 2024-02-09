/*
this is an example of majority element question 
it has 2 steps 
1. check what is majority element
2. confirm if that majority element is majority in array. this is only required where there is no guarantee that majority element exists or not
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()<=1){
            return nums[0];
        }
        // we gonna use boyer more majority voting algo 
        int counter = 0;
        int ele;
        for(int i=0;i<nums.size();i++){
            if(counter==0){
                ele = nums[i];
                counter++;
            }
            else if(nums[i]==ele){
                counter++;
            }
            else{
                counter--;
            }
        }

        // in this question it is guarantee that there will be always majority element 
        // so counter will be always >0
        // if the majority element always exist then last step is nto required
        int precounter = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele){
                precounter++;
            }
        }
        if(precounter>nums.size()/2){
            return ele;
        }
        return -1;
    }
};
