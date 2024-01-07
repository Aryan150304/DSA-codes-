// leetcode question - https://leetcode.com/problems/subsets/description/

class Solution {
public:
void Solutions(vector<int>&nums,int index, vector<int>output, vector<vector<int>>&ans){
    if(index>=nums.size()){
        ans.push_back(output);
        return;
    }
    Solutions(nums,index+1,output,ans);

    int element = nums[index];
    output.push_back(element);
    Solutions(nums,index+1,output,ans);
}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>output;
        int index = 0;
        Solutions(nums, index , output, ans);
        return ans;
    }
};
