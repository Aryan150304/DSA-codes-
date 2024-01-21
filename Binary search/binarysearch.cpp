// leetcode link - https://leetcode.com/problems/binary-search/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int start = 0;
        int end = nums.size() - 1;
        int mid = (start + end) / 2;
        while (start <= end) {
            if (nums[mid] == target) {
                ans = mid;
                break;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
            mid = (start + end) / 2;
        }
        return ans;
    }
};
