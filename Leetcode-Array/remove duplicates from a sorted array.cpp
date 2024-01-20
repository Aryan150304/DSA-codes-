class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> aryan;
        for(int i=0;i<nums.size();i++){
            aryan.insert(nums[i]);
        }
        vector<int> finalans;
        for(auto it : aryan){
            finalans.push_back(it);
        }
        for(int k=0;k<finalans.size();k++){
            nums[k]=finalans[k];
        }
        return aryan.size();
        
    }
};
