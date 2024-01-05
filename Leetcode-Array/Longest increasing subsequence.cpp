// leetcode daily problem 
// Main indea is is to replace all giant values by minimal values that openss the possibility of having more values not changing the length of lis
// if the next element is smaller than the last element of the LIS but greater than the other elements of lis then replace the current element with the last element
//we need to add the element in the lis only if it increases the length of the list it doesn't matter how much or which one increases the most,
//it matters adding which one can lead to possibility of adding others so we need to add minimum of the current element and last element of lis

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
 
   int n = nums.size();
   vector<int> lis;
   lis.push_back(nums[0]);

   for(auto it :nums){
        int len = lis.size() ;
        int index = lower_bound(lis.begin(),lis.end(),it)-lis.begin();
        if(index==len){
            len++;
            lis.push_back(it);
        }
        else{
            lis[index]= it;
        }
   }
   return lis.size();
    }
};
