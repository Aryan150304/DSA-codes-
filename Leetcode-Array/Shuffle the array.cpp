// leetcode link - https://leetcode.com/problems/shuffle-the-array/submissions/1146200586/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> firstPart;
        vector<int> secondPart;
        for(int i=0;i<n;i++){
            firstPart.push_back(nums[i]);
        }
        for(int i=n;i<nums.size();i++){
            secondPart.push_back(nums[i]);
        }

        int i =0;
        int j =0;
        int index = 0;
        while(i<firstPart.size()||j<secondPart.size()){
            nums[index++] = firstPart[i++];
            nums[index++] = secondPart[j++];
        }
        return nums;
    }
};

// approach 2 
 vector<int> ans;
       for(int i=0;i<n;i++){
           ans.push_back(nums[i]);
           ans.push_back(nums[n+i]);
       }
       return ans;
