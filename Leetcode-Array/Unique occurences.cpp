// leetcode link - https://leetcode.com/problems/unique-number-of-occurrences/submissions/1148495951/?envType=daily-question&envId=2024-01-17

// approach 1 - store the frequency in an array or a hashmap . Iterate the array/hashmap to find if the occurences are same or not 
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        // 1 1 1 2 2 3 
        vector<int> count;
        int checker  = 0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]!=arr[i-1]){
                count.push_back(checker);
                checker=0;
            }
            else
            {
                checker++;
            }
            
        }
        count.push_back(checker);
        sort(count.begin(),count.end());
        for(int i=0;i<count.size()-1;i++){
            if(count[i]==count[i+1]){
                return false;
            }
        }
        return true;
}
};
