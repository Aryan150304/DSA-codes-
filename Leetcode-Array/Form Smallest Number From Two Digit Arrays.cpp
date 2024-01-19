// leetcod elink - https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/description/ 
// Approach1 - more optimised 
/* find the sum of first and last element. If sum is larger than target then reduce the sum by moving to end--. if it is smaller than
the targget then increase sum by start++
    */
// TC - O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int k) {
        // sum find kr first aur last ka 
        // agar to vo last element se bda hai to ik element chota krdo
        // agar sum chota hai to ik element badha do 

        int start =0;
        vector<int> ans;
        int end = numbers.size()-1;
        while(end>start){
            int sum = numbers[start]+numbers[end];
            if(sum>k){
                end--;
            }
            else if(sum<k){
                start++;
            }
            else{
                ans.push_back(start+1);
                ans.push_back(end+1);
                break;
            }

        }
        return ans;     
    }
};


/* approach 2 - for every element we find the lower bound of target - i  ands if the idex of lower bound element and i become eual to k 
then ok other wise i++. Now it may happen that the lower bound become bigger than the total size of array so ignore such cases by using 
if statement
*/
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
