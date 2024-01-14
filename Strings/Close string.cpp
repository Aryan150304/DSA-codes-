// leetcode question link - https://leetcode.com/problems/determine-if-two-strings-are-close/submissions/1145850905/?envType=daily-question&envId=2024-01-14

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // both words length should be same thenonly we can attain the answer
        if(word1.length()!=word2.length()){
            return false;
        }
        vector<int> first(26,0);
        vector<int> second(26,0);
        for(int i=0;i<word1.length();i++){
            int elem = word1[i] -'a';
            first[elem]++;
        }
        cout<<endl;
        for(int i=0;i<word2.length();i++){
            int elem = word2[i] -'a';
            second[elem]++;
        }

        for(int i =0; i<26; i++){
            if(first[i]==0&&second[i]>0||first[i]>0&&second[i]==0){
                return false;
            }
        }
        cout<<endl;
        sort(first.begin(),first.end());
        sort(second.begin(),second.end());

        int i =25;
        while(i>=0){
            if(first[i]!=second[i]){
                return false;
            }
            i--;
        }
        return true;
        
    }
};
