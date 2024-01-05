// leetcode daily problem - https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/submissions/1136504478/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size()==1||nums.size()==0){
            return -1;
        }
        // int maxi = *max_element(nums.begin(),nums.end());
        // store the number in a hashmap 
        unordered_map<int,int> map;
         for(auto am: nums){
             map[am]++;
         }
         int counter = 0;
         for(auto ap: map){
             int am = ap.second;
             if(am==0){
                 continue;
             }
             else if(am==1){
                 return -1;
             }
             else if (am>=3){
                 int rem = am % 3;
                 int div = am / 3;
                 if(rem==0){
                     counter += div;
                 }
                 else if (rem==2){
                     counter+=div;
                     counter++;
                 }
                 else if (rem==1){
                     div--;
                     counter+=div;
                     int newnum = am - (div*3);
                     newnum = newnum/ 2;
                     counter+=newnum;
                 }
             }
             else{
                 counter++;
             }
         }
         return counter;

    }
};
