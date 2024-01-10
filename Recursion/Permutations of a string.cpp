// leetcode solution - https://leetcode.com/problems/permutations/submissions/1142652153/
class Solution {
public:
void solve(vector<int>& nums, int index , string output , vector<vector<int>>&ans){
    if(index>=nums.size()){
        ans.push_back(nums);
        return ;
    }
    for(int i=index;i<nums.size();i++){
        swap(nums[index],nums[i]);
         solve(nums, index+1, output, ans);
        swap(nums[index],nums[i]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        int index = 0;
        string output ;
        vector<vector<int>>ans;
        solve(nums, index, output, ans);
        return ans;
    }
};
