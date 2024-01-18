// leetcod elink - https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/description/ 


class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i =0;
        int j =0;
        int mini =10;
        int count = 0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]>nums2[j]){
                j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                count++;
                if(mini>nums1[i]){
                    mini = nums1[i];
                }
                i++;
                j++;
            }
        }

        if(count>0){
            return mini;
        }
        int num1= nums1[0];
        int num2= nums2[0];

        mini = min(num1,num2);
        int maxi = max(num1,num2);
        return mini *10+maxi;
        
    }
};
