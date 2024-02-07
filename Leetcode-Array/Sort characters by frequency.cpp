class Solution {
public:
     static bool sortByValueDesc(const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    }
    string frequencySort(string s) {
        unordered_map<char, int> map;
        for (int i = 0; i < s.length(); i++) {
            map[s[i]]++;
        }
        string finalans = "";
         vector<pair<char, int>> vec(map.begin(), map.end());
      sort(vec.begin(), vec.end(), sortByValueDesc);
        for(auto it: vec){
            int k = it.second;
            while(k--){
                finalans+=it.first;
            }

        }

        return finalans;
    }
};
