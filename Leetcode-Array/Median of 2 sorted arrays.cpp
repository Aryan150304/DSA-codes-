class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // first sort both the arrays 
        // then return the median of mid element
        vector<int> ans;
        int i = 0;
        int j =0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                ans.push_back(nums1[i++]);
            }
            else{
                ans.push_back(nums2[j++]);      
            }
        }
        while(i<nums1.size()){
            ans.push_back(nums1[i++]); 
        }
        while(j<nums2.size()){
            ans.push_back(nums2[j++]);
        }
        float num;
        if(ans.size()%2!=0){
            num = (float)ans[ans.size()/2];
        }
        else{
            num = ans[ans.size()/2]+ans[ans.size()/2-1];
            num =(float)num/2;
        }
        return num;
        
    }
};
