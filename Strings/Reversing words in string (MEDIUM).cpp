// leetcode solution - https://leetcode.com/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    string reverseWords(string s) {
        vector<string> str;
        string ans;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                str.push_back(ans);
                ans ="";   
            }
            else{
                 ans.push_back(s[i]);
            }
           
        }
        if(ans!=" "){
  str.push_back(ans);
        }
        
          string finalans="";
        for(int i=str.size()-1;i>=0;i--){
            if(str[i]!=""){
                 finalans+=str[i];
                // we can onky add chars but we can concatenate these strings
                finalans.push_back(' ');
            }
        }
        finalans.pop_back();
          
        
        return finalans;
        // appraoch is to push all
    }
};
