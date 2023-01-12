/* Code Ninjas problem solution of finding Peak Index in a Mountain Array
Link of the problem - https://leetcode.com/problems/peak-index-in-a-mountain-array/
Solution - */ 

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
    int lb = 0;
    int ub = arr.size() - 1;
    int ans = -1;
    int mid = lb + (ub - lb) / 2;
    int n = arr.size();
    while (n)
    {
        if (lb <= ub)
        {
            mid = (lb + ub) / 2;
            if (arr[mid] > arr[mid-1])
            {
                lb = mid;
            }
            else if(arr[mid]<arr[mid-1])
            {
                ub = mid;
            }
        }
        n--;
    }
    ans = mid ;
    return ans;
}

};

// here we use the concept of binary search to find the peak index in the array
