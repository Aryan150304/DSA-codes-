// leetcode link - https://leetcode.com/problems/set-mismatch/?envType=daily-question&envId=2024-01-22

// approach 1 to solve by calculating expected and actual sum 
// approach 2 can be to store the frequency 
// approach which is the most optimal and has o(1) space is finding XOR
class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int expectedSum = n*(n+1);
        expectedSum = expectedSum/2;

        int haveSum =0;
        for(auto it :arr){
            haveSum+=it;
        }
        int ans = expectedSum-haveSum;
        vector<int>answer;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]==arr[i+1]){
                answer.push_back(arr[i]);
                answer.push_back(arr[i]+ans);
                break;
            }

        }
        return answer;
        
    }
};
