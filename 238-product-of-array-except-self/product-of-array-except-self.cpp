class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // finding the left product and finding right prodiut
        int n = nums.size();
        int value = 1;
        vector<int> prefix(n);
        vector<int> suffix(n);
        for (int i = 0; i < n; i++) {
            prefix[i] = value;
            value = value * nums[i];
        }
        value = 1;
        //  1 1 2 6
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = value;
            value = value * nums[i];
        }
        for(int i=0;i<n;i++){
            nums[i]= prefix[i]*suffix[i];
        }
        return nums;
    }
};