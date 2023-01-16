/* This is a leetode problem where all the zeroes have to placed in end of the array such that the order of the array doesn't change 
Problem link  - https://leetcode.com/problems/move-zeroes/description/
SOLUTION - */
class Solution {
public:
    void moveZeroes(vector<int>& arr) {
    int i = 0;
    int j =0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    }
};
