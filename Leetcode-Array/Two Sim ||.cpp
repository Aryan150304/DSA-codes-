// leetcode array - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/1150465300/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // find two integers that add uptto specific point 
        // tell the position not the index
        vector<int> ans;
        // manlo maine search space reduce krdia
        for(int i =0;i<numbers.size()-1;i++){
            int finalnum = target-numbers[i];
            int secondnum = lower_bound(numbers.begin()+i+1,numbers.end(),finalnum) - numbers.begin();
            if(secondnum<numbers.size()){
             if(numbers[i]+numbers[secondnum]==target){
                ans.push_back(i+1);
                ans.push_back(secondnum+1);
                cout<<secondnum;
                break;
            }
            }
        }
        return ans;
    }
};
