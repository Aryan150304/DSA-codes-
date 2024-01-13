// link - https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/?envType=daily-question&envId=2024-01-13
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> first(26,0);
        vector<int> second(26,0);
        for(int i=0;i<s.length();i++){
            int elem = s[i] -'a';
            first[elem]++;
        }

         for(int i=0;i<t.length();i++){
            int elem = t[i] -'a';
            second[elem]++;
        }
        int count =0;

        for(int i=0;i<26;i++){
            if((first[i]>second[i])){
                count+=(first[i]-second[i]);
                cout<<count;
            }
        }
        return count;
        
    }
};
