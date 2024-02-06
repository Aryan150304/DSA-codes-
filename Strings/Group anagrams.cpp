class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> map;
        /* approach is to find sum for each*/
        for(int i=0;i<strs.size();i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            map[str].push_back(strs[i]);
        }
        for(auto it: map){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};
        
