/* This is a problem of leetcode where we have to merge 2 sorted arrays such that the resulting array is array 1 and is sorted 
Problem link - https://leetcode.com/problems/merge-sorted-array/description/
Solution */

// OPTIMAL SOLUTION 1(runtime 0ms and beats 100% solutions)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      for(int i=0;i<n;i++){
          nums1[i+m]=nums2[i];
      }
      sort(nums1.begin(),nums1.end());
    }
};

//OPTIMAL SOLUTION (3ms runtime and beats 74% solution)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        vector<int> ans ;
        int j = 0;
        while(i<(m+n)&& ans.size()<m+n){
            if(i>=m&&j<n){
                ans.push_back(nums2[j++]);
            }
            else if(j>=n){
                ans.push_back(nums1[i++]);
            }
           else if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i++]);
            }
            else if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i++]);
                ans.push_back(nums2[j++]);

            }
            else if(nums1[i]>nums2[j]){
                ans.push_back(nums2[j++]);
             }
            
    }
    if(ans.size()>0){
    nums1 = ans ;
    }
    else if(m==0){
      nums1=nums2;
     }
    }
};
