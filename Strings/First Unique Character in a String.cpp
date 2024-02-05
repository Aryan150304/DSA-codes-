class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>map;
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }
        int index = -1 ;
        for(int i=0;i<s.length();i++){
            if(map[s[i]]==1){
                index = i;
                return index;
            }
        }
        return index;
        
    }
};
