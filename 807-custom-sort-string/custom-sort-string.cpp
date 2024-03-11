class Solution {
public:
    string customSortString(string order, string s) {
        // order ko hashmap pe daalenge
        // jaise hi s me uska vo character millega

        unordered_map<char, int> map;
        for (auto it : s) {
            map[it]++;
        }
        string str;
        int index = 0;
        for (int i = 0; i < order.length(); i++) {
            char value = order[i];
            while(map[value] > 0) {
                map[value]--;
                str.push_back(value);
                index++;
            }
        }
        int i = index;
        for (auto it : map) {
            while(i <s.length()&&map[it.first]>0) {
                    char value = it.first;
                    str.push_back(value);
                    i++;
                    map[it.first]--;
            }
        }
        return str;
    }
};